#include "TextureHolder.hpp"


void TextureHolder::load(Textures::ID id, const std::string &filename) {
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	if (!texture->loadFromFile(filename))
		throw std::runtime_error("TextureHolder::load -          Failed to load " + filename);
	// If loading successful, insert resource to map
	auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
	assert(inserted.second);
}


//step 2

sf::Texture& TextureHolder::get(Textures::ID id)
{
	//std::map<Textures::ID, sf::Texture>::iterator found;
	//let's auto specifier figure out the type
	auto found = mTextureMap.find(id);
	assert(found != mTextureMap.end());

	return *found->second;
}


const sf::Texture& TextureHolder::get(Textures::ID id) const
{
	auto found = mTextureMap.find(id);
	assert(found != mTextureMap.end());

	return *found->second;
}

//end step 2