#include "server.h"
#include "string.h"

// constant define
#define BUFFER_SIZE 255 

struct Server_Socket* create_server(int port) {
  struct Server_Socket* sock;
  sock = (struct Server_Socket*)malloc(100*sizeof(struct Server_Socket));

  sock->port_number = port;
  sock->file_desc = socket(AF_INET, SOCK_STREAM, 0);
  sock->server_address.sin_family = AF_INET;
  sock->server_address.sin_addr.s_addr = INADDR_ANY;
	sock->server_address.sin_port = htons((u_short) port);

  int res = bind(sock->file_desc, (struct sockaddr *) &sock->server_address,
             sizeof(struct sockaddr_in));
  if (res < 0) 		fprintf(stderr, "ERROR: failed to connect\n");
  
  return sock;  
}

  void lis_acpt(struct Server_Socket* sock) {
  int len =  sizeof(struct sockaddr_in);
  listen(sock->file_desc, 5);
  sock->client_file_desc = accept(sock->file_desc,
                                  (struct sockaddr *) &sock->client_address,
                                  (socklen_t *) &len);
  if(sock->client_file_desc < 0) fprintf(stderr, "ERROR: failed to accept\n");
}

void destroy_server(struct Server_Socket* sock) {
  close(sock->file_desc);
  close(sock->client_file_desc);
	free(sock);

}

char* rec_message(struct Server_Socket* sock) {
  char buffer[256];
  int res = read(sock->client_file_desc,buffer, BUFFER_SIZE);
  if (res < 0) fprintf(stderr, "ERROR: failed to read message\n");

  // Modify the return for your own benefit
  printf("Here is the message: %s\n",buffer);
}
