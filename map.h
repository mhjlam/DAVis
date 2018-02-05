#pragma once

#include <stddef.h>

typedef struct pair
{
    char        *key;
    void        *value;
    struct pair *next;
} pair;

typedef struct bucket
{
    size_t  size;
    pair  *pairs;
} bucket;

typedef struct map
{
    size_t  size;
    bucket *buckets;
} map;

extern map*     map_new();
extern void     map_free(map*);

extern void*    map_get(map*, const char*);
extern pair*    map_find(map*, const char*);
extern void     map_insert(map*, const char*, void*);
extern void     map_remove(map*, const char*);

extern void     map_print_s(map*);
extern void     map_print_i(map*);
extern void     map_format_i(map*, char**);
extern void     map_format_s(map*, char**);
