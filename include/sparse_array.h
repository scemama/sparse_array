#ifndef SPARSE_ARRAY
#define SPARSE_ARRAY

#include <stdlib.h>
#include <omp.h>

typedef double             sparse_array_value_t     ;
typedef long           int sparse_array_key_t       ;
typedef unsigned short int cache_key_t_;

#define map_shift 15


static unsigned long map_mask = ((1 << map_shift)-1) ;


typedef struct {
    sparse_array_value_t*  value;
    cache_key_t_*          key;
    omp_lock_t             lock;
    size_t                 size;
    size_t                 n_elements;
    int                    sorted;
} cache_map_t_;


typedef struct {
    cache_map_t_**         map;
    sparse_array_value_t*  consolidated_value;
    cache_key_t_*          consolidated_key;
    sparse_array_key_t*    consolidated_idx;
    omp_lock_t             lock;
    size_t                 size;
    size_t                 n_elements;
    int                    sorted;
    int                    consolidated;
} sparse_array_t;



sparse_array_t  sparse_array_init  (sparse_array_key_t  keymax);
float           sparse_array_mb    (sparse_array_t      map);
cache_map_t_*   cache_map_init     (size_t              size);

#endif
