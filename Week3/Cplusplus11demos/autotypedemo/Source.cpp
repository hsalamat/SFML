#include <cstdio>
#include <string>
#include <typeinfo>
#include <iostream>
using namespace std;

string func() {
	return string("is a string");
}

int main(int argc, char ** argv) {
	string y = "bye";
	auto x = func();
	//std::basic_string::c_str Returns a pointer to a null-terminated character array 
	//with data equivalent to those stored in the string. 
	printf("x  %s\n", x.c_str());
	printf("type of x is a %s\n", typeid(x).name());

	cout << "Press any key to continue: ";
	getline(cin, y);
	return 0;
}