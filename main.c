#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "tuple.h"
#include "vector.h"
#include "string.h"
#include "list.h"
#include "queue.h"
#include "stack.h"

void tuple_test()
{
	printf("\n~~~ tuple ~~~\n");

    tuple *t = tuple_new((void*)(uintptr_t[]){1,2,3,4}, 4);

    tuple_set(t, 2, (void*)1);  // 3 becomes 1
    tuple_erase(t, 1);          // 2 becomes 0
    tuple_erase(t, 3);          // 4 becomes 0
                                // t = { 1, 0, 1, 0 }

    for (int i = 0; i < t->size; i++)
    {
    	printf("%lu ", (uintptr_t)tuple_get(t, i));
    }
    printf("\n");

    tuple_free(t);
}

void vector_test()
{
	printf("\n~~~ vector ~~~\n");

    vector *v = vector_new();
    vector_push(v, "Bonjour");
    vector_push(v, "tout");
    vector_push(v, "le");
    vector_push(v, "monde");

    for (int i = 0; i < v->size; i++)
    {
    	printf("%s ", (char*)vector_get(v, i));
    }
    printf("\n");

    vector_erase(v, 3);
	vector_pop(v);
    vector_pop(v);

    vector_set(v, 0, "Hello");
    vector_push(v, "World");

    for (int i = 0; i < v->size; i++)
    {
    	printf("%s ", (char*)vector_get(v, i));
    }
    printf("\n");

    vector_free(v);
}

void string_test()
{
    printf("\n~~~ string ~~~\n");

    string *s = string_new("string");

    printf("string = \"%s\"\n", string_format(s));
    printf("length: %llu\n\n", string_length(s));

    string_append(s, " test");
    printf("string = \"%s\"\n", string_format(s));
    printf("length: %llu\n\n", string_length(s));

    printf("string = \"%s\"\n", string_format(s));
    printf("string equals \"test\"? %s\n\n", string_compare(s, "test") ? "yes" : "no");
    string_set(s, "test");
    printf("string = \"%s\"\n", string_format(s));
    printf("string equals \"test\"? %s\n\n", string_compare(s, "test") ? "yes" : "no");

    string_set(s, "word1, word2");
    printf("string = \"%s\"\n", string_format(s));
    string *ss = string_substr(s, 7, 5);
    printf("substr(7,5) = \"%s\"\n", string_format(ss));
    printf("\n");

    string_free(s);
    s = string_new("salve mundi");
    printf("string = \"%s\"\n", string_format(s));
    printf("string contains \"mundi\"? %s\n", string_find(s, "mundi") != string_length(s) ? "yes" : "no");

    string_free(s);
}

void list_test()
{
    printf("\n~~~ list ~~~\n");

    list *l = list_new();

    printf("push back & front:\n");
    list_push_back(l,  (void*)6);
    list_push_front(l, (void*)5);
    list_push_back(l,  (void*)7);
    list_push_front(l, (void*)3);
    list_push_front(l, (void*)2);
    list_push_front(l, (void*)1);
    list_push_back(l, (void*)8);
    list_print_i(l);

    printf("\npop back, front, back:\n");
    list_pop_back(l);
    list_pop_front(l);
    list_pop_back(l);
    list_print_i(l);

    printf("\nfind node with value 5 and insert 4 before:\n");
    list_insert(l, list_find(l, (void*)5), (void*)4);
    list_print_i(l);

    printf("\nget and then remove second element:\n");
    node *n = list_get(l, 1);
    printf("list(1) = %li\n", (n) ? (intptr_t)n->data : -1);
    list_remove(l, n);
    list_print_i(l);

    list_free(l);
}

void queue_test()
{
    printf("\n~~~ queue ~~~\n");

    queue *q = queue_new();
    queue_enqueue(q, (void*)1);
    queue_enqueue(q, (void*)2);
    queue_enqueue(q, (void*)3);
    queue_print_i(q);

    queue_free(q);
}

void stack_test()
{
    printf("\n~~~ stack ~~~\n");

    stack *s = stack_new();
    stack_push(s, (void*)1);
    stack_push(s, (void*)2);
    stack_push(s, (void*)3);
    stack_print_i(s);

    stack_free(s);
}

int main(int argc, char *argv[])
{
	tuple_test();
	vector_test();
    string_test();
    list_test();
    queue_test();
    stack_test();

	return 0;
}
