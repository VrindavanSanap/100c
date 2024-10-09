#include <cjson/cJSON.h>
#include <curl/curl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Callback function to write the response data
size_t write_callback(void *ptr, size_t size, size_t nmemb, char *data) {
  size_t total_size = size * nmemb;
  strncat(data, (char *)ptr, total_size); // Append response data to buffer
  return total_size;
}

int main() {
  char *BASE_URL = "https://generic709.herokuapp.com/stockc/";
  char *ticker = "AAPL";
  char *price;
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
  cJSON *json = cJSON_Parse(response);
  cJSON *price_json = cJSON_GetObjectItem(json, "price");
  price = price_json->valuestring;
  printf("Price: %s", price);
  cJSON *change_json = cJSON_GetObjectItem(json, "change");
  cJSON *time_json = cJSON_GetObjectItem(json, "time");
  cJSON *volume = cJSON_GetObjectItem(json, "volume");

  return 0;
}
