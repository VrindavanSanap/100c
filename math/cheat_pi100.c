#include <cjson/cJSON.h>
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                     void *user_data) {
  size_t total_size = size * nmemb;
  char *response = (char *)user_data;
  strcat(response, (char *)contents);
  return total_size;
}

int main() {
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  if (curl) {
    char url[] = "https://api.pi.delivery/v1/pi?start=0&numberOfDigits=100";
    char response[4096] = "";
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    } else {
      cJSON *parsedRoot = cJSON_Parse(response);
      if (parsedRoot) {
        const char *content =
            cJSON_GetObjectItem(parsedRoot, "content")->valuestring;
        printf("%s\n", content);
        cJSON_Delete(parsedRoot);
      } else {
        printf("Error parsing JSON.\n");
      }
    }
  }
}
