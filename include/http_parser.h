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

struct http_request
{
  short type; //GET or POST
  std::string cookie; //the cookie I (may) have sent it
  unsigned int contentLength; //length in bytes of the message
  char date[25]; //timestring of when this was sent
  char userAgent[100]; //browser that sent it
  char file[75]; //the file to post or get or molest
  char httpVersion[50];; //http protocol that sent this
};

int parse_response(const char* data, http_request* request, ctemplate::TemplateDictionary* dict);
