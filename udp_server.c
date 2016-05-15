#include "udp_server.h"
#include "sys/socket.h"
#include "string.h"


// constant define
#define BUFFER_SIZE 255 

struct Udp_Server* create_server(int port, int bcast) {
  struct Udp_Server* sock;
  sock = (struct Udp_Server*)malloc(100*sizeof(struct Udp_Server));

  sock->port_number = port;
  sock->file_desc = socket(AF_INET, SOCK_DGRAM, 0);
  sock->server_address.sin_family = AF_INET;
	sock->server_address.sin_port = htons((u_short) port);
  sock->server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	
  int res = bind(sock->file_desc, (struct sockaddr *) &sock->server_address,
             sizeof(struct sockaddr_in));
  if (res < 0) 		fprintf(stderr, "ERROR: failed to bind\n");
  setsockopt(sock->file_desc, SOL_SOCKET, SO_BROADCAST, &bcast, sizeof(bcast));
  return sock; 
}

/*
void send_message(struct Udp_Socket* sock, char* message) {
  int res = sendto(sock->file_desc, message, strlen(message), 0,
                   (struct sockaddr *)& sock->server_address, sizeof(sock->server_address));
  if (res < 0) {
    fprintf(stderr, "ERROR: failed to send message\n");
  }
}
*/

void destroy_server(struct Udp_Server* sock) {
  close(sock->file_desc);
  close(sock->client_file_desc);
	free(sock);

}

void rec_message(struct Udp_Server* sock) {
  int res = recvfrom(sock->file_desc, sock->buffer, BUFFER_SIZE, 0,
                     (struct sockaddr *)& sock->server_address,
                     (socklen_t *) sizeof(sock->server_address));
}
