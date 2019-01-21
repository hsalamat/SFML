// Function templates are special functions that can operate with generic types. 
//This allows us to create a function template whose functionality can be adapted to more than one type or class without repeating the entire code for each type.
#include <iostream>
#include <string>
using namespace std;

template <class T>
T GetMax(T a, T b) {
	T result;
	//a ternary operator is an operator that takes three arguments.
	result = (a>b) ? a : b;  
	return (result);
}

template <typename T>
T GetMaxTypeName (T a, T b)
{
	T result;
	result = (a > b) ? a : b;
	return result;
}

int GetMaxOld(int a, int b)
{
	int result;
	result = (a > b) ? a : b;
	return result;
}

//the difference between typename and class: 
//typename is used to declare when you are referencing a nested type that depends on another template parameter, such as the typedef 
template<typename param_t>
class Foo
{
	typedef typename param_t::baz sub_t;
};

//A typename keyword tells the compiler that an identifier is a type not a static member
template <class T> struct S {
	typename T::type i;
};

int main() {

	int i = 5, j = 6, k;
	long l = 10, m = 5, n;

	cout << "function template using class" << endl;

	k = GetMax<int>(i, j);
	n = GetMax<long>(l, m);

	cout << k << endl;
	cout << n << endl;

	cout << "function template using typename" << endl;

	k = GetMaxTypeName<int>(i, j);
	n = GetMaxTypeName<long>(l, m);

	cout << k << endl;
	cout << n << endl;

	system("pause");

	return 0;
}
