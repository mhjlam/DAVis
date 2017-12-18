#include <stdio.h>
#include "vector.h"

int main(int argc, char *argv[])
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
    	printf("%s ", (char *) vector_get(&v, i));
    }
    printf("\n");

    vector_free(&v);

	return 0;
}
