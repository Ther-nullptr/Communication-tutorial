#include "proto/MessageToClient.pb.h"
#include "proto/MessageToClient.grpc.pb.h"
#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>

#include <iostream>
#include <thread>
#include <semaphore.h>
#include "pch.h"

class RemoteAddImpl final : public hello::RemoteAdd::Service
{
public:
    RemoteAddImpl(sem_t& end_sem) : m_end_sem(end_sem) {}

    grpc::Status GetResult(grpc::ServerContext* context, const hello::Adder* adder, hello::Result* result) override
    {
        int x = adder->x(), y = adder->y();
        if (x == 0 && y == 0) {
            int ret = sem_post(&m_end_sem);
        }

        for (int i = 0; i < 2; ++i) {
            std::cout << "Wait for " << i << std::endl;
            ::sleep(1);
        }
        result->set_res(x + y);

        if (x == 1 && y == 1) return grpc::Status::CANCELLED;
        return grpc::Status::OK;
    }

    grpc::Status GetNumberSequence(grpc::ServerContext* context, const hello::NumberPair* request, grpc::ServerWriter<hello::Number>* writer) override {
        int val = request->val(), times = request->times();
        std::cout << "Receive seq: " << val << ' ' << times << std::endl;
        for (int i = 0; i < times; ++i) {
            std::cout << "Wait for " << i << std::endl;
            ::usleep(20000);

            hello::Number number;
            number.set_val(val);
            writer->Write(number);
        }
        return grpc::Status::OK;
    }

private:
    sem_t& m_end_sem;
};

int main() {
    grpc::ServerBuilder server_builder;
    server_builder.AddListeningPort(SERVER_ADDR, grpc::InsecureServerCredentials());

    sem_t end_sem;
    sem_init(&end_sem, 0, 0);

    RemoteAddImpl remote_add(end_sem);
    server_builder.RegisterService(&remote_add);
    server_builder.SetOption(grpc::MakeChannelArgumentOption(GRPC_ARG_ALLOW_REUSEPORT, 0));

    auto server = server_builder.BuildAndStart();
    if (server == nullptr) {
        std::cout << "Start server failed!" << std::endl;
        return 1;
    }

    std::cout << "Server begins to listen" << std::endl;
    std::thread thr (
        [&server] {
            server->Wait();
        }
    );

    sem_wait(&end_sem);
    server->Shutdown();

    thr.join();
    sem_destroy(&end_sem);
    return 0;
}
