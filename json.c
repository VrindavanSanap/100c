#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"


int main() {
    // Create a JSON object
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "name", "John Doe");
    cJSON_AddNumberToObject(root, "age", 30);
    
    cJSON *address = cJSON_CreateObject();
    cJSON_AddStringToObject(address, "street", "123 Main St");
    cJSON_AddStringToObject(address, "city", "Exampleville");
    cJSON_AddItemToObject(root, "address", address);

    // Convert cJSON object to a string
    char *jsonStr = cJSON_Print(root);
    printf("Generated JSON:\n%s\n", jsonStr);
    
    // Parse JSON string
    cJSON *parsedRoot = cJSON_Parse(jsonStr);
    if (parsedRoot == NULL) {
        printf("Failed to parse JSON.\n");
        return 1;
    }

    // Access values from the parsed JSON
    const char *name = cJSON_GetObjectItem(parsedRoot, "name")->valuestring;
    int age = cJSON_GetObjectItem(parsedRoot, "age")->valueint;
    cJSON *parsedAddress = cJSON_GetObjectItem(parsedRoot, "address");
    const char *street = cJSON_GetObjectItem(parsedAddress, "street")->valuestring;
    const char *city = cJSON_GetObjectItem(parsedAddress, "city")->valuestring;

    printf("Parsed JSON:\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Address: %s, %s\n", street, city);

    // Clean up
    cJSON_Delete(root);
    cJSON_Delete(parsedRoot);
    free(jsonStr);

    return 0;
}

