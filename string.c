#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_init(string *s, const char* data)
{
	s->size = strlen(data);
	s->data = (char*) malloc(s->size * sizeof(char));

	memcpy(s->data, data, s->size);
}

void string_init_clear(string *s)
{
	s->size = 0;
	s->data = (char*) calloc(1, sizeof(char));
	s->data[0] = '\0';
}

void string_free(string *s)
{
	free(s->data);
}

char string_get(string *s, size_t index)
{
	if (s == NULL) return '\0';
	if (index >= s->size) return '\0';

	return s->data[index];
}

void string_append(string *dst, const string *s)
{
	size_t sz = dst->size;
	dst->size += s->size;
	dst->data = (char*) realloc(dst->data, dst->size * sizeof(char));

	memcpy(dst->data + sz, s->data, s->size);
}

string*	string_concat(const string *s1, const string *s2)
{
	string *s = NULL;
	s->size = s1->size + s2->size;
	s->data = (char*) malloc(s->size * sizeof(char));

	memcpy(s->data, s1->data, s1->size);
	memcpy(s->data + s1->size, s2->data, s2->size);

	return s;
}

bool string_compare(const string *s1, const string *s2)
{
	return strcmp(s1->data, s2->data) == 0;
}

void string_copy(string *dst, const string *src)
{
	dst->size = src->size;
	dst->data = (char*) malloc(dst->size * sizeof(char));

	memcpy(dst->data, src->data, src->size);
}

size_t string_length(const string *s)
{
	return s->size;
}

string*	string_substring(const string *s, size_t pos, size_t count)
{
	if (pos + count >= s->size) return NULL;

	string *ss = NULL;
	ss->size = count + 1;
	ss->data = (char*) malloc(ss->size * sizeof(char));

	memcpy(ss->data, s->data + pos, count);
	ss->data[ss->size] = '\0';
	return ss;
}

size_t string_find(const string *s, const string* target)
{
	char* pos = strstr(s->data, target->data);

	if (pos == NULL) return s->size;
	return pos - s->data;
}

void string_print(const string *s)
{
	printf("%s", s->data);
}
