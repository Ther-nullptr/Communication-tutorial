// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: MessageToClient.proto
#ifndef GRPC_MessageToClient_2eproto__INCLUDED
#define GRPC_MessageToClient_2eproto__INCLUDED

#include "MessageToClient.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace hello {

class RemoteAdd final {
 public:
  static constexpr char const* service_full_name() {
    return "hello.RemoteAdd";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status GetResult(::grpc::ClientContext* context, const ::hello::Adder& request, ::hello::Result* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::hello::Result>> AsyncGetResult(::grpc::ClientContext* context, const ::hello::Adder& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::hello::Result>>(AsyncGetResultRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::hello::Result>> PrepareAsyncGetResult(::grpc::ClientContext* context, const ::hello::Adder& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::hello::Result>>(PrepareAsyncGetResultRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderInterface< ::hello::Number>> GetNumberSequence(::grpc::ClientContext* context, const ::hello::NumberPair& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::hello::Number>>(GetNumberSequenceRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::hello::Number>> AsyncGetNumberSequence(::grpc::ClientContext* context, const ::hello::NumberPair& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::hello::Number>>(AsyncGetNumberSequenceRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::hello::Number>> PrepareAsyncGetNumberSequence(::grpc::ClientContext* context, const ::hello::NumberPair& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::hello::Number>>(PrepareAsyncGetNumberSequenceRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void GetResult(::grpc::ClientContext* context, const ::hello::Adder* request, ::hello::Result* response, std::function<void(::grpc::Status)>) = 0;
      virtual void GetResult(::grpc::ClientContext* context, const ::hello::Adder* request, ::hello::Result* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void GetNumberSequence(::grpc::ClientContext* context, const ::hello::NumberPair* request, ::grpc::ClientReadReactor< ::hello::Number>* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::hello::Result>* AsyncGetResultRaw(::grpc::ClientContext* context, const ::hello::Adder& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::hello::Result>* PrepareAsyncGetResultRaw(::grpc::ClientContext* context, const ::hello::Adder& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderInterface< ::hello::Number>* GetNumberSequenceRaw(::grpc::ClientContext* context, const ::hello::NumberPair& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::hello::Number>* AsyncGetNumberSequenceRaw(::grpc::ClientContext* context, const ::hello::NumberPair& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::hello::Number>* PrepareAsyncGetNumberSequenceRaw(::grpc::ClientContext* context, const ::hello::NumberPair& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status GetResult(::grpc::ClientContext* context, const ::hello::Adder& request, ::hello::Result* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::hello::Result>> AsyncGetResult(::grpc::ClientContext* context, const ::hello::Adder& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::hello::Result>>(AsyncGetResultRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::hello::Result>> PrepareAsyncGetResult(::grpc::ClientContext* context, const ::hello::Adder& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::hello::Result>>(PrepareAsyncGetResultRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReader< ::hello::Number>> GetNumberSequence(::grpc::ClientContext* context, const ::hello::NumberPair& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::hello::Number>>(GetNumberSequenceRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::hello::Number>> AsyncGetNumberSequence(::grpc::ClientContext* context, const ::hello::NumberPair& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::hello::Number>>(AsyncGetNumberSequenceRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::hello::Number>> PrepareAsyncGetNumberSequence(::grpc::ClientContext* context, const ::hello::NumberPair& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::hello::Number>>(PrepareAsyncGetNumberSequenceRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void GetResult(::grpc::ClientContext* context, const ::hello::Adder* request, ::hello::Result* response, std::function<void(::grpc::Status)>) override;
      void GetResult(::grpc::ClientContext* context, const ::hello::Adder* request, ::hello::Result* response, ::grpc::ClientUnaryReactor* reactor) override;
      void GetNumberSequence(::grpc::ClientContext* context, const ::hello::NumberPair* request, ::grpc::ClientReadReactor< ::hello::Number>* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::hello::Result>* AsyncGetResultRaw(::grpc::ClientContext* context, const ::hello::Adder& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::hello::Result>* PrepareAsyncGetResultRaw(::grpc::ClientContext* context, const ::hello::Adder& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReader< ::hello::Number>* GetNumberSequenceRaw(::grpc::ClientContext* context, const ::hello::NumberPair& request) override;
    ::grpc::ClientAsyncReader< ::hello::Number>* AsyncGetNumberSequenceRaw(::grpc::ClientContext* context, const ::hello::NumberPair& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::hello::Number>* PrepareAsyncGetNumberSequenceRaw(::grpc::ClientContext* context, const ::hello::NumberPair& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_GetResult_;
    const ::grpc::internal::RpcMethod rpcmethod_GetNumberSequence_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status GetResult(::grpc::ServerContext* context, const ::hello::Adder* request, ::hello::Result* response);
    virtual ::grpc::Status GetNumberSequence(::grpc::ServerContext* context, const ::hello::NumberPair* request, ::grpc::ServerWriter< ::hello::Number>* writer);
  };
  template <class BaseClass>
  class WithAsyncMethod_GetResult : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GetResult() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_GetResult() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetResult(::grpc::ServerContext* /*context*/, const ::hello::Adder* /*request*/, ::hello::Result* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetResult(::grpc::ServerContext* context, ::hello::Adder* request, ::grpc::ServerAsyncResponseWriter< ::hello::Result>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetNumberSequence : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GetNumberSequence() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_GetNumberSequence() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetNumberSequence(::grpc::ServerContext* /*context*/, const ::hello::NumberPair* /*request*/, ::grpc::ServerWriter< ::hello::Number>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetNumberSequence(::grpc::ServerContext* context, ::hello::NumberPair* request, ::grpc::ServerAsyncWriter< ::hello::Number>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_GetResult<WithAsyncMethod_GetNumberSequence<Service > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_GetResult : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_GetResult() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::hello::Adder, ::hello::Result>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::hello::Adder* request, ::hello::Result* response) { return this->GetResult(context, request, response); }));}
    void SetMessageAllocatorFor_GetResult(
        ::grpc::MessageAllocator< ::hello::Adder, ::hello::Result>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::hello::Adder, ::hello::Result>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_GetResult() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetResult(::grpc::ServerContext* /*context*/, const ::hello::Adder* /*request*/, ::hello::Result* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GetResult(
      ::grpc::CallbackServerContext* /*context*/, const ::hello::Adder* /*request*/, ::hello::Result* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_GetNumberSequence : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_GetNumberSequence() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::hello::NumberPair, ::hello::Number>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::hello::NumberPair* request) { return this->GetNumberSequence(context, request); }));
    }
    ~WithCallbackMethod_GetNumberSequence() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetNumberSequence(::grpc::ServerContext* /*context*/, const ::hello::NumberPair* /*request*/, ::grpc::ServerWriter< ::hello::Number>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::hello::Number>* GetNumberSequence(
      ::grpc::CallbackServerContext* /*context*/, const ::hello::NumberPair* /*request*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_GetResult<WithCallbackMethod_GetNumberSequence<Service > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_GetResult : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GetResult() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_GetResult() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetResult(::grpc::ServerContext* /*context*/, const ::hello::Adder* /*request*/, ::hello::Result* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetNumberSequence : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GetNumberSequence() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_GetNumberSequence() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetNumberSequence(::grpc::ServerContext* /*context*/, const ::hello::NumberPair* /*request*/, ::grpc::ServerWriter< ::hello::Number>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_GetResult : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GetResult() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_GetResult() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetResult(::grpc::ServerContext* /*context*/, const ::hello::Adder* /*request*/, ::hello::Result* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetResult(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_GetNumberSequence : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GetNumberSequence() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_GetNumberSequence() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetNumberSequence(::grpc::ServerContext* /*context*/, const ::hello::NumberPair* /*request*/, ::grpc::ServerWriter< ::hello::Number>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetNumberSequence(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_GetResult : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_GetResult() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->GetResult(context, request, response); }));
    }
    ~WithRawCallbackMethod_GetResult() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetResult(::grpc::ServerContext* /*context*/, const ::hello::Adder* /*request*/, ::hello::Result* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GetResult(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_GetNumberSequence : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_GetNumberSequence() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const::grpc::ByteBuffer* request) { return this->GetNumberSequence(context, request); }));
    }
    ~WithRawCallbackMethod_GetNumberSequence() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetNumberSequence(::grpc::ServerContext* /*context*/, const ::hello::NumberPair* /*request*/, ::grpc::ServerWriter< ::hello::Number>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::grpc::ByteBuffer>* GetNumberSequence(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_GetResult : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_GetResult() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::hello::Adder, ::hello::Result>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::hello::Adder, ::hello::Result>* streamer) {
                       return this->StreamedGetResult(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_GetResult() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetResult(::grpc::ServerContext* /*context*/, const ::hello::Adder* /*request*/, ::hello::Result* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGetResult(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::hello::Adder,::hello::Result>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_GetResult<Service > StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_GetNumberSequence : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithSplitStreamingMethod_GetNumberSequence() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::SplitServerStreamingHandler<
          ::hello::NumberPair, ::hello::Number>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerSplitStreamer<
                     ::hello::NumberPair, ::hello::Number>* streamer) {
                       return this->StreamedGetNumberSequence(context,
                         streamer);
                  }));
    }
    ~WithSplitStreamingMethod_GetNumberSequence() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetNumberSequence(::grpc::ServerContext* /*context*/, const ::hello::NumberPair* /*request*/, ::grpc::ServerWriter< ::hello::Number>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedGetNumberSequence(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::hello::NumberPair,::hello::Number>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_GetNumberSequence<Service > SplitStreamedService;
  typedef WithStreamedUnaryMethod_GetResult<WithSplitStreamingMethod_GetNumberSequence<Service > > StreamedService;
};

}  // namespace hello


#endif  // GRPC_MessageToClient_2eproto__INCLUDED