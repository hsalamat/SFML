#include <random>
#include <iostream>
#include <memory>
#include <functional>
#include <string>
using namespace std;

struct Command {
	Command(int x) : mX(x) {}
	void launchMissile(float target) { std::cout << "Missile is launched from Command center - target = " << target << '\n'; }
	int mX;
};

void launchMissile(int target)
{
	std::cout << "Missile is launched from regular function - target = " << target << '\n';
}

//A functor is  a class which defines the operator().That lets you create objects which "look like" a function :  unlike regular functions, they can contain state.
//Since `LaunchMissile` defines `operator()`, it can be used as a function
struct LaunchMissile {
	void operator()(float target)
	{
		std::cout << "Missile is launched from operator - target = " << target << '\n';
	}
};



int main()
{

	// store a free function
	std::function<void(int)> launchM1 = launchMissile;
	std::cout << "store a free function:  ";
	launchM1(-9);

	// store a lambda
	std::function<void()> launchM2 = []() {
		std::cout << "store a lambda:  " ; 
		launchMissile(42); };
	launchM2();


	//Here, std::function allows you to abstract away exactly what kind of callable object it is you are dealing with — you don't know it's LaunchMissile, 
	//you just know that it returns void and has one float parameter.
	LaunchMissile func;
	std::function<void(float)> f(func);
	f(3);

	// store the result of a call to std::bind. The function template bind generates a forwarding call wrapper for launchMissile . 
	//Calling this wrapper is equivalent to invoking launchMissile with some of its arguments bound to args. 
	std::function<void()> launchM31337 = std::bind(launchMissile, 31337);
	std::cout << "store the result of the call to std::bind  ";
	launchM31337();

	// store a call to a member function
	std::function<void(Command&, int)> launchM3 = &Command::launchMissile;
	std::cout << "store a call to member function:  ";
	Command command(314159);
	launchM3(command, 1);

	// store a call to a data member accessor
	std::function<int(Command &)> callCommandmX = &Command::mX;
	std::cout << "store a call to a data member accessor:  ";
	std::cout << "mX: " << callCommandmX(command) << '\n';

	// store a call to a member function and object
	using std::placeholders::_1;
	std::function<void(int)> launchM4 = std::bind(&Command::launchMissile, command, _1);
	std::cout << "store a call to member function and object:  ";
	launchM4(2);

	// store a call to a member function and object ptr
	std::function<void(int)> launchM5 = std::bind(&Command::launchMissile, &command, _1);
	std::cout << "store a call to member function and object ptr:  ";
	launchM5(3);

	// store a call to a function object
	std::function<void(int)> launchM6 = LaunchMissile();
	launchM6(18);


	// demonstrates argument reordering and pass-by-reference

	system("pause");
}


