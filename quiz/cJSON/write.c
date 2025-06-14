
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

/*

  In this example we want to build and parse the following JSON:

  {
    "name": "Awesome 4K",
    "resolutions":
        [
          {
            "width": 1280,
            "height": 720
          },
          {
            "width": 1920,
            "height": 1080
          },
          {
            "width": 3840,
            "height": 2160
          }
        ]
  }

*/

#include "cJSON.h"
#include <stdio.h>

char* create_monitor(void)
{
    const unsigned int resolution_numbers[3][2] = { { 1280, 720 }, { 1920, 1080 }, { 3840, 2160 } };
    char* string = NULL;
    cJSON* name = NULL;
    cJSON* resolutions = NULL;
    cJSON* resolution = NULL;
    cJSON* width = NULL;
    cJSON* height = NULL;
    size_t index = 0;

    // Create empty json object
    cJSON* monitor = cJSON_CreateObject();
    if (monitor == NULL)
    {
        goto end;
    }
    // Add name to that object
    name = cJSON_CreateString("Awesome 4K");
    if (name == NULL)
    {
        goto end;
    }
    cJSON_AddItemToObject(monitor, "name", name);

    // Add resolutions to that object
    resolutions = cJSON_CreateArray();
    if (resolutions == NULL)
    {
        goto end;
    }
    cJSON_AddItemToObject(monitor, "resolutions", resolutions);
    for (index = 0; index < (sizeof(resolution_numbers) / (2 * sizeof(int))); ++index)
    {
        resolution = cJSON_CreateObject();
        if (resolution == NULL)
        {
            goto end;
        }
        cJSON_AddItemToArray(resolutions, resolution);

        width = cJSON_CreateNumber(resolution_numbers[index][0]);
        if (width == NULL)
        {
            goto end;
        }
        cJSON_AddItemToObject(resolution, "width", width);

        height = cJSON_CreateNumber(resolution_numbers[index][1]);
        if (height == NULL)
        {
            goto end;
        }
        cJSON_AddItemToObject(resolution, "height", height);
    }

    string = cJSON_Print(monitor);
    if (string == NULL)
    {
        fprintf(stderr, "Failed to print monitor.\n");
    }

end:
    cJSON_Delete(monitor);
    return string;
}
int main()
{
    FILE* file;

    char* monitor_string = create_monitor();
    file = fopen("monitor.json", "w");
    fprintf(file, "%s\n", monitor_string);
    printf("%s", monitor_string);
    fclose(file);

    return 0;
}
