#include "udp_client.h"
#include <string>
#include <iostream>


int main() {

  struct Udp_Client* client;
  char mess1[] =  "Hello Friend";
  char mess2[] =  "Goodbye Friend";
  char host[] =  "127.255.255.255";
	client = create_client(45678, host, 1);
  send_message(client, mess1);
  send_message(client, mess2);
	destroy_client(client);

}
