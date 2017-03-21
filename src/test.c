#include "sparse_array.h"
#include <stdio.h>

int main(int argc, char** argv) {

  sparse_array_t      s;
  sparse_array_key_t  key;
  int test;

  key = 20*20*20*20;
  s = sparse_array_create(key);
  test = 0;
  printf("sparse_array_init...\t");
  if (sparse_array_size(s) != 4) test++;
  if (sparse_array_n_elements(s) != 0) test++;
  if (sparse_array_sorted(s) != 1) test++;
  if (sparse_array_consolidated(s) != 0) test++;

  if ( test == 0 )
     printf(" [     OK     ]\n");
  else
     printf(" [ Failed: %d ]\n",test);
  return 0;
}
