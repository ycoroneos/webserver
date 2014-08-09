#pragma once

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctemplate/template.h>
#include <string>

#define UNKNOWN -1
#define GET 0
#define POST 1

#define DATELENGTH 25
#define AGENTLENGTH 100
#define FILELENGTH 75
#define VERSIONLENGTH 50
#define CKLENGTH 200


struct http_request
{
  short type; //GET or POST
  char cookie[CKLENGTH]; //the cookie I (may) have sent it
  unsigned int contentLength; //length in bytes of the message
  char date[DATELENGTH]; //timestring of when this was sent
  char userAgent[AGENTLENGTH]; //browser that sent it
  char file[FILELENGTH]; //the file to post or get or molest
  char httpVersion[VERSIONLENGTH]; //http protocol that sent this
};

void initrequest(http_request* request);

int parse_response(const char* data, http_request* request, ctemplate::TemplateDictionary* dict);
