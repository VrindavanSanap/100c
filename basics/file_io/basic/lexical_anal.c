#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 128

int total_words = 0;

struct HashNode
{
    char key;
    int value;
    struct HashNode* next;
};

struct HashTable
{
    struct HashNode* table[TABLE_SIZE];
};

struct HashNode* createHashNode(char key, int value)
{
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    if (newNode == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(char key)
{
    return (int)key % TABLE_SIZE;
}

void insert(struct HashTable* ht, char key, int value)
{
    int index = hashFunction(key);

    struct HashNode* newNode = createHashNode(key, value);

    if (ht->table[index] == NULL)
    {
        ht->table[index] = newNode;
    }
    else
    {
        free(ht->table[index]);
        ht->table[index] = newNode;
    }
}

int get(struct HashTable* ht, char key)
{
    int index = hashFunction(key);
    struct HashNode* current = ht->table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void printHashTable(struct HashTable* ht)
{
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct HashNode* current = ht->table[i];
        printf("[%d]: ", i);
        while (current != NULL)
        {
            printf("(%c, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}
void print_lexical_anal(struct HashTable* ht)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct HashNode* current = ht->table[i];
        while (current != NULL)
        {
            char c = current->key;
            int n = current->value;
            printf("Number of words starting with %c is %d (%.2f %)\n", c, n,
                (((float)n) / (float)total_words) * 100);
            current = current->next;
        }
    }
}
void freeHashTable(struct HashTable* ht)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        struct HashNode* current = ht->table[i];
        while (current != NULL)
        {
            struct HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht);
}

int main(int argc, char* argv[])
{
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    if (ht == NULL)
    {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        ht->table[i] = NULL;
    }
    char word[100];
    char* file_name = argv[1];
    FILE* file = fopen(file_name, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    while (fscanf(file, "%99s", word) == 1)
    {
        total_words++;
        int res = get(ht, word[0]);
        if (res == -1)
        {
            insert(ht, word[0], 1);
        }
        else
        {
            insert(ht, word[0], res + 1);
        }
    }
    print_lexical_anal(ht);
    freeHashTable(ht);
    return 0;
}
