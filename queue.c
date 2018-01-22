#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        // allocate memory buffer with prefix
        char *strbuf = malloc(10 * sizeof(char));
        strcpy(strbuf, "queue = { ");

        // first node: get value and its length
        char temp[10];
        sprintf(temp, "%li", (intptr_t)q->front->data);

        // allocate buffer for integers
        char *content = malloc(strlen(temp) * sizeof(char));

        // add value to contents buffer
        strcpy(content, temp);

        struct queue_node *current = q->front->next;

        // for each node:
        while (current)
        {
            // allocate buffer for integer
            sprintf(temp, " ,%li", (intptr_t)current->data);
            content = realloc(content, strlen(content) + strlen(temp));

            // add value to contents buffer
            strcpy(content + strlen(content), temp);

            current = current->next;
        }

        // reverse content string
        int n = strlen(content);
        for (int i = 0; i < n/2; i++)
        {
            char t = content[n-i-1];
            content[n-i-1] = content[i];
            content[i] = t;
        }

        // append suffix
        strbuf = realloc(strbuf, 10 + strlen(content) + 2);
        strcpy(strbuf + 10, content);
        sprintf(temp, " }");
        strcpy(strbuf + strlen(strbuf), temp);

        // print final string
        printf("%s\n", strbuf);
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
