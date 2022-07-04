using Grpc.Core;
using Hello;

namespace GrpcTest.Client
{
    public static class Program
    {
        public static async Task Main()
        {
            Channel channel = new Channel("127.0.0.1:8887", ChannelCredentials.Insecure);
            var client = new Calculator.CalculatorClient(channel); // 建立一个连接到特定host的client

            Tuple<int, int, Operator> tup0 = new(1, 1, Operator.Add);
            Operand operand0 = new Operand();
            operand0.Op1 = tup0.Item1;
            operand0.Op2 = tup0.Item2;
            operand0.Opr = tup0.Item3;

            // case 1: unary call（单一RPC）
            Console.WriteLine("case 1:");
            var unaryCall = client.UnaryCall(operand0); // 
            var unaryCallVal = unaryCall.Val;
            Console.WriteLine(unaryCallVal);

            // case 2: streaming from server（服务器流式RPC）
            Console.WriteLine("case 2:");
            var streamingFromServer = client.StreamingFromServer(operand0);
            while(await streamingFromServer.ResponseStream.MoveNext())
            {
                var streamingFromServerVal = streamingFromServer.ResponseStream.Current.Val;
                Console.WriteLine(streamingFromServerVal);
            }

            // case 3: streaming from client（客户端流式RPC）
            Console.WriteLine("case 3:");
            var streamingFromClient = client.StreamingFromClient();
            Tuple<int, int, Operator>[] tups = { new(1, 1, Operator.Add), new(5, 6, Operator.Mul), new(3, 4, Operator.Sub), new(0, 0, Operator.NoneOp) };
            foreach (var tup in tups)
            {
                Operand operand = new Operand();
                operand.Op1 = tup.Item1;
                operand.Op2 = tup.Item2;
                operand.Opr = tup.Item3;
                await streamingFromClient.RequestStream.WriteAsync(operand);
            }
            await streamingFromClient.RequestStream.CompleteAsync();
            var streamingFromClientVal = streamingFromClient.ResponseAsync.Result.Val;
            Console.WriteLine(streamingFromClientVal);

            // case 4: streaming both ways（双向流RPC）
            Console.WriteLine("case 4:");
            var streamingBothWays = client.StreamingBothWays();       
            foreach (var tup in tups)
            {
                Operand operand = new Operand();
                operand.Op1 = tup.Item1;
                operand.Op2 = tup.Item2;
                operand.Opr = tup.Item3;
                _ = streamingBothWays.RequestStream.WriteAsync(operand);
                if (!await streamingBothWays.ResponseStream.MoveNext())
                {
                    break;
                }
                var streamingBothWaysVal = streamingBothWays.ResponseStream.Current.Val;
                Console.WriteLine(streamingBothWaysVal);
            }
        }
    }
}
