#include <stdio.h>
#include "dict.h"

Dictionary stoi()
{
    Dictionary dict;
    init_dict(&dict);
    int i = 0;
    char alpha_i[2];
    for (char alpha = 'a'; alpha <= 'z'; alpha++)
    {
        alpha_i[0] = alpha;
        alpha_i[1] = '\0';
        insert_key_value_pair(&dict, alpha_i, ++i);
    }
    char point = '.';
    alpha_i[0] = point;
    alpha_i[1] = '\0';
    insert_key_value_pair(&dict, alpha_i, ++i);
    return dict;
}
