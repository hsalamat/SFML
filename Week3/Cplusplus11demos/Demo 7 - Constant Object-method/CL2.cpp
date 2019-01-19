#include "CL2.h"



void CL2::const_method() const
{
	//x = 3;   // illegal, can't modify a member in a const object
}

void CL2::method() 
{
	x = 3;   // illegal, can't modify a member in a const object
}


//A const method can be called on a const object