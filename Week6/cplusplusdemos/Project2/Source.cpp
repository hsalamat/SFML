#include <functional>
#include <iostream>
#include <string>
using namespace std;


class Aircraft
{
public:
	void moveLeft() 
	{
		cout << "Aircraft Moving Left..." << endl;
	}

	void moveRight()
	{
		cout << "Aircraft Moving Right..." << endl;
	}
};


class SceneNode {
public:
	void moveLeft()
	{
		cout << "Node Moving Left..." << endl;
	}

	void moveRight()
	{
		cout << "Node Moving Right..." << endl;
	}
};

template <typename T>
class Command
{
public:
	std::function<void(T&)> action;
};

class Command2
{
public:
	std::function<void(SceneNode&)> action;
};


int main(void)
{
	Aircraft a;
	Command<Aircraft> b;
	b.action = &Aircraft::moveLeft;
	b.action(a);

	b.action = &Aircraft::moveRight;
	b.action(a);


	SceneNode node;
	Command2 c;
	c.action = &SceneNode::moveLeft;
	c.action(node);

	c.action = &SceneNode::moveRight;
	c.action(node);


	system("pause");

	return 0;
}