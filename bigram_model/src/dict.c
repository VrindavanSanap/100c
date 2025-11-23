#include <bigram_model/dict.h>
#include <stdio.h>
#include <string.h>

void init_dict(Dictionary *dict) { dict->size = 0; }

void insert_key_value_pair(Dictionary *dict, const char *key, int value) {
  if (dict->size >= MAX_DICTIONARY_SIZE) {
    printf("Dictionary is full, cannot insert more key-value pairs.\n");
    return;
  }
  KeyValuePair *pair = &dict->pairs[dict->size];
  strcpy(pair->key, key);
  pair->value = value;
  dict->size++;
}

int get_value_by_key(const Dictionary *dict, const char *key) {
  for (int i = 0; i < dict->size; i++) {
    if (strcmp(dict->pairs[i].key, key) == 0) {
      return dict->pairs[i].value;
    }
  }
  return -1000;
}

void print_all(Dictionary *dict) {
  for (int i = 0; i < dict->size; i++) {
    printf("%s %d \n", dict->pairs[i].key, dict->pairs[i].value);
  }
}
