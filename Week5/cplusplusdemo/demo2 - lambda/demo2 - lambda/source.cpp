//Lambda expression constructs a closure: an unnamed function object capable of capturing variables in scope.
//syntax: [ captures ] ( params ) -> ret { body }
//Syntax: [ captures ] ( params ) { body }
//Syntax: [ captures ] { body }
//Syntax: [ captures ] <tparams>(optional)(c++20) ( params ) specifiers exception attr -> ret requires(optional)(c++20) { body }
//The captures is a comma-separated list of zero or more captures, optionally beginning with the capture-default. The only capture defaults are

//& (implicitly capture the used automatic variables by reference) and
//= (implicitly capture the used automatic variables by copy).

#include <iostream>
using namespace std;

int main()
{
// generic lambda, operator() is a template with two parameters
auto glambda = [](auto a, auto b) { return a < b; };
bool boo = glambda(3, 3.14); // ok
cout << "is 3 less than 3.14? " << boo << endl;


//[]captures no variable: the capture list specifies to which variables in the surrounding scope the lambda expression has access.
auto p = [](auto v1, auto v2, auto v3) { cout << v1 << v2 << v3; };
p(1, 'a', 3.14); // outputs 1a3.14
cout << endl;


//[&]capture by reference: the capture list specifies to which variables in the surrounding scope the lambda expression has access.
int a = 0;
int b = 0;
auto g0 = [&, b](int c) mutable { a = ++b + c; };
g0(4);
cout << a << endl << b << endl;


//same as above: explicitly captures the variable n by value and implicitly captures the variable m by reference:
int m = 0;
int n = 0;
[&, n](int a) mutable { m = ++n + a; }(4);  //mutable allows you to modify a variable
cout << m << endl << n << endl;

int m1 = 0;
int n1 = 0;
[&, n1](int a)  { m1 = n1 + a; }(4);
cout << m1 << endl << n1 << endl;


//[=]capture by value: the capture list specifies to which variables in the surrounding scope the lambda expression has access.
int a1 = 0;
int b1 = 0;
auto g1 = [=](int c1) mutable { a1 = ++b1 + c1; cout << a1 << endl << b1 << endl; };
g1(4);
cout << a1 << endl << b1 << endl;


system("pause");
return 0;
}