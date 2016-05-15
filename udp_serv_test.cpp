//  Simple test for udp sockets
#include "udp_server.h"
#include <string>
#include <iostream>
#include <string.h>


int main() {
	struct Udp_Server* server;
	server = create_server(45678, 1);
  while (true) {
    rec_message(server);
    std::cout << server->buffer << '\n';
    if (!strcmp(server->buffer, "Goodbye Friend")) break; 
  }
  destroy_server(server);
}
