#pragma once

#include <stddef.h>

typedef struct stack_node
{
    struct stack_node *next;
    void              *data;
} stack_node;

typedef struct stack
{
    size_t            size;
    struct stack_node *top;
} stack;

extern stack*   stack_new();
extern void     stack_free(stack*);

extern void     stack_push(stack*, void*);
extern void*    stack_peek(stack*); // get top without deletion
extern void*    stack_pop(stack*);  // get top and delete

extern void     stack_print_i(stack*);
extern void     stack_print_s(stack*);
extern void     stack_format_i(stack*, char**);
extern void     stack_format_s(stack*, char**);
