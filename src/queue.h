#pragma once

#include <stddef.h>

typedef struct queue_node
{
    struct queue_node *next;
    void              *data;
} queue_node;

typedef struct queue
{
    size_t             size;
    struct queue_node *back;
    struct queue_node *front;
} queue;

extern queue*   queue_new();
extern void     queue_free(queue*);

extern void     queue_enqueue(queue*, void*);
extern void*    queue_peek(queue*);     // get front without deletion
extern void*    queue_dequeue(queue*);  // get front and delete

extern void     queue_print_i(queue*);
extern void     queue_print_s(queue*);
extern void     queue_format_i(queue*, char**);
extern void     queue_format_s(queue*, char**);
