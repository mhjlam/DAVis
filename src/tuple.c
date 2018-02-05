#include "tuple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tuple *tuple_new(void **data, size_t size)
{
	tuple *t = malloc(sizeof(struct tuple));
	t->size = size;
	t->data = malloc(sizeof(void*) * size);
	memcpy(t->data, data, sizeof(void*) * size);
	return t;
}

void tuple_free(tuple *t)
{
	free(t->data);
	free(t);
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

void tuple_print(tuple *t)
{
	if (t == NULL) return;

	if (t->size == 0)
	{
		printf("{ }\n");
	}
	else if (t->size == 1)
	{
		printf("{ %s }\n", t->data[0]);
	}
	else
	{
		printf("{ %s", (char*)t->data[0]);
		for (int i = 1; i < t->size; ++i)
		{
			printf(", %s", t->data[i]);
		}
		printf(" }\n");
	}
}

const char* tuple_format(tuple *t)
{
	return "";
}
