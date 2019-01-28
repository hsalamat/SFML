#include "Submarine.h"
#include "ArmedFreighter.h"
#include <string>
#include <iostream>
using namespace std;

//this design called the diamond of death, where the base class "Entity" is indirectly inherited mutiple times
//Notice how class Submarine inherits from both ArmedEntity & DivingEntity.But both ArmedEntity & DivingEntity inherit from Entity classs.
//That will result in 2 copies of the class Entity being included in the vtable. vtable is a virtual table which has an array of pointers to virtual functions.
//vtable, or vftable is a mechanism used in a programming language to support dynamic dispatch (or run-time method binding).


int main()
{
	Submarine sub;

	//If there is a method in Entity that ArmedEntity & DivingEntity have overridden, and Submarine does not override it, 
	//then which version of the method does Submarine class inherit : that of ArmedEntity, or that of DivingEntity?
	//sub.setVelocity(1);

	system("pause");
	return 0;
}