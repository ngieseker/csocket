#include "client.h"
#include "string.h"

/* Modifies socket passed in */
struct Client_Socket* create_client(int port, char* hostname) {
	struct Client_Socket* sock;
	sock = (struct Client_Socket*)malloc(100*sizeof(struct Client_Socket));
	sock->port_number = port;
	sock->file_desc = socket(AF_INET, SOCK_STREAM, 0);
	sock->server_address.sin_family = AF_INET;
	sock->server_address.sin_port = htons((u_short) port);
	
	
	sock->server = gethostbyname(hostname);
	if (!sock->server) {
			fprintf(stderr,"ERROR, no such host\n");
			exit(0);
		}

	
	/*
		TODO: should we be using this? 

		char node[NI_MAXHOST];	
		getnameinfo((struct sockaddr*)&socket.server_address,
							sizeof(socket.server_address),node,
							sizeof(node), NULL, 0, 0);
	*/

	sock->server_address.sin_port = htons((u_short) port);
	memcpy(&sock->server_address.sin_addr,
				 sock->server->h_addr, sock->server->h_length);
	if (connect(sock->file_desc, (struct sockaddr *) &sock->server_address,
							sizeof(struct sockaddr_in)) < 0) {
		fprintf(stderr, "ERROR: failed to connect\n");
	}
	return sock;
	
}

void destroy_client(struct Client_Socket* sock) {
	free(sock);
}

int main() {
	struct Client_Socket* client;
	client = create_client(45678, "127.0.0.1");
	destroy_client(client);
}
