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
		Airplane,
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;


#pragma region step 1
//typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
using TextureHolder = ResourceHolder<sf::Texture, Textures::ID>;

#pragma endregion