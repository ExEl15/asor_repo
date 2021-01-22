#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char* argv[]){
	if(argc== 1){
		perror("Argumentos");
		return -1;	
	}
	
	struct addrinfo *info;
	struct addrinfo filtro;

	memset(&filtro, 0, sizeof(struct addrinfo));
	filtro.ai_family = AF_UNSPEC; //IPv4 y IPv6
        filtro.ai_flags = AI_PASSIVE;
        filtro.ai_socktype = 0; //Cualquier protocolo
	//Mostrar IP numérica, la familia de protocolos y tipo de socket
	
	if(getaddrinfo(argv[1], NULL, &filtro, &info)!= 0){
		perror("Error");
	}
	
	struct addrinfo *i;
        for(i = info; i != NULL; i->ai_next){
                char host[NI_MAXHOST], service[NI_MAXSERV];
                getnameinfo(i->ai_addr, i->ai_addrlen, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICHOST);
                printf("Host: %s Puerto: %s Socktype: %s Family: %s \n", host, service, i->ai_socktype, i->ai_family);
        }



return 0;
} 
