/* assert example */
#include <stdio.h>      /* printf */
#include <assert.h>     /* assert */
#include <iostream>
#include <string>

void print_number(int* myInt) {
	assert(myInt != NULL);
	printf("%d\n", *myInt);
}

int main()
{
	int a = 10;
	int * b = NULL;
	int * c = NULL;

	b = &a;

	print_number(b);
	print_number(c);

	std::string y = "bye";
	std::cout << "Press any key to continue: ";
	getline(std::cin, y);

	return 0;
}