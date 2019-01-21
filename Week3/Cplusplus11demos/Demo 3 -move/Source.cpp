// Demo 3 - movedemo.cpp : Defines the entry point for the console application.
// std::move is used to indicate that an object t may be "moved from", i.e. allowing the efficient transfer of resources from t to another object. 

#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str = "Hello";

	vector<string> v;

	// vector uses the push_back(const T&) overload, which means 
	// we'll incur the cost of copying str
	v.push_back(str);
	cout << "After copy, str is: " << str << endl;

	// std::move uses the rvalue reference push_back(T&&) overload, 
	// which means no strings will be copied; instead, the contents
	// of str will be moved into the vector.  This is less
	// expensive, but also means str is now empty.
	v.push_back(move(str));
	cout << "After move, str is: " << str << endl;

	cout << "The contents of the vector are " << v[0] << " & " << v[1] << endl;

	system("pause");
	return 0;
}

