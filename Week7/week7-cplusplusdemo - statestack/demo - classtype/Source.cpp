#include "iostream"
using namespace std;

class A
{
public:
	void f() { cout << "f()\n"; }
};

int main()
{
	A a1; //this works
	A *a = new A(); 
	//a.f(); // "f has not been declared" Expression must have class type
	a->f();  //a->f notion is just a shorthand of (*a).f

	A& ref = a1;
	ref.f();


	A* ptr = new A();
	(*ptr).f();
	ptr->f();

	system("pause");
}