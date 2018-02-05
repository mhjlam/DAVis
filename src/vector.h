#pragma once

#include <stddef.h>

typedef struct vector
{
    size_t size;
    size_t capacity;
    void **data;
} vector;

extern vector*      vector_new();
extern void         vector_free(vector*);
extern void         vector_push(vector*, void*);
extern void         vector_pop(vector *v);
extern void         vector_set(vector*, size_t, void*);
extern void*        vector_get(vector*, size_t);
extern void         vector_erase(vector*, size_t);

extern void         vector_print(vector*);
extern const char*  vector_format(vector*);
