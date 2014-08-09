#include "http_parser.h"

short getType(const char* data)
{
  if (strstr(data, "GET")!=NULL)
    return GET;
  else if (strstr(data, "POST")!=NULL)
    return POST;
}

int parse_response(const char* data, http_request* request, ctemplate::TemplateDictionary* dict)
{
  request->type=getType(data);
  const char* start=strstr(data, " "); //find the first whitespace
  if (start==NULL)
  {
    return -1; //something's fucked
  }
  const char* end=strstr(start, " "); //find the second whitespace
  if (end==NULL)
  {
    return -1; //something's fucked
  }
  request->file=std::string(start, end-start); //hope this works
  start=strstr(end, "HTTP/"); //get the HTTP type
  if (start==NULL)
    return -1;
  end=strstr(start, "\r\n"); //go to the end of the first line
  if (end==NULL)
    return -1;
  request->httpVersion=std::string(start, end-start); //copy over the http protocol version
  return 0;
}
