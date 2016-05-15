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

  struct Udp_Client {
    
    int port_number, client_file_desc, file_desc ;
    struct sockaddr_in server_address, client_address;
    struct hostent *server;
    char buffer[256];
  };
  
  struct Udp_Client* create_client(int port, char* hostname, int bcast);

  void send_message(struct Udp_Client* sock, char* message);
  
  void destroy_client(struct Udp_Client* sock);
  
  //void rec_message(struct Udp_Socket* sock);
  
#ifdef __cplusplus
}
#endif
