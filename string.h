#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct string
{
	size_t size;
	char*  data;
} string;

extern string* 		string_new(const char*);
extern string* 		string_init();
extern void 		string_free(string*);

extern void 		string_set(string*, const char*);
extern const char* 	string_get(const string*);
extern void			string_append(string*, const char*);
extern void			string_append_string(string*, const string*);
extern string*		string_concat(const string*, const char*);
extern string*		string_concat_string(const string*, const string*);
extern bool 		string_compare(const string*, const char*);
extern bool 		string_compare_string(const string*, const string*);
extern void			string_copy(string*, const string*);
extern size_t 		string_length(const string*);

extern string*		string_substr(const string*, size_t, size_t);
extern size_t		string_find(const string*, const char*);
extern size_t		string_find_string(const string*, const string*);
extern void 		string_print(const string*);
