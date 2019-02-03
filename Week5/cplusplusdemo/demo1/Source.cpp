//std::array is a container that encapsulates fixed size arrays.
//This container is an aggregate type with the same semantics as a struct holding a C-style array T[N] as its only non-static data member. 
//Unlike a C-style array, it doesn't decay to T* automatically.
//A C-Style array is just a "naked" array - that is, an array that's not wrapped in a class
//a "C++ style array" is  a wrapper class like std::vector (or std::array) that provides handy capabilities like bounds checking and size information.

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main() {

	//c-style array
	int a1[] = { 5,2,3 };
	// ranged for loop is supported
	for (const auto& n : a1)
		std::cout << n << ' ';
	
		cout << "the array size is " << sizeof(a1) / sizeof(int) << endl;

	//sort(a1.begin(), a1.end()); in old school array you can't use sort!


	array<int, 3> a2 = { 5, 2, 3 };
	sort(a2.begin(), a2.end());
	for (const auto& n : a2)
		std::cout << n << ' ';
	cout << "the array size is " << a2.size() << endl;


	//std::ostream_iterator is a single-pass LegacyOutputIterator that writes successive objects of type T into the std::basic_ostream object for which it was constructed, using operator<<. 
	reverse_copy(a2.begin(), a2.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl;

	array<string, 2> a3 = { string("a"), "b" };
	for (const auto& s : a3)
		cout << s << ' ';
	
	cout << endl;

	system("pause");

	return 0;
}