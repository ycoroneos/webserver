#include "http_parser.h"

void initrequest(struct http_request* request)
{
  request->type=UNKNOWN;
  memset(request->cookie, '\0', CKLENGTH);
  request->contentLength=0;
  memset(request->date, '\0', DATELENGTH);
  memset(request->userAgent, '\0', AGENTLENGTH);
  memset(request->file, '\0', FILELENGTH);
  memset(request->httpVersion, '\0', VERSIONLENGTH);
  return;
}

short getType(const char* data)
{
  if (strstr(data, "GET")!=NULL)
    return GET;
  else if (strstr(data, "POST")!=NULL)
    return POST;
}

//get string in between start and end chars conatined in input
//fill buffer with result
//inputs then points to after where the string was found
int getEnclosedString(const char* start, const char* end, char* input, char* buf, int length)
{
  const char* begin=strstr((const char*)input, start);
  if (begin==NULL)
    return -1;
  const char* stop=strstr(begin, end);
  if (end==NULL)
    return -1;
  ++begin;
  if ((stop-begin)>length)
    return -1;
  strncpy(buf, begin, stop-begin);
  buf[stop-start]='\0';
  input=(char*)end;
  return 0;
}

/*
 *Parse tokens in the header, there are 2. : and "\r\n"
 *use strtok()
 *
 */

int parseHeader(char* data, struct http_request* request)
{
  //char header[20];
  //char value[200];
  //memset(header, '\0', 20);
  //memset(value, '\0', 200);
  char *header, *value;
  header=strtok(data,":");
  value=strtok(NULL, "\r\n");
  if (header==NULL || value==NULL)
  {
    return -1;
  }
  if (strncmp(header, "Cookie", 6)==0)
  {
    //its the cookie
    strncpy(request->cookie, value, CKLENGTH);
  }
  else if (strncmp(header, "Content-Length", 14)==0)
  {
    //content length
    request->contentLength=strtol(value, NULL, 0);
    //sscanf(value, "%u", &request->contentLength);
  }
  else if (strncmp(header, "Date", 4)==0)
  {
    //datestring
    strncpy(request->date, value, DATELENGTH);
  }
  else if (strncmp(header, "User-Agent", 10)==0)
  {
    //browser string
    strncpy(request->userAgent, value, AGENTLENGTH);
  }
  return 0;
}


int parse_response(char* data, struct http_request* request)
{
  //char type[6];
  //memset(type, '\0', 6);
  char *type;
  char *file;
  char *httpVersion;
  type=strtok(data, " ");
  file=strtok(NULL, " ");
  httpVersion=strtok(NULL, "\r\n");
  if (type==NULL || request==NULL || httpVersion==NULL)
  {
    return -1;
  }
  strncpy(request->file, file, 75);
  strncpy(request->httpVersion, httpVersion, 50);
  //sscanf(data, "%6s %75s %50s\r\n", type, request->file, request->httpVersion);
  if (strncmp(request->file, "..", 2)==0)
  {
    printf("tried to jailbreak\n");
    return -1;
  }
  if (strlen(request->file)==1)
    strncpy(request->file, "/index.html", 11);
  if (strncmp(type, "GET",3)==0)
    request->type=GET;
  else if (strncmp(type, "POST", 4)==0)
    request->type=POST;
  else if (request->type==UNKNOWN)
  {
    printf("unknown request type\n");
    return -1;
  }
  /*
  data=strstr(data, "\r\n");
  if (data==NULL)
  {
    printf("error trying to get headers\n");
    return -1;
  }
  data+=2;
  while (parseHeader(data, request)==0)
  {
    data=strstr(data, "\r\n");
    if (data==NULL)
    {
      printf("error parsing headers\n");
      return -1;
    }
    data+=2;
  }
  */
  while (parseHeader(data, request)==0)
  {
  }
  //now we're at the content
  /*data=strstr(data, "\r\n");
  if (data==NULL)
  {
    printf("error acquiring content\n");
    return -1;
  }
  data+=2;*/
  return 0;
}
