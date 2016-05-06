cc=g++

all: client_test.o server_test.o

client_test.o:
	$(cc) client.c client.h client_test.cpp -o client 
server_test.o:
	$(cc) server.c server.h server_test.cpp -o server


clean :
	$ rm -r server client
