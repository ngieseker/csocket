/*  
		This is a lightweight client socket
		Provides a create, destoy, send, and recieve
		message functions.
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <unistd.h>


#ifdef __cplusplus
extern "C" {
#endif

  struct Client_Socket {
    
    int port_number, file_desc, num_char_read;
    struct sockaddr_in server_address;
    struct hostent *server;
    
  };
  
  struct Client_Socket* create_client(int port, char* hostname);

  void send_message(struct Client_Socket* sock, char* message);
  
  void destroy_client(struct Client_Socket* sock);
  
  char* rec_message(struct Client_Socket* sock, char* message);
  
#ifdef __cplusplus
}
#endif
