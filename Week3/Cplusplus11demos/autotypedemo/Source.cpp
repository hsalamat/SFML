#include <cstdio>
#include <string>
#include <typeinfo>
#include <iostream>
using namespace std;

string func() {
	return string("is a string");
}

int main(int argc, char ** argv) {
	
	//auto specifiers
	//For variables, specifies that the type of the variable that is being declared will be automatically deduced from its initializer. 
	//For functions, specifies that the return type is a trailing return type or will be deduced from its return statements (since C++14) 
	//for non-type template parameters, specifies that the type will be deduced from the argument 
	auto x = func();
	//std::basic_string::c_str Returns a pointer to a null-terminated character array 
	//with data equivalent to those stored in the string. 
	printf("x  %s\n", x.c_str());
	printf("type of x is a %s\n", typeid(x).name());
	cout << endl << x << endl;

	system("pause");
	return 0;
}