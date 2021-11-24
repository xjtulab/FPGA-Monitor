#include "server.h"

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>

#define SERVER_PORT 1234
#define MAXLINE 128

void StartServer(){
    int listenfd = 0;
    int connfd = 0;
    int n;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    char ip[MAXLINE] = {0};
    char recvMsg[MAXLINE] = {0};

    /* Create Server socket address struct. */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    /* Default ip address is 0.0.0.0 */ 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port  = htons(SERVER_PORT); /* Server port number */

    /* Create listened socket fd. */
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd == -1)
        Log(ERROR, "socket create error!");
    
    /* Bind socket with target address. */
    if(bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)))
        Log(ERROR, "bind socket error!");
    
    /* Server start at ... */
    Log(NOTICE, "Server start at %s:%d,", inet_ntop(AF_INET, &servaddr.sin_addr, ip, MAXLINE),
        ntohs(servaddr.sin_port));
    
    /* The max count connected client of this server is 4. */
    listen(listenfd, 4);

    /* Accept one client. */
    clilen = sizeof(cliaddr);
    connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
    if(connfd == -1)
        Log(ERROR, "accept client failed.");
    
    Log(NOTICE, "connect from %s %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, ip, MAXLINE),
        ntohs(cliaddr.sin_port));

    /* Receive message and send the same message repeately. */
    while((n = read(connfd, recvMsg, MAXLINE) != 0)){
        Log(NOTICE, "Received msg: %s",recvMsg);
        write(connfd, recvMsg, MAXLINE);

        /* Remember to clear message buffer each time. */
        memset(recvMsg, 0, sizeof(recvMsg));
    }

    close(connfd);
    close(listenfd);
}