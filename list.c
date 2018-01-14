#include "list.h"
#include <stdlib.h>

list *list_new()
{
	list *l = malloc(sizeof(struct list));
	l->size = 0;
	l->front = NULL;
	l->back = NULL;
	return l;
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

	free(l);
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

bool list_locate(list *l, node *n)
{
	if (l == NULL) return false;
	if (n == NULL) return false;

	node *m = l->front;

	while (m != NULL && m != n)
		m = m->next;

	return m != NULL;
}

void list_insert(list *l, node* n, void *value)
{
	if (l == NULL) return;
	if (n == NULL) return;

	node *m;
	m->next = n;
	m->prev = n->prev;
	m->data = value;

	n->prev = m;

	if (l->front == n) l->front = m;
	if (l->back == n) l->back = m;

	l->size++;
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

	l->size++;
}

void list_pop_back(list *l)
{
	if (l == NULL) return;
	if (l->back == NULL) return;

	list_remove(l, l->back);
}

void list_push_front(list *l, void *value)
{
	if (l == NULL) return;

	node *n;
	n->prev = NULL;
	n->next = (l->front) ? l->front : NULL;
	n->data = value;

	if (l->front) l->front->prev = n;
	else l->back = n; // if there is no front, there is no back either
	l->front = n;

	l->size++;
}

void list_pop_front(list *l)
{
	if (l == NULL) return;
	if (l->front == NULL) return;

	list_remove(l, l->front);
}
