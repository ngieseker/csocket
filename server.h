/*  
		This is a lightweight TCP server socket
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

  struct Server_Socket {
    
    int port_number, client_file_desc, file_desc ;
    struct sockaddr_in server_address, client_address;
    struct hostent *server;
    char buffer[256];
  };
  
  struct Server_Socket* create_server(int port);

  void lis_acpt(struct Server_Socket* sock);

  //void send_message(struct Server_Socket* sock, char* message);
  
  void destroy_server(struct Server_Socket* sock);
  
  void rec_message(struct Server_Socket* sock);
  
#ifdef __cplusplus
}
#endif
