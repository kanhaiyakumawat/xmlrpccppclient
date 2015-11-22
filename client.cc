#include <iostream>
#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/client_simple.hpp>
using namespace std;

int main(int argc, char **argv) {

    string const serverUrl("http://localhost:8080/RPC2");
    string const methodName("MathComputation.ComputePi");

    xmlrpc_c::clientSimple myClient;
    xmlrpc_c::value result;
        
    myClient.call(serverUrl, methodName, "i", &result, 0);

    double const sum((xmlrpc_c::value_double(result)));
        // Assume the method returned an integer; throws error if not

    cout << "Result of RPC (sum of 5 and 7): " << sum << endl;

    return 0;
}
