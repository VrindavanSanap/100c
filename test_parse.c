#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main() {
    // Example JSON response string
    const char *response = "{\"content\": 42}";

    printf("Response:\n%s\n", response);

    cJSON *parsedRoot = cJSON_Parse(response);
    if (parsedRoot == NULL) {
        printf("JSON parsing failed.\n");
        return 1; // Return an error code
    }

    cJSON *contentItem = cJSON_GetObjectItem(parsedRoot, "content");
    if (contentItem != NULL && cJSON_IsNumber(contentItem)) {
        int pi = contentItem->valueint;
        printf("Parsed integer value: %d\n", pi);
    } else {
        printf("Could not find valid 'content' integer value.\n");
        cJSON_Delete(parsedRoot); // Clean up cJSON resources
        return 1; // Return an error code
    }

    cJSON_Delete(parsedRoot); // Clean up cJSON resources
    return 0; // Return success
}

