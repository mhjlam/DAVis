#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_init(string *str, const char* data)
{
	if (str == NULL) return;

	str->size = strlen(data);
	str->data = (char*) malloc(str->size * sizeof(char));

	memcpy(str->data, data, str->size);
}

void string_init_clear(string *str)
{
	if (str == NULL) return;

	str->size = 0;
	str->data = (char*) calloc(1, sizeof(char));
	str->data[0] = '\0';
}

void string_free(string *str)
{
	free(str->data);
}

char string_get(string *str, size_t index)
{
	if (str == NULL) return '\0';
	if (index >= str->size) return '\0';

	return str->data[index];
}

void string_append(string *dst, const string *str)
{
	size_t sz = dst->size;
	dst->size += str->size;
	dst->data = (char*) realloc(dst->data, dst->size * sizeof(char));

	memcpy(dst->data + sz, str->data, str->size);
}

string*	string_concat(const string *str1, const string *str2)
{
	string *str = NULL;
	str->size = str1->size + str2->size;
	str->data = (char*) malloc(str->size * sizeof(char));

	memcpy(str->data, str1->data, str1->size);
	memcpy(str->data + str1->size, str2->data, str2->size);

	return str;
}

bool string_compare(const string *str1, const string *str2)
{
	return strcmp(str1->data, str2->data) == 0;
}

void string_copy(string *dst, const string *src)
{
	dst->size = src->size;
	dst->data = (char*) malloc(dst->size * sizeof(char));

	memcpy(dst->data, src->data, src->size);
}

size_t string_length(const string *str)
{
	return str->size;
}

string*	string_substring(const string *src, size_t pos, size_t count)
{
	if (pos + count >= src->size) return NULL;

	string *str = NULL;
	str->size = count + 1;
	str->data = (char*) malloc(str->size * sizeof(char));

	memcpy(str->data, src->data + pos, count);
	str->data[str->size] = '\0';
	return str;
}

size_t string_find(const string *str, const string* target)
{
	char* pos = strstr(str->data, target->data);

	if (pos == NULL) return str->size;
	return pos - str->data;
}

void string_print(const string *str)
{
	printf("%s", str->data);
}
