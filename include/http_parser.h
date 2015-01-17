#ifndef HTTP_PARSER
#define HTTP_PARSER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define UNKNOWN -1
#define GET 0
#define POST 1

#define DATELENGTH 25
#define AGENTLENGTH 100
#define FILELENGTH 75
#define VERSIONLENGTH 50
#define CKLENGTH 500
#define NPARAMS 50

struct parameter
{
  char name[25];
  char value[100];
};

struct http_request
{
  short type; //GET or POST
  char cookie[CKLENGTH]; //the cookie I (may) have sent it
  unsigned int contentLength; //length in bytes of the message
  char date[DATELENGTH]; //timestring of when this was sent
  char userAgent[AGENTLENGTH]; //browser that sent it
  char file[FILELENGTH]; //the file to post or get
  char httpVersion[VERSIONLENGTH]; //http protocol that sent this
  char contentType[100]; //type of content client sent
  char queryString[250];
  //struct parameter parameters[NPARAMS]; //params from a POST
};


void initrequest(struct http_request* request);

int parse_response(char* data, struct http_request* request);

#endif
