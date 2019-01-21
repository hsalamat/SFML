//void assert (int expression);
//If the argument "expression" of this macro with functional form compares equal to zero(i.e., the expression is false), 
//a message is written to the standard error device and abort is called, terminating the program execution.
//If NDEBUG is defined as a macro name at the point in the source code where <assert.h> is included, then assert does nothing.

#include <stdio.h>      /* printf */

// uncomment to disable assert() 
//#define NDEBUG
#include <assert.h>     /* assert */

#include <iostream>
#include <string>
using namespace std;

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

	system("pause");

	return 0;
}