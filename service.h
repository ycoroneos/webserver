#pragma once
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include "dynamic.h"
int service(int client); //service a requets by parsing it and returning what it wanted
