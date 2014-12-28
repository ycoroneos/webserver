#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "service.h" //simple routing


#define SERVER_PORT 80
#define LISTENQ 8 //also number of forks
static int services[LISTENQ]; //pids of forks

int main(int argc, char** argv)
{
  pid_t pid;

  int listener, conn, numconnections;
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
  memset(&servaddr, 0, sizeof(struct sockaddr_in));
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
  numconnections=0;
  while (1)
  {
    memset(&clientaddr, 0, sizeof(struct sockaddr_in));
    int len=sizeof(clientaddr);
    if ((conn=accept(listener, (struct sockaddr*) &clientaddr, (socklen_t*)&len))<0)
    {
      perror("error accepting connection...\n");
    }
    setsockopt(conn, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval));
    printf("connected client: %i\n", clientaddr.sin_addr.s_addr);
    pid=fork();
    if (pid==0)
    {
      close(listener);
      service(conn);
      close(conn);
      return 0;
    }
    else
    {
      close(conn);
    }
  }
  close(listener);
  perror("exiting");
  return 0;
}


//experimental
/*
void runservice()
{
  while (1)
  {
    memset(&clientaddr, 0, sizeof(struct sockaddr_in));
    int len=sizeof(clientaddr);
    if ((conn=accept(listener, (struct sockaddr*) &clientaddr, (socklen_t*)&len))<0)
    {
      perror("error accepting connection...\n");
    }
    printf("connected client: %i\n", &clientaddr.sin_addr.s_addr);

    setsockopt(conn, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval));
    service(conn);
    close(conn);
  }
  return;
}
*/
