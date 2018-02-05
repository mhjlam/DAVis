#include "vector.h"
#include <stdlib.h>

vector *vector_new()
{
	vector *v = malloc(sizeof(struct vector));
	v->size = 0;
	v->capacity = 0;
	v->data = NULL;
	return v;
}

void vector_free(vector *v)
{
	free(v->data);
	free(v);
}

static void vector_resize(vector *v, size_t capacity)
{
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

void vector_set(vector *v, size_t index, void *item)
{
	if (v == NULL) return;
	if (index < 0) return;
	if (v->size == 0) return;
	if (index > v->size) return;

	v->data[index] = item;
}

void *vector_get(vector *v, size_t index)
{
	if (v == NULL) return NULL;
	if (index < 0) return NULL;
	if (v->size == 0) return NULL;
	if (index > v->size) return NULL;

	return v->data[index];
}

void vector_erase(vector *v, size_t index)
{
	if (index < 0) return;
	if (v->size == 0) return;
	if (index >= v->size) return;

	// remove element
	v->size = v->size - 1;
	v->data[index] = NULL;

	// shift remaining elements
	for (size_t i = index; i < v->size - 1; ++i)
	{
		v->data[i] = v->data[i + 1];
		v->data[i + 1] = NULL;
	}

	if (v->size > 0 && v->size == v->capacity / 2)
	{
		vector_resize(v, v->capacity / 2);
	}
}

void vector_print(vector *v)
{

}

const char *vector_format(vector *v)
{
	//char *str = malloc(v->size * sizeof(char));
	//memcpy(str, v->data);
	return "";
}
