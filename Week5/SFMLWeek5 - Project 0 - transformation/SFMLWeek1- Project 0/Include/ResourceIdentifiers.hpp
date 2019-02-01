#pragma once
namespace sf
{
	class Texture;
}

namespace Textures
{
	enum ID
	{
		Landscape,
		Eagle,
		Raptor,
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;


typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
//using TextureHolder = ResourceHolder<sf::Texture, Textures::ID>;

