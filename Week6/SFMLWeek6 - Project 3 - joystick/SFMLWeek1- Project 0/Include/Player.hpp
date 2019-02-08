#pragma once
#include "Command.hpp"
#include <SFML/Window/Event.hpp>
#include <map>

#pragma region step 1-1
#include <iostream>
using namespace std;
#pragma endregion

class CommandQueue;

class Player
{
public:
	Player();

	void					handleEvent(const sf::Event& event, CommandQueue& commands);
	void					handleRealtimeInput(CommandQueue& commands);

	enum Action
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		ActionCount
	};
	void					assignKey(Action action, sf::Keyboard::Key key);
	sf::Keyboard::Key		getAssignedKey(Action action) const;

private:
	void					initializeActions();
	static bool				isRealtimeAction(Action action);

private:
	std::map<sf::Keyboard::Key, Action>		mKeyBinding;
	std::map<Action, Command>				mActionBinding;

#pragma region step 1-2
	std::map<sf::Joystick::Axis, Action>		mJoystickBinding;
#pragma endregion
};

