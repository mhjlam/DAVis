#include "vector.h"
#include <stdlib.h>

void vector_init(vector *v)
{
	v->size = 0;
	v->capacity = 0;
	v->data = NULL;
}

static void vector_resize(vector *v, int capacity)
{
	if (capacity < 0) return;

	void **data = realloc(v->data, sizeof(void*) * capacity);
	if (!data) return;
	
	v->data = data;
	v->capacity = capacity;
}

void vector_push(vector *v, void *item)
{
    if (v->capacity == v->size)
    {
    	int new_capacity = (v->capacity == 0) ? 1 : v->capacity * 2;
    	vector_resize(v, new_capacity);
    }

    v->data[v->size++] = item;
}

void vector_pop(vector *v)
{
	if (v->size < 1) return;

	v->size = v->size - 1;
	v->data[v->size] = NULL;

	if (v->size > 0 && v->size == v->capacity / 2)
	{
		vector_resize(v, v->capacity / 2);
	}
}

void vector_set(vector *v, int index, void *item)
{
	if (v == NULL) return;
	if (index < 0) return;
	if (index > v->size) return;

	v->data[index] = item;
}

void *vector_get(vector *v, int index)
{
	if (v == NULL) return NULL;
	if (index < 0) return NULL;
	if (index > v->size) return NULL;

	return v->data[index];	
}

void vector_erase(vector *v, int index)
{
	if (index < 0) return;
	if (index >= v->size) return;

	// remove element
	v->size = v->size - 1;
	v->data[index] = NULL;

	// shift remaining elements
	for (int i = index; i < v->size - 1; ++i)
	{
		v->data[i] = v->data[i + 1];
		v->data[i + 1] = NULL;
	}

	if (v->size > 0 && v->size == v->capacity / 2)
	{
		vector_resize(v, v->capacity / 2);
	}
}

void vector_free(vector *v)
{
	free(v->data);
}
