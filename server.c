#include<stdio.h>
#include<string.h>	
#include<stdlib.h>	
#include<sys/socket.h>
#include<arpa/inet.h>	
#include<unistd.h>	
#include<pthread.h>

void *connection_handler(void *);

int main(int argc , char *argv[])
{
	int socket_desc , new_socket , c,len , *new_sock;
	struct sockaddr_in server , client1,client2;
	char *message;
	char buffer[1024];
	
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("169.254.156.72")
	server.sin_port = htons( 8080 );
	
	client1 = accept(socket_desc, (struct sockaddress *) &serverStorage, &addr_size);
  client2 = accept (socket_desc, (struct sockaddress *) &serverStorage, &addr_size);
	
	if( bind(socket_desc,(struct sockaddress *)&server , sizeof(server)) < 0)
	{
		puts("bind failed!");
		return 1;
	}
	puts("bind successful!");
	
	if ((listen(socket_desc, 5)) != 0) {
        printf("Listening failed!\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(client);
    
        connfd = accept(socket_desc, (SA*)&client, &len);
    if (connfd < 0) {
        printf("Acceptation failed..\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");
        
    int exit = 0;
	while (exit == 0)
	{
		recv(client2, buffer , 1024, 0);
		printf ("%s\n client1 send client2 a message!~~\n", buffer);
		send (client1, buffer , 1024, 0);
		
		if (compare_strings (buffer,"exit")== 0)
		{
			exit = 1;
		}
		else
		{
			memset (&buffer[0], 0, sizeof (buffer));
			
			recv (client1, buffer, 1024, 0);
			printf ("%s\n  client2 send client1 a message!~~\n", buffer);
			send (client2, buffer, 1024, 0);
			
			if (compare_strings (buffer, "exit") == 0)
			{
				exit = 1;
			}
		}
	}
	
	return 0;

}
