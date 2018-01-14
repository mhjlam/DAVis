#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "tuple.h"
#include "string.h"
#include "vector.h"

void tuple_test()
{
	printf("~~~ tuple ~~~\n");

	uintptr_t a[] = { 1, 2, 3, 4 };

	void* array[4];
	memcpy(array, a, sizeof(void*) * 4);

    tuple *t = tuple_new(array, 4);

    tuple_set(t, 2, (void*)1);
    tuple_erase(t, 1);
    tuple_erase(t, 3);

    for (int i = 0; i < t->size; i++)
    {
    	printf("%lu ", (uintptr_t) tuple_get(t, i));
    }
    printf("\n\n");

    tuple_free(t);
}

void vector_test()
{
	printf("~~~ vector ~~~\n");

    vector *v = vector_new();
    vector_push(v, "Bonjour");
    vector_push(v, "tout");
    vector_push(v, "le");
    vector_push(v, "monde");

    for (int i = 0; i < v->size; i++)
    {
    	printf("%s ", (char *) vector_get(v, i));
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
    printf("\n\n");

    vector_free(v);
}

void string_test()
{
    printf("~~~ string ~~~\n");

    string *s = string_new("string");

    printf("string = \"%s\"\n", string_get(s));
    printf("length: %llu\n\n", string_length(s));

    string_append(s, " test");
    printf("string = \"%s\"\n", string_get(s));
    printf("length: %llu\n\n", string_length(s));

    printf("string = \"%s\"\n", string_get(s));
    printf("string equals \"test\"? %s\n\n", string_compare(s, "test") ? "yes" : "no");
    string_set(s, "test");
    printf("string = \"%s\"\n", string_get(s));
    printf("string equals \"test\"? %s\n\n", string_compare(s, "test") ? "yes" : "no");

    string_set(s, "word1, word2");
    printf("string = \"%s\"\n", string_get(s));
    string *ss = string_substr(s, 7, 5);
    printf("substr(7,5) = \"%s\"\n", string_get(ss));
    printf("\n");

    string_free(s);
    s = string_new("salve mundi");
    printf("string = \"%s\"\n", string_get(s));
    printf("string contains \"mundi\"? %s\n", string_find(s, "mundi") != string_length(s) ? "yes" : "no");

    string_free(s);
}

int main(int argc, char *argv[])
{
	tuple_test();
	vector_test();
    string_test();

	return 0;
}
