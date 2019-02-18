#include "ParallelTask.hpp"
#include <iostream>
#include <SFML\Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

//Mutex stands for "MUTual EXclusion": it ensures that only a single thread is able to run the code that it guards. 
sf::Mutex mutex;

//every time you run this, you will get different result!

// example 1: non member function with one argument
void threadFunc(int argument)
{
	cout << "non member function with one argument " << endl; 
	for (int i = 0; i < 10; ++i)
		cout << "I'm thread number one " << endl;

	//the only way to pause a thread is to do it from the code that it runs
	sf::sleep(sf::seconds(10));
}


void threadFunc2()
{
	mutex.lock();
	for (int i = 0; i < 10; ++i)
		cout << "I'm thread with mutex " << i << endl;

	mutex.unlock();
}

class Task1
{
public:
	void run()
	{		
		cout << "member function " << endl;
		for (int i = 0; i < 10; ++i)
			cout << "I'm thread number two " << endl;
	}
};

struct Task2
{
	void operator()() {
		cout << "functor " << endl;
		for (int i = 0; i < 10; ++i)
			cout << "I'm thread number three " << endl;
	}
};


bool func()
{
	sf::Lock lock(mutex); // mutex.lock()

	sf::Texture texture;

		if (!texture.loadFromFile("texture.png"))
		return false; // mutex.unlock()

		if (!texture.loadFromFile("texture.png"))
		return false; // mutex.unlock()

		if (!texture.loadFromFile("texture.png"))
		return false; // mutex.unlock()

	return true;
	// mutex.unlock()
} 


int main() {

	///this section doesn't use ParallelTask class

	sf::Thread thread1(&threadFunc, 5);
	thread1.launch(); // start the thread (internally calls threadFunc(5))

	cout << "starting threadwithmutex1 " << endl;
	sf::Thread threadwithmutex1(&threadFunc2);
	threadwithmutex1.launch(); // start the thread (internally calls threadFunc2())

	//notice this thread doesn't really start still the other thread is done with locking 
	cout << "starting threadwithmutex2 " << endl;
	sf::Thread threadwithmutex2(&threadFunc2);
	threadwithmutex2.launch(); // start the thread (internally calls threadFunc2())

	cout << "starting threadloadtexture " << endl;
	sf::Thread threadloadtexture(&func);
	threadloadtexture.launch(); // start the thread (internally calls func())

	Task1 task;
	sf::Thread thread2(&Task1::run, &task);
	thread2.launch(); // start the thread (internally calls task.run())

	Task2 task2;
	sf::Thread thread3(task2);
	thread3.launch(); // start the thread (internally calls operator() on the Task instance)


	// block execution until the thread is finished
	thread1.wait();

	///end of the section

	//Let's try the same thing using ParallelTask -a fake task that takes 10 seconds
	ParallelTask task3;
	task3.execute();

	ParallelTask task4;
	task4.execute();

	//Let's keep the main program wait till task 3 to be completed
	while (!task3.isFinished())
	{
		//cout << "task 4 is in " << task4.getCompletion() * 10 << " seconds " << endl;
	}


	if (task3.isFinished())
	{
		// 100% at 10 seconds of elapsed time
		cout << "task 3 is " << task3.getCompletion()* 10 << " seconds and complete " << endl;

		cout << "task 4 is in " << task4.getCompletion() * 10 << " seconds " << endl;
	}


	system("pause");
	return 0;
}