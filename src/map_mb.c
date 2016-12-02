#include "sparse_array.h"


float map_mb(sparse_array_t map)
{
  size_t i;
  long int result;

  result = sizeof(map_t_);
  for (i=0 ; i<map.size ; i++)
    result += sizeof(cache_map_t_) + map.map[i].size * (sizeof(value_t_)+sizeof(cache_key_t_));
  return ((float) result)/(1024.*1024.);
}
