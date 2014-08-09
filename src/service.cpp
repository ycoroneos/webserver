#include "service.h"

const char* root="/home/yanni/webserver";

int service(int client)
{
    char buf[256];
    memset(buf, 0, 256);
    int status=0;
    while (status<=256)
    {
      status+=recv(client, buf, 256, 0); //fill buffer with user data
    }
    http_request request;
    ctemplate::TemplateDictionary dict("dict");
    if (parse_response(buf, &request, &dict)==-1)
    {
      return -1;
    }
    //check if the browser wants to keep the connection alive
    if (strstr(buf, "Connection: keep-alive")!=NULL)
    {
      puts("HISS\n");
    }
    return 0;
}
