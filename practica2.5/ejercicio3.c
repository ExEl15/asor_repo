#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#include <time.h>
#include <netinet/in.h>
int main(int argc, char* argv[]){
	if(argc<2){
		perror("Argumentos");
		return -1;	
	}
	
	
	struct addrinfo *info;
	struct addrinfo filtro;

	memset(&filtro, 0, sizeof(struct addrinfo));
	filtro.ai_family = AF_UNSPEC; //IPv4 y IPv6
        filtro.ai_flags = AI_PASSIVE;
        filtro.ai_protocol = 0; //Cualquier protocolo
	filtro.ai_socktype = SOCK_DGRAM; 
	//filtro.ai_next = NULL;
	//filtro.ai_addr=NULL;
	//Mostrar IP numérica, la familia de protocolos y tipo de socket
	
	if(getaddrinfo(argv[1], argv[2], &filtro, &info)!= 0){
		perror("Error");
	}
	
	struct addrinfo *i;


	//socket
	int sd = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
	
	//bind
	//bind(sd, info->ai_addr, info->ai_addrlen);
	
	struct sockaddr_storage client_addr;
  	socklen_t client_addrlen = sizeof(client_addr);
	
	char buf[2];
  	
 	
	
	sendto(sd,argv[3],2,0,info->ai_addr, info->ai_addrlen);
	
	printf("%s\t",argv[3]);
	
	if(*argv[3] == 'd' || *argv[3] == 't'){
		char data[50];
   	 	ssize_t bytes = recvfrom(sd, data, 50, 0, (struct sockaddr *) &client_addr, &client_addrlen);
    		data[bytes] = '\0';
 		 printf("%s\n", data);
	}
return 0;
} 
