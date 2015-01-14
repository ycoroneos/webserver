#include "mimetypes.h"


char *mimestring[]={
  [TEXT] "text/html",
  [JPEG] "image/jpeg",
};

int sendmimetype(int client, char *file)
{
  char *suffix=strchr(file, '.');
  int mimetype=TEXT;
  if (suffix==NULL)
  {
    mimetype=TEXT;
  }
  else if (strncmp(suffix, ".html", 5)==0)
  {
    mimetype=TEXT;
  }
  else if (strncmp(suffix, ".jpg", 4)==0)
  {
    mimetype=JPEG;
  }
  else
  {
    mimetype=TEXT;
  }
  char output[40];
  snprintf(output, sizeof(output), "Content-Type: %s\n\n", mimestring[mimetype]);
  write(client, output, strlen(output));
  return 0;
}
