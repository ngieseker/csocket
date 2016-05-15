cc=g++

all: tcp.o udp.o


tcp.o: client_test.o server_test.o

udp.o:  udp_client_test.o udp_server_test.o

client_test.o:
	$(cc) client.c client.h client_test.cpp -o client 
server_test.o:
	$(cc) server.c server.h server_test.cpp -o server
udp_client_test.o:
	$(cc)  udp_cli_test.cpp udp_client.h udp_client.c -o udp_client
udp_server_test.o:
	$(cc) udp_server.c udp_server.h udp_serv_test.cpp -o udp_server


clean :
	$ rm -r server client udp_client udp_server
