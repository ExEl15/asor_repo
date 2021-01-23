#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

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
        filtro.ai_protocol = 0; //Cualquier protocolo
	filtro.ai_socktype = 0; 
	filtro.ai_next = NULL;
	filtro.ai_addr=NULL;
	//Mostrar IP numérica, la familia de protocolos y tipo de socket
	
	if(getaddrinfo(argv[1], NULL, &filtro, &info)!= 0){
		perror("Error");
	}
	
	struct addrinfo *i;
        for(i = info; i != NULL; i->ai_next){

		//Dos familias
		switch(i->ai_family){
		case AF_INET:;//IPv4
			struct sockaddr_in *data = i->ai_addr;
			char toString[INET_ADDRSTRLEN+1]="";
			inet_ntop(AF_INET, &(data->sin_addr), toString, INET_ADDRSTRLEN+1);
			printf("%s\t", toString);
		break;
		case AF_INET6:;
			struct sockaddr_in6 *data6 = i->ai_addr;
			char toString6[INET6_ADDRSTRLEN+1]= "";
			inet_ntop(AF_INET6,&(data6->sin6_addr), toString6, INET6_ADDRSTRLEN+1);
			printf("%s\t",toString6);

		break;
		default:;
			printf("Familia desconocida");

		break;
		}
	}
		printf("%i\t%i\t\n",i->ai_family, i->ai_socktype);        
return 0;
} 
