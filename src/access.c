#include "sparse_array.h"
#include "sparse_array_private.h"

size_t  sparse_array_size (sparse_array_t s)
{
  return s.size;
}


size_t  sparse_array_n_elements (sparse_array_t s)
{
  return s.n_elements;
}


int  sparse_array_sorted (sparse_array_t s)
{
  return s.sorted;
}


int  sparse_array_consolidated (sparse_array_t s)
{
  return s.consolidated;
}


