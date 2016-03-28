//  Simple test for the client
#include "client.h"
#include <string>

using std::string;

int main() {
	struct Client_Socket* client;
	char host[] =  "127.0.0.1";
	client = create_client(45678, host);
  char msg[] = "Hello";
  send_message(client,msg );
	destroy_client(client);
}
