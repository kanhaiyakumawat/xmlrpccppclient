# xmlrpccppclient
This is just a sample project for connecting a C++ XML-RPC client to Java RPC Server. Java RPC server is been put in different repository [here](https://github.com/kanhaiyakumawat/KanhaiyaJavaRPC)

## Dependencies
This sample project is using libxmlrpc++ library. I haven't put a .gitignore file intentionaly. Here are the steps to be followed:

1. Download the libxmlrpc++ and keep unzipped in your project folder
1. Switch to the library folder and run `./configure`
1. Run the `make` command
1. Run the command 'make install`
1. I havae also kept the Make File in the project that was also available online.
1. Create your client file as shown in the client.cc file
1. build your client using `g++ -o client client.cc -l xmlrpc++ -l xmlrpc_client++`
1. Run the client using `./client`

Java RPC server steps are mentioned in another repository
