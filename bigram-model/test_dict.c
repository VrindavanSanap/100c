#include "dict.h"
#include <stdio.h>

int main()
{
    Dictionary dict;
    init_dict(&dict);

    insert_key_value_pair(&dict, "temp", 10);
    insert_key_value_pair(&dict, "hash", 29);
    insert_key_value_pair(&dict, "yeet", 31);

    int temp = get_value_by_key(&dict, "temp");
    int hash = get_value_by_key(&dict, "hash");
    printf("temp = %d, hash = %d\n", temp, hash);
    print_all(&dict);

    return 0;
}
