#include "service.h"

const char* root="/home/yanni/webserver";

int service(int client)
{
    bool keepalive=false;
    char buf[256];
    do
    {
        memset(buf, 0, 256);
        int status=recv(client, buf, 256, 0); //fill buffer with user data
        if (status==0)
        {
          printf("closing connection\n");
          keepalive=false;
        }
        printf("%s\n", buf);
        char uri[250];
        memset(uri, 0, 250);
        //use sscanf with a max string length to avoid overflow
        if (sscanf(buf, "GET %249s HTTP/1.1\n", uri)==1)
        {
            //what is this crap?
            if (uri[0]==0)
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
            int count=sprintf(response, "Content-length: %i", fsize);
            write(client, "HTTP/1.1 200 OK\n", 16);
            write(client, response, count);
            write(client, "Content-Type: text/html\n\n", 25);
            //write(new_socket, "<html><body><H1>Hello world</H1></body></html>",46);
            char *string = new char[fsize + 1];
            fread(string, fsize, 1, webpage);
            fclose(webpage);
            write(client, string, fsize);
            /*int count=0;
            while (count<=fsize)
            {
                count+=send(client, string, fsize, 0);
            }
            */
            delete string;
        }
        //check if the browser wants to keep the connection alive
        if (strstr(buf, "Connection: keep-alive")!=NULL)
        {
            keepalive=true;
        }
    } while (keepalive==true);
    return 1;
}
