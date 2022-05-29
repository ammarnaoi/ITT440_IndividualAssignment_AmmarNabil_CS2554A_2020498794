#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

int main()
{
    int socket_desk;
    struct sockaddr_in servaddr, client1,client2;
    char buffer[1024];
   
    socket_desk = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desk == -1) {
        printf("Socket creation failed!\n");
        exit(0);
    }
    else
        printf("Socket created success!\n");
  
   
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("169.254.256.72");
    server.sin_port = htons(8080);
   
    if (connect(socket_desk, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Failed to connect to chat\n");
        exit(0);
    }
    else
        printf("Welcome to the chat!\n");
   
    	int exit = 0; 
	while (exit == 0)
	{
		int received = recv(socket_desk, buffer, sizeof buffer -1, 0);
			
			if (received != 1)
			{
				if (compare_strings (buffer, "exit") == -1)
				{
					printf ("Client 1: ");
					printf ("%s\n", buffer);
					
					memset (&buffer[0], 0, sizeof(buffer));
				}
				
				else exit = 1;
			}
			else
			{
				printf("Client 2: ");
				scanf(" %[^\n]s", buffer);
				
			
				send (socket_desk, buffer, sizeof buffer -1, 0);
				
				if (compare_strings (buffer, "exit") == -1)
				{
					memset (&buffer[0], 0, sizeof (buffer));
				}
				
				else exit = 1;
			}
		
		
	}
   
 func(sockfd);
      
return 0;
}
