#ifndef SPARSE_ARRAY_PRIVATE
#define SPARSE_ARRAY_PRIVATE

#define map_shift 15

static unsigned long map_mask = ((1 << map_shift)-1) ;

cache_map_t_*  cache_map_init (size_t size);

#endif
