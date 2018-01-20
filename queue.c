#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()
{
    queue *q = malloc(sizeof(struct queue));
    q->size = 0;
    q->back = NULL;
    q->front = NULL;
    return q;
}

void queue_free(queue *q)
{
    free(q);
}

void queue_enqueue(queue *q, void *data)
{
    if (q == NULL) return;

    struct queue_node *n = malloc(sizeof(struct queue_node));
    n->next = NULL;
    n->data = data;

    if (q->front == NULL)
    {
        q->front = n;
        q->back = n;
    }
    else
    {
        q->back->next = n;
        q->back = n;
    }

    q->size++;
}

void* queue_peek(queue *q)
{
    if (q == NULL) return NULL;
    if (q->front == NULL) return NULL;
    return q->front->data;
}

void* queue_dequeue(queue *q)
{
    if (q == NULL) return NULL;
    if (q->front == NULL) return NULL;

    void *data = q->front->data;

    if (q->front->next)
    {
        queue_node *next = q->front->next;
        free(q->front);
        q->front = next;
    }
    else
    {
        free(q->front);
        q->front = NULL;
    }

    q->size--;
    return data;
}

void queue_print_i(queue *q) // todo: queue must be printed in reversed order
{
    if (q == NULL) return;

    if (q->front == NULL)
    {
        printf("queue = {}\n");
    }
    else
    {
        printf("queue = { %li", (intptr_t)q->front->data);
        struct queue_node *current = q->front->next;
        while (current)
        {
            printf(", %li", (intptr_t)current->data);
            current = current->next;
        }
        printf(" }\n");
    }
}

void queue_print_s(queue *q)
{
    if (q == NULL) return;

    if (q->front == NULL)
    {
        printf("queue = {}\n");
    }
    else
    {
        printf("queue = { %s", (char*)q->front->data);
        struct queue_node *current = q->front->next;
        while (current)
        {
            printf(", %s", (char*)current->data);
            current = current->next;
        }
        printf(" }\n");
    }
}

void queue_format_i(queue *q, char **format)
{
    if (q == NULL) return;
}

void queue_format_s(queue *q, char **format)
{
    if (q == NULL) return;
}
