#include "service.h"

const char* root_dir="/home/yanni/webserver/http";

int service(int client)
{
    char buf[2048];
    memset(buf, '\0', 2048);
    int status=0;
    status=recv(client, buf, 2048, 0); //fill buffer with user data
    buf[status]='\0';
    struct http_request request;
    initrequest(&request);
    if (parse_response(buf, &request)==-1)
    {
      perror("bad request");
      write(client, "bad request", 11);
      return -1;
    }
    //char *filepath=(char*)malloc(strlen(request.file)+strlen(root_dir));
    char filepath[80];
    memset(filepath, '\0', 80);
    strncpy(filepath, root_dir, strlen(root_dir));
    strcat(filepath, request.file);
    FILE *f = fopen(filepath,"rb");
    if (f==NULL)
    {
      printf("bad file %s\n", filepath);
      perror("\terror");
      return -1;
    }
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *output=(char*)malloc(fsize+1);
    fread(output, fsize, 1, f);
    fclose(f);

    //output[fsize] = 0;
    //send response headers
    int contentLength=fsize;
    char response[25];
    memset(response, '\0', 25);
    if (write(client, "HTTP/1.1 200 OK\n", 16)!=16)
    {
      puts("write failed\n");
      return -1;
    }
    sprintf(response, "Content-Length: %d\n", contentLength);
    write(client, response, strlen(response));
    if (write(client, "Connection: close\n", 18)!=18)
    {
      return -1;
    }
    if (write(client, "Content-Type: text/html\n\n", 25)!=25)
    {
      return -1;
    }
    int bytes=0;
    while (bytes<contentLength)
    {
      bytes+=write(client, &output[bytes], contentLength-bytes);
    }
    //free(filepath);
    free(output);
    return 0;
}
