#include <cjson/cJSON.h>
#include <curl/curl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Callback function to write the response data
size_t write_callback(void *ptr, size_t size, size_t nmemb, char *data) {
  size_t total_size = size * nmemb;
  if (total_size + strlen(data) < 2048) {  // Ensure buffer overflow is avoided
    memcpy(data + strlen(data), ptr, total_size);
    data[total_size + strlen(data)] = '\0';  // Null-terminate the string
  }
  return total_size;
}

int main() {
  char *BASE_URL = "https://generic709.herokuapp.com/stockc/AAPL";
  char *ticker = "AAPL";
  int price;
  int volume;
  CURL *curl;
  CURLcode res;
  char response[2048] = "";
  bool succ = false;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, BASE_URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    } else {
      printf("Response: %s\n", response);
      succ = true;
    }

    curl_easy_cleanup(curl);
  }

  if (succ) {
    cJSON *json = cJSON_Parse(response);
    if (json != NULL) {
      cJSON *price_json = cJSON_GetObjectItem(json, "price");
      cJSON *change_json = cJSON_GetObjectItem(json, "change");
      cJSON *time_json = cJSON_GetObjectItem(json, "time");
      cJSON *volume_json = cJSON_GetObjectItem(json, "volume");


      price = price_json->valueint;
      printf("Price: %d \n", price );
      change :wq

          // Optionally print change, time, and volume if needed
      if (change_json && cJSON_IsString(change_json)) {
        printf("Change: %s\n", change_json->valuestring);
      }
      if (time_json && cJSON_IsString(time_json)) {
        printf("Time: %s\n", time_json->valuestring);
      }
      if (volume_json) {
        printf("Volume: %d\n", volume_json->valueint);
      }

      cJSON_Delete(json);  // Free the JSON object
    } else {
      printf("Error parsing JSON.\n");
    }
  }

  return 0;
}
