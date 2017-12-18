#pragma once

typedef struct vector
{
	int size;
	int capacity;
	void **data;
} vector;

extern void  vector_init(vector*);
static void  vector_resize(vector*, int);
extern void  vector_push(vector*, void *);
extern void  vector_pop(vector *v);
extern void  vector_set(vector*, int, void *);
extern void* vector_get(vector*, int);
extern void  vector_erase(vector*, int);
extern void  vector_free(vector*);
