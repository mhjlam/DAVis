#include "list.h"
#include <stdlib.h>

void list_init(list *l)
{
	l->size = 0;
	l->front = NULL;
	l->back = NULL;
}

void list_free(list *l)
{
	if (l->size == 0) return;

	node* n = l->front;

	while (n != NULL)
	{
		list_remove(l, n);
		n = n->next;
	}
}

node* list_get(list *l, size_t index)
{
	if (l->size == 0) return NULL;

	size_t i = 0;
	node *n = l->front;

	while (n != NULL && i != index)
	{
		n = n->next;
		i++;
	}

	return n;
}

node* list_find(list *l, void *value)
{
	return NULL;
}

void list_insert(node *n, void *value)
{

}

void list_remove(list *l, node *n)
{
	if (l->size == 0) return;

	if (l->front == n) l->front = n->next;
	if (l->back == n) l->back = n->prev;

	if (n->prev) n->prev->next = n->next;
	if (n->next) n->next->prev = n->prev;

	l->size--;
	free(n->data);
}

void list_remove_value(list *l, void *value)
{

}

void list_push_back(list *l, void *value)
{
	if (l == NULL) return;

	node *n;
	n->prev = (l->back) ? l->back : NULL;
	n->next = NULL;
	n->data = value;

	if (l->back) l->back->next = n;
	else l->front = n; // if there is no back, then there is no front either
	l->back = n;
}

void list_pop_back(list *l)
{
	if (l == NULL) return;
}

void list_push_front(list *l, void *value)
{
	if (l == NULL) return;
}

void list_pop_front(list *l)
{
	if (l == NULL) return;
}
