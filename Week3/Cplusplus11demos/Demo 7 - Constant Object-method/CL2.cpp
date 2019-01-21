#include "CL2.h"
#include <iostream>
using namespace std;


void CL2::const_method() const
{
	//x = 3;   // illegal, can't modify a member in a const object
	cout << "calling constant method" << endl;
}

void CL2::method() 
{
	x = 3;   
	cout << "calling a regular method" << endl;
}


//A const method can be called on a const object