#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
/*
    Gives unique characters and their count;
*/
struct Set
{
    char elements[MAX_SIZE];
    int size;
};
bool contains(struct Set* set, int value)
{
    for (int i = 0; i < set->size; ++i)
    {
        if (set->elements[i] == value)
        {
            return true;
        }
    }
    return false;
}
int add(struct Set* set, char element)
{
    if (!contains(set, element))
    {
        if (set->size < MAX_SIZE)
        {
            set->elements[set->size++] = element;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return 0;
    }
}
int remove_element(struct Set* set, char element)
{
    for (int i = 0; i < set->size; i++)
    {
        if (set->elements[i] == element)
        {
            for (int j = i; j < set->size - 1; ++j)
            {
                set->elements[j] = set->elements[j + 1];
            }
            set->size--;
            return 1;
        }
    }
    return 0;
}
void print_set(struct Set* set)
{
    printf("Set with %d elements: ", set->size);
    printf("{ ");
    for (int i = 0; i < set->size; ++i)
    {
        printf("%c ", set->elements[i]);
    }
    printf("}\n");
}

void init_set(struct Set* set)
{
    set->size = 0;
}
int main()
{
    FILE* file;
    char ch;
    file = fopen("quote.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file\n");
        return -1;
    }
    struct Set my_set;
    init_set(&my_set);
    while ((ch = fgetc(file)) != EOF)
    {
        add(&my_set, ch);
    }
    print_set(&my_set);
    fclose(file);
    return 0;
}
