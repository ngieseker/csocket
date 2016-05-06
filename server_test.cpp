//  Simple test for the server
#include "server.h"
#include <string>

int main() {
	struct Server_Socket* server;
	server = create_server(45678);
  lis_acpt(server);
  rec_message(server);
	destroy_server(server);
}
