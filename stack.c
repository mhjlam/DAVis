#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new()
{
    stack *s = malloc(sizeof(struct stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

void stack_free(stack *s)
{
    free(s);
}

void stack_push(stack *s, void *data)
{
    if (s == NULL) return;

    struct stack_node *n = malloc(sizeof(struct stack_node));
    n->next = s->top;
    n->data = data;

    s->top = n;
    s->size++;
}

void* stack_peek(stack *s)
{
    if (s == NULL) return NULL;
    if (s->top == NULL) return NULL;
    return s->top->data;
}

void* stack_pop(stack *s)
{
    if (s == NULL) return NULL;
    if (s->top == NULL) return NULL;

    void *data = s->top->data;

    if (s->top->next)
    {
        stack_node *next = s->top->next;
        free(s->top);
        s->top = next;
    }
    else
    {
        free(s->top);
        s->top = NULL;
    }

    s->size--;
    return data;
}

void stack_print_i(stack *s)
{
    if (s == NULL) return;
    
    if (s->top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack = %li\n", (intptr_t)s->top->data);
        struct stack_node *current = s->top->next;
        while (current)
        {
            printf("        %li\n", (intptr_t)current->data);
            current = current->next;
        }
    }
}

void stack_print_s(stack *s)
{
    if (s == NULL) return;

    if (s->top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack = %s\n", (char*)s->top->data);
        struct stack_node *current = s->top->next;
        while (current)
        {
            printf("        %s\n", (char*)current->data);
            current = current->next;
        }
    }
}

void stack_format_i(stack *s, char **format)
{
    if (s == NULL) return;
}

void stack_format_s(stack *s, char **format)
{
    if (s == NULL) return;
}
