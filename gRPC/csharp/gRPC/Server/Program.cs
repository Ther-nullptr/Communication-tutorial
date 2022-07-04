using Grpc.Core;
using Hello;

namespace GrpcTest.Server
{
    // 默认情况下，生成的 CalculatorBase 不执行任何操作。它的虚拟法会将 UNIMPLEMENTED 错误返回到调用它的任何客户端，为了使服务有用，应用必须创建 CalculatorBase 的具体实现
    // 在该继承类中，我们将定义Server端实现方法的内部处理逻辑
    class CalculatorImpl : Calculator.CalculatorBase
    {
        public override Task<Result> UnaryCall(Operand operand, ServerCallContext context)
        {
            var res = new Result();
            switch (operand.Opr)
            {
                case Operator.Add:
                    res.Val = operand.Op1 + operand.Op2;
                    break;
                case Operator.Sub:
                    res.Val = operand.Op1 - operand.Op2;
                    break;
                case Operator.Mul:
                    res.Val = operand.Op1 * operand.Op2;
                    break;
                default:
                    break;
            }
            return Task.FromResult(res);
        }

        public override async Task StreamingFromServer(Operand operand, IServerStreamWriter<Result> result_stream, ServerCallContext context)
        {
            var res = new Result();
            switch (operand.Opr)
            {
                case Operator.Add:
                    res.Val = operand.Op1 + operand.Op2;
                    break;
                case Operator.Sub:
                    res.Val = operand.Op1 - operand.Op2;
                    break;
                case Operator.Mul:
                    res.Val = operand.Op1 * operand.Op2;
                    break;
                default:
                    break;
            }
            for (var i = 0; i < 3; i++)
            {
                await result_stream.WriteAsync(res);
            }
        }

        public override async Task<Result> StreamingFromClient(IAsyncStreamReader<Operand> operand_stream, ServerCallContext context)
        {
            var res = new Result();
            while (await operand_stream.MoveNext())
            {
                var operand = operand_stream.Current;
                switch (operand.Opr)
                {
                    case Operator.Add:
                        res.Val += operand.Op1 + operand.Op2;
                        break;
                    case Operator.Sub:
                        res.Val += operand.Op1 - operand.Op2;
                        break;
                    case Operator.Mul:
                        res.Val += operand.Op1 * operand.Op2;
                        break;
                    default:
                        break;
                }
            }
            return res;
        }

        public override async Task StreamingBothWays(IAsyncStreamReader<Operand> operand_stream, IServerStreamWriter<Result> result_stream, ServerCallContext context)
        {
            while (await operand_stream.MoveNext())
            {
                Operand operand = operand_stream.Current;
                var res = new Result();
                switch (operand.Opr)
                {
                    case Operator.Add:
                        res.Val = operand.Op1 + operand.Op2;
                        break;
                    case Operator.Sub:
                        res.Val = operand.Op1 - operand.Op2;
                        break;
                    case Operator.Mul:
                        res.Val = operand.Op1 * operand.Op2;
                        break;
                    default:
                        break;
                }
                await result_stream.WriteAsync(res);
            }
        }
    }

    static class Program
    {
        public static void Main()
        {
            try
            {
                Grpc.Core.Server server = new Grpc.Core.Server(new[] { new ChannelOption(ChannelOptions.SoReuseport, 0) })
                {
                    Services = { Calculator.BindService(new CalculatorImpl()) },
                    Ports = { new ServerPort("127.0.0.1", 8887, ServerCredentials.Insecure) }
                }; // 建立监听特定IP地址和端口Server的模板代码
                server.Start();
                Console.WriteLine("Server begins to listen!");
                Console.WriteLine("Press any key to stop the server...");
                Console.ReadKey();
                Console.WriteLine("Server end!");
                server.ShutdownAsync().Wait();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }
    }
}
