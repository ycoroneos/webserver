#include "service.h"

const char* root_dir="/home/yanni/webserver/http";

int service(int client)
{
    char buf[2048];
    memset(buf, '\0', 2048);
    int status=0;
    status=recv(client, buf, 2048, 0); //fill buffer with user data
    buf[status]='\0';
    http_request request;
    initrequest(&request);
    ctemplate::TemplateDictionary dict("dict");
    if (parse_response(buf, &request, &dict)==-1)
    {
      return -1;
    }
    //check if the browser wants to keep the connection alive
    /*if (strstr(buf, "Connection: keep-alive")!=NULL)
    {
      puts("HISS\n");
    }
    */
    std::string file=std::string(root_dir)+std::string(request.file);
    std::string output;
    ctemplate::ExpandTemplate(file, ctemplate::DO_NOT_STRIP, &dict, &output);
    int bytes=0;
    while (bytes<=output.length())
    {
      bytes+=write(client, output.c_str(), output.length());
    }
    sleep(1000);
    return 0;
}
