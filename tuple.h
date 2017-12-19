#pragma once

typedef struct tuple
{
	int    size;
	void** data;
} tuple;

extern void  tuple_init(tuple*, void**, int);
extern void  tuple_set(tuple*, int, void*);
extern void* tuple_get(tuple*, int);
extern void  tuple_erase(tuple*, int);
extern void  tuple_free(tuple*);
