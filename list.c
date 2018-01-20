#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list *list_new()
{
	list *l = malloc(sizeof(struct list));
	l->size = 0;
	l->head = NULL;
	l->tail = NULL;
	return l;
}

void list_free(struct list *l)
{
	if (l->size == 0) return;

	struct node* n = l->head;

	while (n != NULL)
	{
		list_remove(l, n);
		n = n->next;
	}

	free(l);
}

struct node* list_get(struct list *l, size_t index)
{
	if (l->size == 0) return NULL;

	size_t i = 0;
	struct node *n = l->head;

	while (n != NULL && i != index)
	{
		n = n->next;
		i++;
	}

	return (i < l->size) ? n : NULL;
}

struct node* list_find(struct list *l, void *value)
{
	if (l == NULL) return false;

	struct node *m = l->head;

	while (m != NULL && m->data != value)
		m = m->next;

	return m;
}

bool list_locate(list *l, node *n)
{
	if (l == NULL) return false;
	if (n == NULL) return false;

	struct node *m = l->head;

	while (m != NULL && m != n)
		m = m->next;

	return m != NULL;
}

void list_insert(list *l, node* n, void *value)
{
	if (l == NULL) return;
	if (n == NULL) return;

	struct node *m = malloc(sizeof(struct node));
	m->next = n;
	m->prev = n->prev;
	m->data = value;

	n->prev = m;
	m->prev->next = m;

	if (l->head == n) l->head = m;
	if (l->tail == n) l->tail = m;

	l->size++;
}

void list_remove(list *l, node *n)
{
	if (l->size == 0) return;

	if (l->head == n) l->head = n->next;
	if (l->tail == n) l->tail = n->prev;

	if (n->prev) n->prev->next = n->next;
	if (n->next) n->next->prev = n->prev;

	l->size--;
	free(n);
}

void list_push_back(list *l, void *value)
{
	if (l == NULL) return;

	struct node *n = malloc(sizeof(struct node));
	n->prev = NULL;
	n->next = NULL;
	n->data = value;

	if (l->tail)
	{
		n->prev = l->tail;
		l->tail->next = n;
	}

	l->tail = n;	
	l->size++;

	if (l->head == NULL) l->head = n;
}

void list_pop_back(list *l)
{
	if (l == NULL) return;
	if (l->tail == NULL) return;

	list_remove(l, l->tail);
}

void list_push_front(list *l, void *value)
{
	if (l == NULL) return;

	struct node *n = malloc(sizeof(struct node));
	n->prev = NULL;
	n->next = NULL;
	n->data = value;

	if (l->head)
	{
		n->next = l->head;
		l->head->prev = n;
	}

	l->head = n;
	l->size++;

	if (l->tail == NULL) l->tail = n;
}

void list_pop_front(list *l)
{
	if (l == NULL) return;
	if (l->head == NULL) return;

	list_remove(l, l->head);
}

void list_print_i(list *l)
{
	if (l == NULL) return;

	if (l->size > 0)
    {
        printf("list = { %li", (intptr_t)l->head->data);
        struct node *current = l->head->next;
        while (current)
        {
            printf(", %li", (intptr_t)current->data);
            current = current->next;
        }
        printf(" }\n");
    }
}

void list_print_s(list *l)
{
	if (l == NULL) return;

	if (l->size > 0)
    {
        printf("list = { %s", (char*)l->head->data);
        struct node *current = l->head->next;
        while (current)
        {
            printf(", %s", (char*)current->data);
            current = current->next;
        }
        printf(" }\n");
    }
}

void list_format_i(list *l, char **format)
{
	*format = calloc(2 + 10 * l->size + 3, sizeof(char));
	strcat(*format, "{ ");

	if (l->size > 0)
    {
    	char d[10];
    	sprintf(d, "%li", (intptr_t)l->head->data);
    	strcat(*format, d);

        struct node *n = l->head->next;
        while (n)
        {
        	char d[10];
        	sprintf(d, ", %li", (intptr_t)n->data);
        	strcat(*format, d);
            n = n->next;
        }
    }

 	strcat(*format, " }");
}

void list_format_s(list *l, char **format)
{
	*format = calloc(2 + 64 * l->size + 3, sizeof(char));
	strcat(*format, "{ ");

	if (l->size > 0)
    {
    	char d[64];
    	sprintf(d, "%s", (char*)l->head->data);
    	strcat(*format, d);

        struct node *n = l->head->next;
        while (n)
        {
        	char d[64];
        	sprintf(d, ", %s", (char*)n->data);
        	strcat(*format, d);
            n = n->next;
        }
    }

 	strcat(*format, " }");
}
