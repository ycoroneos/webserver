#include "service.h"

const char* root="/home/yanni/webserver";

int service(int client)
{
    char buf[1024];
    memset(buf, '\0', 1024);
    int status=0;
    status=recv(client, buf, 1024, 0); //fill buffer with user data
    buf[status]='\0';
    printf("received:\n%s", buf);
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
