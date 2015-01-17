#ifndef PHPFCGI_H
#define PHPFCGI_H

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct phpfpm_envs
{
  char query_string[80];
  char request_method[10];
  char content_type[30];
  char content_length[10];
  char script_name[100];
  char script_filename[100];
  char request_uri[100];
  char document_uri[100];
  char document_root[100];
  char server_protocol[25];
  char gateway_interface[25];
  char server_software[25];
  char remote_addr[25];
  char remote_port[25];
  char serv_addr[25];
  char serv_port[25];
  char serv_name[25];
  char cookie[500];
};

void runphpfpm(int client_socket, struct phpfpm_envs *env);
void initphpenvs(struct phpfpm_envs *env);
int isphpfile(char* file);
#endif
