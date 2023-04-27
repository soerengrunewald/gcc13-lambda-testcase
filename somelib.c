#include "somelib.h"
#include <stdlib.h>
#include <string.h>

#define DEFAULTSIZE 10

struct TYPE {
	char data[DEFAULTSIZE];
};


SOMETYPE* sometype_create(void)
{
	return calloc(1, sizeof(struct TYPE));
}

void sometype_destroy(SOMETYPE* st)
{
	free(st);
}

int sometype_do_something(SOMETYPE* st, int what)
{
	struct TYPE* t = (struct TYPE*)st;
	if (t) {
		memset(&t->data, what, DEFAULTSIZE);
		t->data[DEFAULTSIZE-1] = 0;
		return 0;
	}
	return -1;
}

const char* sometype_to_string(SOMETYPE* st, const char* prefix)
{
	static char buf[256];
	struct TYPE* t = (struct TYPE*)st;
	char* ptr = NULL;

	if (t) {
		memset(buf, 0, sizeof(buf));
		ptr = strcpy(buf, prefix);

		for (int i=0; i!=DEFAULTSIZE; ++i) {
			*ptr++ = t->data[i] + 'a';
		}
	}
	buf[255] = 0;
	return buf;
}
