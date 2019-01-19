#include <iostream>
#include <memory>
#include <string>

using namespace std;

//std::unique_ptr is a smart pointer that owns and manages another object through a pointer 
//and disposes of that object when the unique_ptr goes out of scope. 
struct Foo
{
	Foo() { std::cout << "Foo::Foo\n"; }
	~Foo() { std::cout << "Foo::~Foo\n"; }
	void bar() { std::cout << "Foo::bar\n"; }
};

void f(const Foo &)
{
	std::cout << "f(const Foo&)\n";
}

int main()
{
	string y = "bye";
	std::unique_ptr<Foo> p1(new Foo);  // p1 owns Foo
	if (p1) p1->bar();

	{
		std::unique_ptr<Foo> p2(std::move(p1));  // now p2 owns Foo
		f(*p2);

		p1 = std::move(p2);  // ownership returns to p1
		std::cout << "destroying p2...\n";
	}

	if (p1) p1->bar();

	// Foo instance is destroyed when p1 goes out of scope
	cout << "Press any key to continue: ";
	getline(cin, y);

	return 0;
}