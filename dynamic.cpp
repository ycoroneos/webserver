#include "dynamic.h"
int cacheTemplates(const char* file)
{
    FILE *cachepages = fopen( file, "r" ); //file contains list of pages
    if (cachepages==NULL)
    {
      return 1;
    }
    char* line=NULL;
    int nbytes=0;
    while (1)
    {
      getline(&line, (size_t*)&nbytes, cachepages);
      if (nbytes==0)
      {
        //eof
        break;
      }
      //line now conatins the template file
      line[nbytes]=NULL;
      if (ctemplate::LoadTemplate(line, ctemplate::DO_NOT_STRIP)==true)
      {
        printf("loaded %s template\n", line);
      }
      delete line;
    }
    puts("done loading templates\n");
    return 0;
}

std::string route_dynamic(char* uri, int len)
{
  char p
  if (sscanf(
  return "None";
}
