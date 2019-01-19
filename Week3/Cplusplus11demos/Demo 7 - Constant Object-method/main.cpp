#include "CL2.h"
int main()
{
	const CL2 co;
	CL2 o;

	co.const_method();  // legal
	//co.method();        // illegal, can't call regular method on const object
	o.const_method();   // legal, can call const method on a regulard object
	o.method();         // legal
	return 0;
}