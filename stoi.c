#include <stdio.h>
#include "dict.h"
int main(){
    Dictionary dict;
    init_dict(&dict);
    int temp = get_value_by_key(&dict, "temp");
    int hash = get_value_by_key(&dict, "hash");
    char alpha;
    int i = 0;
    char alpha_i[1];
    for (alpha = 'a'; alpha <= 'z'; alpha++){
        alpha_i[0] = alpha;
        insert_key_value_pair(&dict, alpha_i, ++i);
    }
    char point = '.';
    alpha_i[0] = point;
    insert_key_value_pair(&dict, alpha_i, ++i);
    print_all(&dict);
    return 0;
}
