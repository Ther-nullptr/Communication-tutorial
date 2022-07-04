#include "proto/MessageToClient.grpc.pb.h"
#include "proto/MessageToClient.pb.h"
#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <utility>

int main()
{
    auto client_stub = hello::RemoteAdd::NewStub(grpc::CreateChannel(SERVER_ADDR, grpc::InsecureChannelCredentials()));
    {
        grpc::ClientContext client_context;
        hello::NumberPair number;
        number.set_val(888);
        number.set_times(10);
        auto reader = client_stub->GetNumberSequence(&client_context, number);
        hello::Number result;
        std::cout << "Get Result: ";
        while (reader->Read(&result)) {
            std::cout << result.val() << ", " << std::flush;
        }
        endl(std::cout);
    }

    std::pair<int, int> xys[] = { { 5, 15 }, { 1, 1 }, { 0, 0 } };

    for (auto xy : xys) {
        grpc::ClientContext client_context;
        hello::Adder adder;
        hello::Result res;
        adder.set_x(xy.first);
        adder.set_y(xy.second);
        auto status = client_stub->GetResult(&client_context, adder, &res);
        if (status.ok()) {
            std::cout << "Got result: " << res.res() << std::endl;
        } else {
            std::cout << "Server cancelled! Result: " << res.res() << std::endl;
        }
    }
    
    return 0;
}
