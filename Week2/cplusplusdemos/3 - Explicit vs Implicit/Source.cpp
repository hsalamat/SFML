#include <iostream>
using namespace std;

//The explicit function specifier controls unwanted implicit type conversions. It can only be used in declarations of constructors within a class declaration. 

//class complexNumbers {
//	double real, img;
//public:
//	//default constructor
//	complexNumbers() : real(0), img(0) { }
//
//	//copy constructor
//	complexNumbers(const complexNumbers& c) { real = c.real; img = c.img; }
//
//	//implicit conversion
//	complexNumbers(double r, double i = 0.0) { 
//		real = r; img = i; 
//		cout << "implicit conversion" << endl;
//	}
//
//
//	//friend function
//	friend void display(complexNumbers cx);
//};
//
//void display(complexNumbers cx) {
//	cout << "Real Part: " << cx.real << " Imag Part: " << cx.img << endl;
//}

class complexNumbers2 {
	double real, img;
public:
	complexNumbers2() : real(0), img(0) { }
	complexNumbers2(const complexNumbers2& c) { real = c.real; img = c.img; }
	explicit complexNumbers2(double r, double i = 0.0) { real = r; img = i; }
	friend void display2(complexNumbers2 cx);
};
void display2(complexNumbers2 cx) {
	cout << "Real Part: " << cx.real << " Imag Part: " << cx.img << endl;
}



int main() {
	//complexNumbers one(1);
	//complexNumbers five = 5; //copy assignment operator
	//display(one);
	//display(five);
	//display(300);  // Implicit conversion

	complexNumbers2 one(1);
	//complexNumbers2 five = 5; //copy assignment operator not allowed using explicit constructor
	display2(one);
	//display2(five);
	//display2(300);  // Implicit conversion not allowed


	system("pause");
	return 0;
}
