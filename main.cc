#include "somelib.h"

#include <gsl_util>
#include <iostream>
#include <string>

static std::string foo_me() {
	return "Foo Bar Baz!";
}


int main()
{
	auto const foo = foo_me();
	SOMETYPE *st = nullptr;
	std::string buf;
	int err;

	auto _ = gsl::finally([&st]{
		std::cout << "destroy ptr: " << st << "\n";
		sometype_destroy(st);
	});

	std::cout << "Creating ...\n";
	st = sometype_create();
	if (!st)
		return -1;

	std::cout << "created ptr: " << st << "\n";

	std::cout << "Something A ...\n";
	err = sometype_do_something(st, 1);
	if (err < 0)
		return -2;

	std::cout << "Something B ...\n";
	err = sometype_do_something(st, 3);
	if (err < 0)
		return -3;

	std::cout << "Print ...\n";
	buf = sometype_to_string(st, foo.c_str());
	std::cout << buf << std::endl;

	return 0;
}
