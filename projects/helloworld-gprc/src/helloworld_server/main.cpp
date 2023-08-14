#include <grpcpp/grpcpp.h>
#include "helloworld_server.h"

int main(int argc, char** argv) {
    HelloWorldService().start_server("localhost"); 
}