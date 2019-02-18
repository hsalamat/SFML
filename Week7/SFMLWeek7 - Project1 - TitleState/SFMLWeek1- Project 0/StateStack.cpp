#pragma region step 5
#include "Include/StateStack.hpp"

#include <cassert>


StateStack::StateStack(State::Context context)
	: mStack()
	, mPendingList()
	, mContext(context)
	, mFactories()
{
}

void StateStack::update(sf::Time dt)
{
	// Iterate from top to bottom, stop as soon as update() returns false
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if (!(*itr)->update(dt))
			break;
	}

	//after an update iteration is complete (when it's safe), then add or remove a state, not in the middle of an update iteration by the stack.
	applyPendingChanges();
}

void StateStack::draw()
{
	// Draw all active states from bottom to top! this allows the states are transparant, and you will be seeing the underlying screens (imagine Pause screen!)
	//If you do not want to see previous screen, use sf::ReactangleShape to draw a colored screen over the whole screen!
	for (State::Ptr& state : mStack)
		state->draw();
}

//Every polled event is fed to the state stack. Then internally, the stack will deliver the event to active states
void StateStack::handleEvent(const sf::Event& event)
{
	// Iterate from top to bottom (remeber it's a stack: top means last state!), stop as soon as handleEvent() returns false
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if (!(*itr)->handleEvent(event))
			break;
	}

	//after an event iteration is complete (when it's safe), then add or remove a state, not in the middle of an event iteration by the stack!
	applyPendingChanges();
}

void StateStack::pushState(States::ID stateID)
{
	mPendingList.push_back(PendingChange(Push, stateID));
}

void StateStack::popState()
{
	mPendingList.push_back(PendingChange(Pop));
}


void StateStack::clearStates()
{
	mPendingList.push_back(PendingChange(Clear));
}

bool StateStack::isEmpty() const
{
	return mStack.empty();
}

State::Ptr StateStack::createState(States::ID stateID)
{
	auto found = mFactories.find(stateID);
	assert(found != mFactories.end());

	return found->second();
}

void StateStack::applyPendingChanges()
{
	for (PendingChange change : mPendingList)
	{
		switch (change.action)
		{
		case Push:
			mStack.push_back(createState(change.stateID));
			break;

		case Pop:
			mStack.pop_back();
			break;

		case Clear:
			//completely empty the active stack!
			mStack.clear();
			break;
		}
	}

	mPendingList.clear();
}

StateStack::PendingChange::PendingChange(Action action, States::ID stateID)
	: action(action)
	, stateID(stateID)
{
}

#pragma endregion

