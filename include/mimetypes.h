#ifndef MIMETYPES_H
#define MIMETYPES_H
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum MimeType
{
  TEXT=0,
  JPEG,
};
int sendmimetype(int client, char *file);

#endif
