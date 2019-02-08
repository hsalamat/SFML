#include "Include/Player.hpp"
#include "Include/CommandQueue.hpp"
#include "Include/Aircraft.hpp"

#include <map>
#include <string>
#include <algorithm>


struct AircraftMover
{
	AircraftMover(float vx, float vy)
		: velocity(vx, vy)
	{
	}

	void operator() (Aircraft& aircraft, sf::Time) const
	{
		aircraft.accelerate(velocity);
	}

	sf::Vector2f velocity;
};

Player::Player()
{
	// Set initial key bindings
	mKeyBinding[sf::Keyboard::Left] = MoveLeft;
	mKeyBinding[sf::Keyboard::Right] = MoveRight;
	mKeyBinding[sf::Keyboard::Up] = MoveUp;
	mKeyBinding[sf::Keyboard::Down] = MoveDown;

#pragma region step2
	mJoystickBinding[sf::Joystick::Axis::X] = MoveDown;
	mJoystickBinding[sf::Joystick::Axis::Y] = MoveDown;
#pragma endregion

	// Set initial action bindings
	initializeActions();

	// Assign all categories to player's aircraft
	for (auto& pair : mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		// Check if pressed key appears in key binding, trigger command if so
		auto found = mKeyBinding.find(event.key.code);
		if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
			commands.push(mActionBinding[found->second]);
	}

#pragma region step3

	bool move = false;//indicate whether motion is detected
	int turbo = 1;//indicate whether player is using button for turbo speed ;)

				  //for movement
	sf::Vector2f speed = sf::Vector2f(0.f, 0.f);


	sf::Joystick::Identification id = sf::Joystick::getIdentification(0);
	//std::cout << controller;//easily tells us what controller is connected
	std::cout << "\nVendor ID: " << id.vendorId << "\nProduct ID: " << id.productId << std::endl;
	sf::String controller("Joystick Use: " + id.name);
	wcout << controller.toWideString() << endl;

	//std::cout uses char as character type, std::wcout uses wide character wchar_t as character type
	//char is used for narrow strings, suitable for 7-bit ASCII and 8-bit ANSI. wchar_t is used for wide strings, aka Unicode strings. However, the size of wchar_t is not portable, on some systems it is 16bit (suitable for UCS2/UTF-16), on others it is 32bit (suitable for UCS4/UTF-32). C++11 introduced new char16_t and char32_t types to deal with that descrepency

	if (sf::Joystick::isConnected(0)) {
		// check how many buttons joystick number 0 has
		unsigned int buttonCount = sf::Joystick::getButtonCount(0);

		// check if joystick number 0 has a Z axis
		bool hasZ = sf::Joystick::hasAxis(0, sf::Joystick::Z);

		std::cout << "Button count: " << buttonCount << std::endl;
		std::cout << "Has a z-axis: " << hasZ << std::endl;
	}

	if (event.type == sf::Event::JoystickMoved) {
		//move = true;
		//check state of joystick
		speed = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));

		std::cout << "X axis: " << speed.x << std::endl;
		std::cout << "Y axis: " << speed.y << std::endl;
	}


	if (sf::Joystick::isButtonPressed(0, 0)) {//"A" button on the XBox 360 controller
		//turbo = 2;
	}

	if (!sf::Joystick::isButtonPressed(0, 0)) {
		//turbo = 1;
	}

	if (sf::Joystick::isButtonPressed(0, 1)) {//"B" button on the XBox 360 controller

	}

	if (sf::Joystick::isButtonPressed(0, 2)) {//"X" button on the XBox 360 controller

	}

	for (auto pair : mJoystickBinding)
	{
		// If joystick button is pressed, lookup action and trigger corresponding command

		if (sf::Joystick::isButtonPressed(0, 2))
			commands.push(mActionBinding[pair.second]);
	}

#pragma endregion
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
	// Traverse all assigned keys and check if they are pressed
	for (auto pair : mKeyBinding)
	{
		// If key is pressed, lookup action and trigger corresponding command
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
	// Remove all keys that already map to action
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
	for (auto pair : mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}

	return sf::Keyboard::Unknown;
}

void Player::initializeActions()
{
	const float playerSpeed = 200.f;

	mActionBinding[MoveLeft].action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
	mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(+playerSpeed, 0.f));
	mActionBinding[MoveUp].action = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
	mActionBinding[MoveDown].action = derivedAction<Aircraft>(AircraftMover(0.f, +playerSpeed));
}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
	case MoveLeft:
	case MoveRight:
	case MoveDown:
	case MoveUp:
		return true;

	default:
		return false;
	}
}

