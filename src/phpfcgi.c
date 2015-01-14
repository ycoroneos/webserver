#include "phpfcgi.h"

//array of env variables php-fpm needs
char *fpm_args[]={
  "cgi-fcgi",
  "-bind",
  "-connect",
  "127.0.0.1:9000",
  NULL,
};

void initphpenvs(struct phpfpm_envs *env)
{
  memset(env, '\0', sizeof(struct phpfpm_envs));
}

void runphpfpm(int client, struct phpfpm_envs *env)
{
  int pipes[2];
  pipe(pipes);
  if (fork()==0)
  {
    //child
    setenv("QUERY_STRING", env->query_string, 1);
    setenv("REQUEST_METHOD", env->request_method, 1);
    setenv("CONTENT_TYPE", env->content_type, 1);
    setenv("CONTENT_LENGTH", env->content_length, 1);
    setenv("SCRIPT_NAME", env->script_name, 1);
    setenv("SCRIPT_FILENAME", env->script_filename, 1);
    setenv("REQUEST_URI", env->request_uri, 1);
    setenv("DOCUMENT_URI", env->document_uri, 1);
    setenv("DOCUMENT_ROOT", env->document_root, 1);
    setenv("SERVER_PROTOCOL", env->server_protocol, 1);
    setenv("GATEWAY_INTERFACE", env->gateway_interface, 1);
    setenv("SERVER_SOFTWARE", env->server_software, 1);
    setenv("REMOTE_ADDR", env->remote_addr, 1);
    setenv("REMOTE_PORT", env->remote_port, 1);
    setenv("SERVER_ADDR", env->serv_addr, 1);
    setenv("SERVER_PORT", env->serv_port, 1);
    setenv("SERVER_NAME", env->serv_name, 1);
    close(1);
    //write(client, "Content-Length: 2000\n", 21);
    close(pipes[0]);
    dup2(pipes[1], 1);
    //dup2(client, 1); //dup socket to stdout
    execvp("cgi-fcgi", fpm_args);
}
  //parent
  close(pipes[1]);
  while (wait(NULL)>0);
  const int chunksize=10;
  char result[chunksize];
  int amt=read(pipes[0], result, chunksize);
  while (amt>0)
  {
    char output[5+chunksize];
    memset(output, '\0', sizeof(output));
    snprintf(output, sizeof(output), "%x\r\n%s\r\n", amt, result);
    write(client, output, strlen(output));
    amt=read(pipes[0], result, chunksize);
  }
  write(client, "0\r\nTransfer-Encoding: chunked\r\n", 30);
  close(pipes[0]);
}

int isphpfile(char* file)
{
  char *suffix=strchr(file, '.');
  if (suffix==NULL)
    return 0;
  if (strncmp(suffix, ".php", 4)==0)
  {
    return 1;
  }
  return 0;
}
