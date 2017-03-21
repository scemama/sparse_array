#ifndef SPARSE_ARRAY
#define SPARSE_ARRAY

#include <stdlib.h>
#include <omp.h>

typedef double             sparse_array_value_t     ;
typedef long           int sparse_array_key_t       ;
typedef unsigned short int cache_key_t_;


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


/* Create a new sparse array */
sparse_array_t  sparse_array_create  (sparse_array_key_t keymax);

/* Compute the size in MiB of the sparse array */
float  sparse_array_mb (sparse_array_t map);

/* Physical size (memory allocation) of the sparse array */
size_t  sparse_array_size (sparse_array_t s);

/* Logical size (number of elements) of the sparse array */
size_t  sparse_array_n_elements (sparse_array_t s);

/* Get the sorted status of the sparse array */
int  sparse_array_sorted (sparse_array_t s);

/* Get the consolidated status of the sparse array */
int  sparse_array_consolidated (sparse_array_t s);


#endif
