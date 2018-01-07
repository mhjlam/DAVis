#pragma once

#include <stddef.h>

typedef struct tuple
{
	size_t size;
	void** data;
} tuple;

extern void  tuple_init(tuple*, void**, size_t);
extern void  tuple_free(tuple*);
extern void  tuple_set(tuple*, int, void*);
extern void* tuple_get(tuple*, int);
extern void  tuple_erase(tuple*, int);
