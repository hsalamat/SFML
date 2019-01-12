#include <string>
#include <iostream>
using namespace std;

#include "Box2.hpp"
#include "complexNumber.hpp"

int main() {

	//it is possible to initialize a Box like this when it's not explicit
	//Box2 b1 = 42;
	Box2 b2(12);
	Box2 boxes[3]{ {1,2,3},{4,5,6},{7,8,9} };

	//cout << "Volume of b1: " << b1.Volume() << endl;
	cout << "Volume of b2: " << b2.Volume() << endl;
	cout << "Volume of boxes[0]: " << boxes[0].Volume() << endl;
	cout << "Volume of boxes[1]: " << boxes[1].Volume() << endl;
	cout << "Volume of boxes[2]: " << boxes[2].Volume() << endl;
	
	complexNumber one(1);
	display(one);

	//you can't do the following - if you have an explicit construcotr!!
	complexNumber five = 5;
	display(five);
	display(300);  //==> Implicit conversion

	display(complexNumber(200));  //only explicit conversion is allowed



	system("pause");

	return 0;
}

void display(complexNumber cx) {
	cout << "Real Part : "<< cx.real << " Imag Part : " << cx.img << endl;
}
