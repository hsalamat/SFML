#pragma once
#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>
#include <SFML\Graphics.hpp>
using namespace std;

namespace Textures
{
	enum ID
	{
		Landscape,
		Airplane,
	};
}

class TextureHolder
{
public:
	void						load(Textures::ID id, const std::string& filename);


	sf::Texture&					get(Textures::ID id);
	const sf::Texture&				get(Textures::ID id) const;   //if we only have a pointer or reference to a const TextureHolder, we need a constant qualified overload. The caller cannot change the texture.


private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>>	mTextureMap;

};
