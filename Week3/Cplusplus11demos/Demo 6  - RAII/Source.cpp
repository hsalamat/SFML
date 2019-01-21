// Demo 5 - RAII demo.cpp : Defines the entry point for the console application.
//RAII: Resource acquisition is initialization - the resource is guaranteed to be held between when initialization finishes and finalization starts, and to be held only when the object is alive. 


// The C++ library classes that manage their own resources follow RAII : std::string, std::vector, std::thread, 
//and many others acquire their resources in constructors(which throw exceptions on errors), 
//release them in their destructors(which never throw), and don't require explicit cleanup. 
//In addition, the standard library offers several RAII wrappers to manage user - provided resources :
//std::unique_ptr and std::shared_ptr to manage dynamically - allocated memory or , with a user - provided deleter, 
//any resource represented by a plain pointer;
//std::lock_guard, std::unique_lock, std::shared_lock to manage mutexes.

#include <cstdio>
#include "WriteToFile.hpp"

									  // if good() returns normally, the mutex is released
int main()
{
	write_to_file("this is a test");
	good(); //try bad() to see what happens
	puts("Hello World!");
	system("pause");
	return 0;
}