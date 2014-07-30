#include "service.h"

const char* root="/home/yanni/webserver";

int service(int client)
{
    char buf[256];
    memset(buf, 0, 256);
    int status=recv(client, buf, 256, 0); //fill buffer with user data
    if (status==0)
    {
        printf("lost connection\n");
    }
    printf("%s\n", buf);
    char uri[250];
    memset(uri, 0, 250);
    //use sscanf with a max string length to avoid overflow
    if (sscanf(buf, "GET %249s HTTP/1.1\n", uri)==1)
    {
        //what is this crap?
        if (uri[0]==0 || strstr(uri, "..")!=NULL)
        {
            return 1;
        }
        //they want the index page
        if (uri[1]==0)
        {
            strcat(uri, "index.html");
        }
        char file[300];
        memset(file, 0, 300);
        strcat(file, root);
        strcat(file, uri);
        printf("serving %s\n", file);
        FILE *webpage;
        webpage=fopen(file, "r");
        //file didn't exist
        if (webpage==NULL)
        {
            return 1;
        }
        fseek(webpage, 0, SEEK_END);
        long fsize = ftell(webpage);
        fseek(webpage, 0, SEEK_SET);
        char response[25];
        int count=sprintf(response, "Content-length: %li", fsize);
        write(client, "HTTP/1.1 200 OK\n", 16);
        write(client, response, count);
        write(client, "Connection: Close\n", 18);
        write(client, "Content-Type: text/html\n\n", 25);
        char *string = new char[fsize + 1];
        fread(string, fsize, 1, webpage);
        fclose(webpage);
        int bytes=0;
        while (bytes<=fsize)
        {
            bytes+=write(client, string, fsize);
        }
        delete string;
        sleep(1000);
    }
    else if (sscanf(buf, "POST %249s HTTP/1.1\n", uri)==1)
    {
        //what is this crap?
        if (uri[0]==0 || strstr(uri, "..")!=NULL)
        {
            return 1;
        }
        int param_length;
        char params[250];
        memset(params, 0, 250);
        if (sscanf(buf, "Content-Length:%i", &param_length)!=1)
        {
          return 1;
        }
        //they want the index page
        std::string output=route_dynamic(uri, strlen(uri));
        char response[25];
        int count=sprintf(response, "Content-length: %li", output.length());
        write(client, "HTTP/1.1 200 OK\n", 16);
        write(client, response, count);
        write(client, "Connection: Close\n", 18);
        write(client, "Content-Type: text/html\n\n", 25);
        int bytes=0;
        while (bytes<=output.length())
        {
            bytes+=write(client, output.c_str(), output.size());
        }
        sleep(1000);
    }
    //check if the browser wants to keep the connection alive
    if (strstr(buf, "Connection: keep-alive")!=NULL)
    {
      puts("HISS\n");
    }
    return 1;
}
