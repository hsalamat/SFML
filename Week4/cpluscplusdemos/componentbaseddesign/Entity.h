#pragma once
//For large scale games, component based approaches are certailny an option. Abilities are aggregated as components in the single entities, instead of base classes.
//Each entity would then hold abilities as members.
//Components specify behavior and operate on properties. Properties are shared between all components by a reference and get updates for free. 
//This means no large overhead for message passing. 

#include <map>  
#include <string>
#include "Component.h"	

class Property {

};
class Entity {
public:
	Entity(const unsigned int id, const std::string& enttype);
	~Entity();

	//Component Interface
	const Component* GetComponent(const std::string& family) const;
	void SetComponent(Component* newComp);
	void RemoveComponent(const std::string& family);
	void ClearComponents();

	//Property Interface
	bool HasProperty(const std::string& propName) const;
	template<class T> T& GetPropertyDataPtr(const std::string& propName);
	template<class T> const T& GetPropertyDataPtr(const std::string& propName) const;

	//Entity Interface
	const unsigned int GetID() const;
	void Update(float dt);

private:
	void RemoveProperty(const std::string& propName);
	void ClearProperties();
	template<class T> void AddProperty(const std::string& propName);
	template<class T> Property<T>* GetProperty(const std::string& propName);
	template<class T> const Property<T>* GetProperty(const std::string& propName) const;

	unsigned int m_Id;
	std::map<const string, IProperty*> m_Properties;
	std::map<const string, Component*> m_Components;
};

template<class T>
inline T & Entity::GetPropertyDataPtr(const std::string & propName)
{
	// TODO: insert return statement here
}

template<class T>
inline const T & Entity::GetPropertyDataPtr(const std::string & propName) const
{
	// TODO: insert return statement here
}

template<class T>
inline void Entity::AddProperty(const std::string & propName)
{
}

template<class T>
inline Property<T>* Entity::GetProperty(const std::string & propName)
{
	return NULL;
}

template<class T>
inline const Property<T>* Entity::GetProperty(const std::string & propName) const
{
	return NULL;
}
