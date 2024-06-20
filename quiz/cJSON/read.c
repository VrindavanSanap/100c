
/*

  cJSON represents JSON data using the cJSON struct data type:

  The cJSON structure:

    typedef struct cJSON
    {
      struct cJSON *next;
      struct cJSON *prev;
      struct cJSON *child;
      int type;
      char *valuestring;
      int valueint;
      double valuedouble;
      char *string;
    } cJSON;

*/

#include <stdio.h>
#include "cJSON.h"


int main() { 
  FILE *file;
  file = fopen("books.json", "w");
  



  fclose(file);

  return 0; 
}
