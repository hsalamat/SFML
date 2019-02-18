#include "ParallelTask.hpp"


ParallelTask::ParallelTask()
	: mThread(&ParallelTask::runTask, this)
	, mFinished(false)
{
}

void ParallelTask::execute()
{
	mFinished = false;
	mElapsedTime.restart();
	mThread.launch();
}

bool ParallelTask::isFinished()
{
	sf::Lock lock(mMutex);
	return mFinished;
}

float ParallelTask::getCompletion()
{
	//What happens if an exception is thrown while a mutex is locked? It never gets a chance to be unlocked and remains locked forever.
	//All threads that try to lock it in the future will block forever, and in some cases, your whole application could freeze. Pretty bad result.
	//To make sure that mutexes are always unlocked in an environment where exceptions can be thrown, SFML provides an RAII class to wrap them: sf::Lock. 
	//It locks a mutex in its constructor, and unlocks it in its destructor. Simple and efficient.
	sf::Lock lock(mMutex);

	// 100% at 10 seconds of elapsed time
	return mElapsedTime.getElapsedTime().asSeconds() / 10.f;
}

//Because sf::Lock is a RAII compliant class, as soon as it goes out of scope and is destructed, the sf::Mutex object automatically unlocks.
void ParallelTask::runTask()
{
	// Dummy task - stall 10 seconds
	bool ended = false;
	while (!ended)
	{
		sf::Lock lock(mMutex); // Protect the clock 
		if (mElapsedTime.getElapsedTime().asSeconds() >= 10.f)
			ended = true;
	}

	{ // mFinished may be accessed from multiple threads, protect it
		sf::Lock lock(mMutex);
		mFinished = true;
	}
}

