#include "tuple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tuple_init(tuple *t, void** data, int size)
{
	t->size = size;
	t->data = malloc(sizeof(void*) * size);
	memcpy(t->data, data, sizeof(void*) * size);
}

void tuple_set(tuple *t, int index, void *item)
{
	if (t == NULL) return;
	if (index < 0) return;
	if (t->size == 0) return;
	if (index > t->size) return;

	t->data[index] = item;
}

void* tuple_get(tuple *t, int index)
{
	if (t == NULL) return NULL;
	if (index < 0) return NULL;
	if (t->size == 0) return NULL;
	if (index > t->size) return NULL;

	return t->data[index];
}

void tuple_erase(tuple *t, int index)
{
	if (index < 0) return;
	if (t->size == 0) return;
	if (index >= t->size) return;

	t->data[index] = NULL;
}

void tuple_free(tuple *t)
{
	free(t->data);
}
