#include <stdio.h>
#include "sparse_array.h"
#include "omp.h"

sparse_array_t sparse_array_init(sparse_array_key_t keymax)
{
  const size_t sze=2;

  int i;
  sparse_array_t result;

  omp_init_lock( &result.lock );
  omp_set_lock ( &result.lock );

  result.n_elements   = 0L;
  result.size         = keymax >> map_shift;
  result.consolidated = 0;

  result.map = (cache_map_t_**) malloc( (result.size+1) * sizeof (cache_map_t_*) );
  if (result.map == NULL) {
      fprintf(stderr, "Failed to allocate sparse map.\n");
      exit(EXIT_FAILURE);
  }

/*
  #pragma omp parallel do default(none) shared(result,sze) private(i) schedule(static,512)
*/
  {
      for (i=0 ; i<result.size ; i++) {
          result.map[i] = cache_map_init(sze);
      }
  }

  result.sorted = 1;
  
  omp_unset_lock( &result.lock );
  return result;
}
