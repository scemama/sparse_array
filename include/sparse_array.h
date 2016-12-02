#ifndef SPARSE_ARRAY
#define SPARSE_ARRAY

#include <stdlib.h>
#include <omp.h>

typedef double             value_t_    ;
typedef unsigned short int cache_key_t_;
typedef unsigned long  int key_t_      ;

#define map_shift (-15)

static unsigned long map_mask = ((1 << -map_shift)-1) ;

typedef struct {
  value_t_*      value;
  cache_key_t_*  key;
  omp_lock_t     lock;
  size_t         map_size;
  size_t         n_elements;
  int            sorted;
} cache_map_t_;

typedef struct {
  cache_map_t_*  map;
  value_t_*      consolidated_value;
  cache_key_t_*  consolidated_key;
  key_t_*        consolidated_idx;
  omp_lock_t     lock;
  size_t         map_size;
  size_t         n_elements;
  int            sorted;
  int            consolidated;
} map_t_;

#endif
