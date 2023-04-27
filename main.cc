#include <gsl_util>
#include "somelib.h"

int main()
{
	SOMETYPE *st = nullptr;
	int err;

	auto _ = gsl::finally([&st]{ sometype_destroy(st); });

	st = sometype_create();
	if (!st)
		return -1;

	err = sometype_do_something(st, 1);
	if (err < 0)
		return -2;

	err = sometype_do_something(st, 3);
	if (err < 0)
		return -3;

	return 0;
}
