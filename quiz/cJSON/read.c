
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
  FILE* fp = fopen("books.json", "r");
  if (fp == NULL) {
    printf("Failed to open JSON file.\n");
    return 1;
  }

  char buffer[10024];
  if (fread(buffer, 1, 10024, fp) <= 0) {
    printf("Failed to read JSON file.\n");
    return 1;
  }
  cJSON* root = cJSON_Parse(buffer);
  if (!root) {
    printf("Failed to parse JSON.\n");
    return 1;
  }
  cJSON* books = cJSON_GetObjectItemCaseSensitive(root, "books");

  const cJSON* book = NULL;
  cJSON_ArrayForEach(book, books) {
    char* title = cJSON_GetObjectItemCaseSensitive(book, "title")->valuestring;
    char* author =
        cJSON_GetObjectItemCaseSensitive(book, "author")->valuestring;
    int published_year =
        cJSON_GetObjectItemCaseSensitive(book, "published_year")->valueint;
    char* genre = cJSON_GetObjectItemCaseSensitive(book, "genre")->valuestring;
    int pages = cJSON_GetObjectItemCaseSensitive(book, "pages")->valueint;
    char* language =
        cJSON_GetObjectItemCaseSensitive(book, "language")->valuestring;
    char* publisher =
        cJSON_GetObjectItemCaseSensitive(book, "publisher")->valuestring;
    printf("%s \n %s \n %d \n %s \n %d \n %s \n %s \n", title, author,
           published_year, genre, pages, language, publisher);
  }
  fclose(fp);
  return 0;
}
