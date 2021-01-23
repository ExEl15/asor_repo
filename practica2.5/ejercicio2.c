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
	bind(sd, info->ai_addr, info->ai_addrlen);
	
	struct sockaddr_storage client_addr;
  	socklen_t client_addrlen = sizeof(client_addr);
	
	char buf[2];
  	char host[NI_MAXHOST];
 	char serv[NI_MAXSERV];
	while (buf[0] != 'q') {
		size_t c = recvfrom(sd, buf, 2, 0, (struct sockaddr *) &client_addr, &client_addrlen);
 		buf[1] = '\0';
  		getnameinfo((struct sockaddr *) &client_addr, client_addrlen, host, NI_MAXHOST,serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);
  		printf("Mensaje de %s:%s: %s\n", host, serv, buf);
  		
		time_t tiempo = time(NULL);
    		struct tm *stime = localtime(&tiempo);
    		size_t max;
    		char stringT[50];
		size_t size;
		switch(buf[0]){
		case 't':;
			size = strftime(stringT, max, "%I:%M:%S %p", stime);
                        stringT[size] = '\0';
                        sendto(sd, stringT, size, 0, (struct sockaddr *) &client_addr, client_addrlen);
		break;
		case 'd':;
			size = strftime(stringT, max, "%Y-%m-%d", stime);
      			stringT[size] = '\0';
		      	sendto(sd, stringT, size, 0, (struct sockaddr *) &client_addr, client_addrlen);
		break;
		default:;
			printf("Comando no reconocido");
		break;
		}
    
}

printf("Saliendo...");
return 0;
} 
