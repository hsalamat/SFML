#include <iostream>
#include <typeinfo>
#include <set>
#include <memory>
#include <string>
using namespace std;
class Foo {
public:
	int aNumber;
	Foo(int a) {
		aNumber = a;
		cout << "Foo constructed with aNumber =" << a << endl;
	}
	~Foo() {
		cout << "Foo is destructed " << aNumber <<
			endl;
	}

};

void myfunc() {
	auto a = 5;
	auto pa = &a;
	cout << typeid(a).name() << endl;
	cout << typeid(pa).name() << endl;

	// Create a set of strings
	set<string> st;
	st.insert({ "geeks", "for", "geeks", "org" });

	// 'it' evaluates to iterator to set of string
	// type automatically
	for (auto it = st.begin(); it != st.end(); it++)
		cout << *it << " ";

		cout << endl;

	Foo foo(30);

	std::unique_ptr<Foo> p(new Foo(42));
	p->aNumber = 50;
	foo.aNumber = 60;
	cout << "destructor for unique pointer calls first" << endl;


	//unique pointer is not copyable
	//unique_ptr<Foo> foo2 = p;

	unique_ptr<Foo> foo2 = std::move(p);
	foo2->aNumber = 70;

	if (!p)cout << "unique pointer object p is empty" << endl;
}
int main() {
	myfunc();
	std::string y = "bye";
	std::cout << "Press any key to continue: ";
	getline(std::cin, y);
	return 0;
}