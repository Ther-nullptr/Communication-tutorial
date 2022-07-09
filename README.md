# 例程使用方法

## `gRPC/cpp`

### Linux

```bash
$ cd gRPC/cpp
$ cmake .
$ make
$ ./server
$ ./client # 在两个终端上分别运行
```

## `gRPC/csharp`

### Linux

```bash
$ cd gRPC/csharp
$ dotnet build
$ cd gRPC
$ ./runServer.sh
$ ./runClient.sh # 在两个终端上分别运行
# 根据生成方式的不同，可能需要修改上述两个bash文件的路径
```

### windows

直接点击`CStest.sln`即可。

## `Protobuf/cpp`

### Linux

```bash
$ cd Protobuf/cpp
$ cmake .
$ make
$ ./protobuf_test 
```

## `Protobuf/csharp`

### Linux

```bash
$ cd Protobuf/csharp/Test
$ dotnet run
```

### windows

直接点击`ProtobufTest.sln`即可。