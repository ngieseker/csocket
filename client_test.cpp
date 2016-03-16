//  Simple test for the client
#include "client.h"
#include <string>

int main() {
	struct Client_Socket* client;
	char host[] =  "127.0.0.1";
	client = create_client(45678, host);
	destroy_client(client);
}
