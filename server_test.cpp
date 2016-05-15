//  Simple test for the server
#include "server.h"
#include <string>
#include <iostream>

int main() {
	struct Server_Socket* server;
	server = create_server(45678);
  lis_acpt(server);
  rec_message(server);
  std::cout << server->buffer <<'\n';
	destroy_server(server);
}
