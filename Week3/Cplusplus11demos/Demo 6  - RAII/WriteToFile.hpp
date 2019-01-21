#pragma once
#include <mutex>
#include <iostream>
#include <string> 
#include <fstream>
#include <stdexcept>
using namespace std;

void write_to_file(const string & message) {
	// mutex to protect file access (shared across threads)
	static mutex mutex;

	// lock mutex before accessing file
	lock_guard<std::mutex> lock(mutex);

	// try to open file
	ofstream file("example.txt");
	if (!file.is_open())
		throw runtime_error("unable to open file");

	// write message to file
	file << message << endl;

	// file will be closed 1st when leaving scope (regardless of exception)
	// mutex will be unlocked 2nd (from lock destructor) when leaving
	// scope (regardless of exception)
}

void bad()
{
	mutex m;
	m.lock();                    // acquire the mutex
	write_to_file("bad way of writing to file");   // if function throws an exception, the mutex is never released
	if (1) return; // early return, the mutex is never released
	m.unlock();                  // if bad() reaches this statement, the mutex is released
}

void good()
{
	mutex m;
	lock_guard<mutex> lk(m); // RAII class: mutex acquisition is initialization
	write_to_file("good way of writing to file");  // if function throws an exception, the mutex is released
	if (1) return;       // early return, the mutex is released
}


