#include "somelib.h"
#include <stdlib.h>
#include <string.h>

#define DEFAULTSIZE 10

SOMETYPE* sometype_create(void)
{
	return malloc(DEFAULTSIZE);
}

void sometype_destroy(SOMETYPE* st)
{
	free(st);
}

int sometype_do_something(SOMETYPE* st, int what)
{
	if (st) {
		memset(st, what, DEFAULTSIZE);
		return 0;
	}
	return -1;
}
