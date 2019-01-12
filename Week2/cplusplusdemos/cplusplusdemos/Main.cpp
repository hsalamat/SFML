#include <string>
#include <iostream>
using namespace std;

#include "Box.hpp"
int main() {

	Box b(21, 32, 45);
	cout << "Volume: " << b.Volume() << endl;

	system("pause");
	return 0;
}