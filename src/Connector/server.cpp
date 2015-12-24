#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

class Server
{
	public:
		Server(int portno);

	private:
		void error(const char *msg);
};

void Server::error(const char *msg)
{
    perror(msg);
    exit(1);
}

Server::Server(int portno)
{
	int sockfd, newsockfd;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	if (!portno || portno == 0) {
	    fprintf(stderr,"ERROR, no port provided\n");
	    exit(1);
	}

	sockfd =  socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) 
	   error("ERROR opening socket");

	bzero((char *) &serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;  
	serv_addr.sin_addr.s_addr = INADDR_ANY;  
	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
	         error("ERROR on binding");

	listen(sockfd,5);

	clilen = sizeof(cli_addr);

	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0) 
	     error("ERROR on accept");

	printf("server: got connection from %s port %d\n",
	       inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

	send(newsockfd, "Hello, world!\n", 13, 0);

	bzero(buffer,256);

	n = read(newsockfd,buffer,255);
	if (n < 0) error("ERROR reading from socket");
	printf("Here is the message: %s\n",buffer);

	close(newsockfd);
	close(sockfd);
}