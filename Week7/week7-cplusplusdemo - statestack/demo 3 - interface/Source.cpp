#include <iostream>
using namespace  std;

//how to create an interface in c++ using pure virtual function

class Interface
{
public:
	Interface() {}
	//virtual ~Interface() {}
	virtual void method1() = 0;    // "= 0" part makes this method pure virtual, and
								   // also makes this class abstract.
	virtual void method2() = 0;
};

class Concrete : public Interface
{
private:
	int myMember;

public:
	Concrete() {}
	~Concrete() {}
	void method1();
	void method2();
};

// Provide implementation for the first method
void Concrete::method1()
{
	// Your implementation
	cout << "this is my factory method 1" <<endl;
}

// Provide implementation for the second method
void Concrete::method2()
{
	// Your implementation
	cout << "this is my factory method 2" << endl;
}

int main(void)
{
	Interface *f = new Concrete();

	f->method1();
	f->method2();

	delete f;

	system("pause");
	return 0;
}