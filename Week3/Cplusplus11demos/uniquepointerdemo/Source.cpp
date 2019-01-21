//std::unique_ptr is a smart pointer that owns and manages another object through a pointer 
//and disposes of that object when the unique_ptr goes out of scope. 
#include <iostream>
#include <memory>
#include <string>

using namespace std;


//The  difference between a struct and class in C++ is the default accessibility of member variables and methods.
//In a struct they are public; in a class they are private.
struct Foo
{
	Foo() { cout << "Foo::Foo\n"; }
	~Foo() { cout << "Foo::~Foo\n"; }
	void bar() { cout << "Foo::bar\n"; }
};

void f(const Foo &)
{
	cout << "f(const Foo&)\n";
}

int main()
{
	unique_ptr<Foo> p1(new Foo);  // p1 owns Foo
	if (p1) p1->bar();


	unique_ptr<Foo> p2(move(p1));  // now p2 owns Foo
	f(*p2);

	p1 = move(p2);  // ownership returns to p1
	cout << "destroying p2...\n";

	if (p1) p1->bar();

	// Foo instance is destroyed when p1 goes out of scope
	system("pause");

	return 0;
}