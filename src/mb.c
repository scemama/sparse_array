#include "sparse_array.h"


/* Size in MiB of the sparse array */
float sparse_array_mb(sparse_array_t s)
{
  size_t i;
  long int result;

  result = sizeof(sparse_array_t);
  for (i=0 ; i<s.size ; i++) {
    result += sizeof(cache_map_t_) + s.map[i]->size * (sizeof(sparse_array_value_t)+sizeof(cache_key_t_));
  }
  return ((float) result)/(1024.*1024.);
}
