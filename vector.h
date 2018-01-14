#pragma once

#include <stddef.h>

typedef struct vector
{
	size_t size;
	size_t capacity;
	void **data;
} vector;

extern vector* 	vector_new();
extern void 	vector_free(vector*);
static void 	vector_resize(vector*, size_t);
extern void 	vector_push(vector*, void*);
extern void 	vector_pop(vector *v);
extern void 	vector_set(vector*, int, void*);
extern void* 	vector_get(vector*, int);
extern void 	vector_erase(vector*, int);
