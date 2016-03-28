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
  close(sock->file_desc);
	free(sock);
}


void send_message(struct Client_Socket* sock, char* message) {
  int result = write(sock->file_desc, message, strlen(message));
  if (result < 0) fprintf(stderr, "ERROR: failed to send message\n");
}

char* rec_message(struct Client_Socket* sock) {
  char buffer[256];
  int result  = read(sock->file_desc,buffer,255);
  if (result < 0) fprintf(stderr, "ERROR: failed to read message\n");
  //return buffer;
}
