#pragma once

#include <stddef.h>

typedef struct node
{
	struct node *prev;
	struct node *next;
	void        *data;
} node;

typedef struct list
{
	size_t size;
	node *front;
	node  *back;
} list;

extern void  list_init(list*);
extern void  list_free(list*);

extern node* list_get(list*, size_t);
extern node* list_find(list*, void*);
extern void  list_insert(node*, void*); // insert before node
extern void  list_remove(list*, node*);
extern void  list_remove_value(list*, void*);

extern void  list_push_back(list*, void*);
extern void  list_pop_back(list*);
extern void  list_push_front(list*, void*);
extern void  list_pop_front(list*);
