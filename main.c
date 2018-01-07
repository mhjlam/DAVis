#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "tuple.h"
#include "vector.h"

void tuple_test()
{
	printf("~~~ tuple ~~~\n");

	uintptr_t a[] = { 1, 2, 3, 4 };

	void* array[4];
	memcpy(array, a, sizeof(void*) * 4);

    tuple t;
    tuple_init(&t, array, 4);

    tuple_set(&t, 1, (void*)3);
    tuple_erase(&t, 3);

    for (int i = 0; i < t.size; i++)
    {
    	printf("%lu ", (uintptr_t) tuple_get(&t, i));
    }
    printf("\n");

    tuple_free(&t);
    printf("\n");
}

void vector_test()
{
	printf("~~~ vector ~~~\n");

    vector v;
    vector_init(&v);

    vector_push(&v, "Bonjour");
    vector_push(&v, "tout");
    vector_push(&v, "le");
    vector_push(&v, "monde");

    for (int i = 0; i < v.size; i++)
    {
    	printf("%s ", (char *) vector_get(&v, i));
    }
    printf("\n");

    vector_erase(&v, 3);
	vector_pop(&v);
    vector_pop(&v);

    vector_set(&v, 0, "Hello");
    vector_push(&v, "World");

    for (int i = 0; i < v.size; i++)
    {
    	printf("%s ", (char*) vector_get(&v, i));
    }
    printf("\n");

    vector_free(&v);
    printf("\n");
}

int main(int argc, char *argv[])
{
	tuple_test();
	vector_test();

	return 0;
}
