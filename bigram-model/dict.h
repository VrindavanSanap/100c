#ifndef DICTIONARY_H
#define DICTIONARY_H

#define MAX_DICTIONARY_SIZE 100

typedef struct
{
    char key[50];
    int value;
} KeyValuePair;

typedef struct
{
    KeyValuePair pairs[MAX_DICTIONARY_SIZE];
    int size;
} Dictionary;

void init_dict(Dictionary* dict);
void insert_key_value_pair(Dictionary* dict, const char* key, int value);
int get_value_by_key(const Dictionary* dict, const char* key);
void print_all(Dictionary* dict);
#endif
