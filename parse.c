#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main() {
    const char *jsonInput = "{\"name\":\"John\",\"age\":30,\"isStudent\":false}";

    // Parse JSON string
    cJSON *parsedRoot = cJSON_Parse(jsonInput);

    if (parsedRoot) {
        const char *name = cJSON_GetObjectItem(parsedRoot, "name")->valuestring;
        int age = cJSON_GetObjectItem(parsedRoot, "age")->valueint;
        int isStudent = cJSON_GetObjectItem(parsedRoot, "isStudent")->valueint;

        printf("Parsed JSON:\n");
        printf("Name: %s\nAge: %d\nIs Student: %s\n", name, age, isStudent ? "true" : "false");

        cJSON_Delete(parsedRoot);
    } else {
        printf("Error parsing JSON.\n");
    }

    return 0;
}

