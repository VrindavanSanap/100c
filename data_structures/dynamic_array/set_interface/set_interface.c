#include <stdio.h>
#include "../dynamic_array.h"
#include"set_interface.h"


struct set {
  void *data;
  size_t num_elements;
  size_t element_size;
};

set* set_build(dynamic_array* da){
  for (size_t i = 0; i < da_get_size(da); i++)  {


  }
}
bool set_find(set *s, void *element){


}