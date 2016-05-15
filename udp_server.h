/*  
		This is a lightweight server socket
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

  struct Udp_Server {
    
    int port_number, client_file_desc, file_desc ;
    struct sockaddr_in server_address, client_address;
    struct hostent *server;
    char buffer[256];
  };
  
  struct Udp_Server* create_server(int port, int bcast);

  //  void send_message(struct Udp_Socket* sock, char* message);
  
  void destroy_server(struct Udp_Server* sock);
  
  void rec_message(struct Udp_Server* sock);
  
#ifdef __cplusplus
}
#endif
