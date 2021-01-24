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
	connect(sd,(struct sockaddr *)info->ai_addr, info->ai_addrlen);
	//bind
	//bind(sd, info->ai_addr, info->ai_addrlen);
	
	listen(sd,5);
	int clisd;
  	char buffin[256];
  	char buffout[256];
  	ssize_t c;

	
  while (1) {
    		c = read(0,buffout, 255);
    		buffout[c] = '\0';
    		send(sd,buffout, c, 0);


    		if ((buffout[0] == 'Q') && (c == 2)) {
      			printf("Conexión terminada\n");
      			exit(0);
    		}

    		c = recv(sd, buffin, 255, 0);
    		buffin[c] = '\0';
    		printf(buffin);
  	}

  close(sd);

return 0;
} 
