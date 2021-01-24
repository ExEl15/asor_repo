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
	filtro.ai_socktype = SOCK_STREAM; 
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
	
	listen(sd,5);
	struct sockaddr_storage client_addr;
  	socklen_t client_addrlen = sizeof(client_addr);
	
	int clisd;
  	char host[NI_MAXHOST];
 	char serv[NI_MAXSERV];
	ssize_t c;
	char buf[80];
	while (1) {
 		clisd = accept(sd, (struct sockaddr *) &client_addr, &client_addrlen);
    		
  		while (1) { // Comprobar mensaje!
    			
			
			getnameinfo((struct sockaddr *) &client_addr, client_addrlen, host, NI_MAXHOST,serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);
			printf("Conexión desde Host:%s Puerto:%s\n", host, serv);
			c = recv(clisd, buf, 80, 0);
      			buf[c] = '\0';						
    			if(buf[0] == 'Q' && c == 2){
				printf("Conexion terminada \n");
				exit(0);
			}
			send(clisd, buf, c, 0);
 		 }
		close(clisd);
  		
	}
	close(clisd);
return 0;
} 
