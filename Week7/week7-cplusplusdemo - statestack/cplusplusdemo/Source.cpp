#include <map>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

namespace States
{
	enum ID
	{
		None,
		Title,
		Menu,
		Game,
		Loading,
		Pause,
		Video
	};
}

class StateStack;


class State
{
public:
	typedef std::unique_ptr<State> Ptr;

	struct Context
	{
		Context(string commonstuff);
		//Common things between screens
		/*sf::RenderWindow*	window;
		TextureHolder*		textures;
		FontHolder*			fonts;
		Player*				player;*/
	};

	State(StateStack& stack, Context context)
		: mStack(&stack)
		, mContext(context)
	{
	}

	virtual void draw() = 0;
private:
	StateStack * mStack;
	Context				mContext;
};

State::Context::Context(string commonstuff)
{
	cout << "the common thing for all the states" << endl;
}

class StateStack
{
	std::vector<State::Ptr>								mStack;
	std::map<States::ID, std::function<State::Ptr()>>	mFactories; //we store our factory method using std::function factory, which returns the std::unqiue_ptr to the State base class
	State::Context												mContext;
public:

	explicit StateStack(State::Context context)
		: mStack()
		, mContext(context)
		, mFactories()
	{
	}
	template <typename T>
	void				registerState(States::ID stateID);
	State::Ptr			createState(States::ID stateID);

	void				registerTitleState();
	void				registerVideoState();
};



class TitleState : public State
{
public:
	TitleState(StateStack& stack, Context context) : State(stack, context) {}
	void draw() {
		cout << "Title screen is called when state is created not registered!" << endl;
	}
};

class VideoState : public State
{
public:
	VideoState(StateStack& stack, Context context) : State(stack, context) {}
	void draw() {
		cout << "Video screen is called when state is created not registered!" << endl;
	}
};

void StateStack::registerTitleState() {

	//A* ptr = new A();
	//TitleState* ptr = new TitleState(*this, mContext);

	mFactories[States::Title] = [this]() {
		//unique_ptr<TitleState> ptr1(new TitleState(*this, mContext));
		//return ptr1;		
		return State::Ptr(new TitleState(*this, mContext));
	};
}

void StateStack::registerVideoState() {
	mFactories[States::Video] = [this]() {
		
		return State::Ptr(new TitleState(*this, mContext));
	};
}


//how to use the template to reduce coding. We can replace the above two methods by the following method!
//StateStack doesn't need to know the concrete state class!
template <typename T>
void StateStack::registerState(States::ID stateID)
{
	mFactories[stateID] = [this]()
	{
		return State::Ptr(new T(*this, mContext));
	};
}

State::Ptr StateStack::createState(States::ID stateID)
{
	auto found = mFactories.find(stateID);
	assert(found != mFactories.end());

	return found->second();  //return a smart pointer to a newly created object of the corresponding state class
}

int main() {

	StateStack				mStateStack(State::Context("Common Stuff Between states")); //mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer))


	mStateStack.registerState<TitleState>(States::Title);
	mStateStack.registerState<VideoState>(States::Video);

	mStateStack.createState(States::Title);
	mStateStack.createState(States::Video);

	//factory method pattern is a creational pattern that uses factory methods
	//factory methods let subclasses define which class to instantiate and defers instatiations to subclasses
	//defines a separate operation (factory method) for creating an object
	State::Ptr titleStatePtr(mStateStack.createState(States::Title)); //createState is the factory method

	titleStatePtr->draw();

	State::Ptr VideoStatePtr(mStateStack.createState(States::Video));

	VideoStatePtr->draw();

	system("pause");
	return 0;
}
