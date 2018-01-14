#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string *string_new(const char *data)
{
	string *s = malloc(sizeof(struct string));
	s->size = strlen(data);
	s->data = malloc((s->size + 1) * sizeof(char));
	memcpy(s->data, data, s->size);
	s->data[s->size] = '\0';
	return s;
}

string *string_init()
{
	string *s = malloc(sizeof(struct string));
	s->size = 0;
	s->data = calloc(1, sizeof(char));
	s->data[0] = '\0';
	return s;
}

void string_free(string *s)
{
	free(s->data);
	free(s);
}

void string_set(string* s, const char *data)
{
	s->size = strlen(data);
	s->data = realloc(s->data, (s->size + 1) * sizeof(char));
	memcpy(s->data, data, s->size);
	s->data[s->size] = '\0';
}

const char *string_get(const string *s)
{
	return s->data;
}

void string_append(string *dst, const char *s)
{
	size_t sz = dst->size;
	dst->size += strlen(s);
	dst->data = (char*) realloc(dst->data, dst->size * sizeof(char));
	memcpy(dst->data + sz, s, strlen(s));
}

void string_append_string(string *dst, const string *s)
{
	size_t sz = dst->size;
	dst->size += s->size;
	dst->data = (char*) realloc(dst->data, dst->size * sizeof(char));
	memcpy(dst->data + sz, s->data, s->size);
}

string *string_concat(const string *s1, const char* s2)
{
	string *s = malloc(sizeof(struct string));
	s->size = s1->size + strlen(s2);
	s->data = malloc(s->size * sizeof(char));

	memcpy(s->data, s1->data, s1->size);
	memcpy(s->data + s1->size, s2, strlen(s2));

	return s;
}

string *string_concat_string(const string *s1, const string *s2)
{
	string *s = NULL;
	s->size = s1->size + s2->size;
	s->data = malloc(s->size * sizeof(char));

	memcpy(s->data, s1->data, s1->size);
	memcpy(s->data + s1->size, s2->data, s2->size);

	return s;
}

bool string_compare(const string *s1, const char *s2)
{
	return strcmp(s1->data, s2) == 0;
}

bool string_compare_string(const string *s1, const string *s2)
{
	return strcmp(s1->data, s2->data) == 0;
}

void string_copy(string *dst, const string *src)
{
	dst->size = src->size;
	dst->data = malloc(dst->size * sizeof(char));

	memcpy(dst->data, src->data, src->size);
}

size_t string_length(const string *s)
{
	return s->size;
}

string*	string_substr(const string *s, size_t pos, size_t count)
{
	if (pos + count > s->size) return NULL;

	string *ss = malloc(sizeof(struct string));
	ss->size = count;
	ss->data = malloc((ss->size + 1) * sizeof(char));

	memcpy(ss->data, s->data + pos, count);
	ss->data[ss->size] = '\0';
	return ss;
}

size_t string_find(const string *s, const char* target)
{
	char* pos = strstr(s->data, target);

	if (pos == NULL) return s->size;
	return pos - s->data;
}

size_t string_find_string(const string *s, const string* target)
{
	char* pos = strstr(s->data, target->data);

	if (pos == NULL) return s->size;
	return pos - s->data;
}

void string_print(const string *s)
{
	printf("%s\n", s->data);
}
