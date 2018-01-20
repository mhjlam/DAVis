#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct node
{
	struct node *prev;
	struct node *next;
	void        *data;
} node;

typedef struct list
{
	size_t       size;
	struct node *head;
	struct node *tail;
} list;

extern list*    list_new();
extern void     list_free(list*);

extern node*    list_get(list*, size_t);
extern node*    list_find(list*, void*);
extern bool     list_locate(list*, node*); // is node in list
extern void     list_insert(list*, node*, void*); // insert before node
extern void     list_remove(list*, node*);

extern void     list_push_back(list*, void*);
extern void     list_pop_back(list*);
extern void     list_push_front(list*, void*);
extern void     list_pop_front(list*);

extern void     list_print_i(list*);
extern void     list_print_s(list*);
extern void     list_format_i(list*, char**);
extern void     list_format_s(list*, char**);
