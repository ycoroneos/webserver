#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream> //c++ streams

#include "service.h" //simple routing


#define SERVER_PORT 80
#define LISTENQ 8

int main(int argc, char** argv)
{
  int listener, conn;
  pid_t pid;
  struct sockaddr_in servaddr, clientaddr;
  struct timeval tv;

  tv.tv_sec = 10;  /* 10 Secs Timeout */
  tv.tv_usec = 0;  // Not init'ing this can cause strange errors
  listener=socket(AF_INET, SOCK_STREAM, 0);
  if (listener<0)
  {
    perror("couldn't establish listening socket\n");
    return 1;
  }
  memset(&servaddr, 0, sizeof(sockaddr_in));
  servaddr.sin_family=AF_INET;
  servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
  servaddr.sin_port=htons(SERVER_PORT);
  if (bind(listener, (struct sockaddr*) &servaddr, sizeof(servaddr))<0)
  {
    perror("couldn't bind socket\n");
    return 1;
  }
  if (listen(listener, LISTENQ)<0)
  {
    perror("couldn't listen on socket\n");
    return 1;
  }
  while (1)
  {
    memset(&clientaddr, 0, sizeof(sockaddr_in));
    int len=sizeof(clientaddr);
    if ((conn=accept(listener, (struct sockaddr*) &clientaddr, (socklen_t*)&len))<0)
    {
      perror("error accepting connection...\n");
    }
    printf("connected client: %i\n", &clientaddr.sin_addr.s_addr);

    setsockopt(conn, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval));
    if ((pid=fork()) == 0)
    {
      //this is the child process
      //Service the request and quit
      close(listener);
      memset(&servaddr, 0, sizeof(sockaddr_in)); //clients should have no knowledge of the master
      service(conn);
      close(conn);
      return 1;
    }
    close(conn);
  }
  return 0;
}
