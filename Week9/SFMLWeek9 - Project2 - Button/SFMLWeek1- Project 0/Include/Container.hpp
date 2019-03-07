//A container bind other components together using a shared pointer
//A Conatiner doesn't own the components
//A container is responsible for selecting for one of its components inside the list
//Example: When you activate a button, which button should it be activated?
#pragma once

#include "Component.hpp"

#include <vector>
#include <memory>


namespace GUI
{

	class Container : public Component
	{
	public:
		//multiple pointers share an object. Reference counting ensures that object is alive as long as any shred_ptr points to it
		typedef std::shared_ptr<Container> Ptr;


	public:
		Container();
		//Pack new component to the list
		void				pack(Component::Ptr component);

		virtual bool		isSelectable() const;
		virtual void		handleEvent(const sf::Event& event);


	private:
		virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;

		bool				hasSelection() const;
		void				select(std::size_t index);
		void				selectNext();
		void				selectPrevious();


	private:
		std::vector<Component::Ptr>		mChildren;
		int								mSelectedChild;
	};

}



