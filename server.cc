#define WIN32_LEAN_AND_MEAN /* required by xmlrpc-c/server_abyss.hpp */
#include <cassert>
#include <stdexcept>
#include <iostream>
#ifdef _WIN32
# include <windows.h>
#else
# include <unistd.h>
#endif
using namespace std;
#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>
#ifdef _WIN32
#define SLEEP(seconds) SleepEx(seconds * 1000);
#else
#define SLEEP(seconds) sleep(seconds);
#endif

class myMethod : public xmlrpc_c::method {
  public:
    myMethod() {
    // signature and help strings are documentation -- the client
    // can query this information with a system.methodSignature and
    // system.methodHelp RPC.
    this->_signature = "i:ii";
    // method's result and two arguments are integers
    this->_help = "This method adds two integers together";
  }

  void execute(xmlrpc_c::paramList const& paramList,
               xmlrpc_c::value * const retvalP) {
    int const num1(paramList.getInt(0));
    int const num2(paramList.getInt(1));
    paramList.verifyEnd(2);
    *retvalP = xmlrpc_c::value_int(num1 + num2);
  }

};


int main(int const,const char ** const) {
  try {
    xmlrpc_c::registry myRegistry;
    xmlrpc_c::methodPtr const myMethodP(new myMethod);
    myRegistry.addMethod("sample.sum", myMethodP);
    xmlrpc_c::serverAbyss myAbyssServer(
      xmlrpc_c::serverAbyss::constrOpt().registryP(&myRegistry).portNumber(53000));
    myAbyssServer.run();

    // xmlrpc_c::serverAbyss.run() never returns
    assert(false);

  } catch (exception const& e) {
    cerr << "Something failed. " << e.what() << endl;
  }
  return 0;
} 

