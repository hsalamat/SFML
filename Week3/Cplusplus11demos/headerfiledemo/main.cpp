#include <iostream>
using namespace std;
#include "MyClass.h"

int main() {
	int i;
	MyClass a;
	printf("Enter a number and plress enter: ");
	//scanf works like a pointer
	cin >> i;
	cout << i;
	return 0;
}