#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct string
{
	size_t size;
	char*  data;
} string;

extern void 	string_init(string*, const char*);
extern void 	string_init_clear(string *str);
extern void 	string_free(string*);

extern char 	string_get(string*, size_t);
extern void		string_append(string*, const string*);
extern string*	string_concat(const string*, const string*);
extern bool 	string_compare(const string*, const string*);
extern void		string_copy(string*, const string*);
extern size_t 	string_length(const string*);

extern string*	string_substring(const string*, size_t, size_t);
extern size_t	string_find(const string*, const string*);
extern void		string_print(const string*);
