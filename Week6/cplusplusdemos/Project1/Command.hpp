#pragma once
#include "Category.hpp"

#include <SFML/System/Time.hpp>

#include <functional>
#include <cassert>

class SceneNode;

struct Command
{
	Command();

	std::function<void(SceneNode&, sf::Time)>	action;
	unsigned int								category;
};


//An adapter helps with downcasting entities derived from SceneNode
template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
{
	return [=](SceneNode& node, sf::Time dt)
	{
		//Safely converts pointers and references to classes up, down, and sideways along the inheritance hierarchy.
		//dynamic_cast is almost exclusively used for handling polymorphism. You can cast a pointer or reference to any polymorphic type to any other class type 
		assert(dynamic_cast<GameObject*>(&node) != nullptr);

		// Downcast node and invoke function on it
		fn(static_cast<GameObject&>(node), dt);
	};
}