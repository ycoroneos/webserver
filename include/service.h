#ifndef SERVICE_H
#define SERVICE_H

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "http_parser.h"
int service(int client); //service a request by parsing it and returning what it wanted

#endif
