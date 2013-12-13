#include "ResourceManager.hpp"

#include <cassert>
#include <iostream>

namespace zge
{

std::map<std::string, sf::Texture> ResourceManager::m_Textures;
std::map<std::string, sf::SoundBuffer> ResourceManager::m_SoundBuffers;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

sf::Texture& ResourceManager::texture(std::string fileName)
{
	std::map<std::string, sf::Texture>::iterator it = m_Textures.find(fileName);

	if (it == m_Textures.end()) //not found
	{
		sf::Texture t;
		assert(t.loadFromFile("textures/" + fileName + ".png"));
		std::cout << "Texture Loaded: " << "textures/" << fileName << ".png\n";
		m_Textures.insert(std::make_pair(fileName, t));
		return m_Textures.find(fileName)->second;
	}

	return it->second;
}

sf::SoundBuffer& ResourceManager::sound(std::string fileName)
{
	std::map<std::string, sf::SoundBuffer>::iterator it = m_SoundBuffers.find(fileName);

	if (it == m_SoundBuffers.end()) //not found
	{
		sf::SoundBuffer sb;
		assert(sb.loadFromFile("audio/" + fileName + ".wav"));
		std::cout << "SoundBuffer Loaded: " << "audio/" << fileName << ".png\n";
		m_SoundBuffers.insert(std::make_pair(fileName, sb));
		return m_SoundBuffers.find(fileName)->second;
	}

	return it->second;
}

sf::Music& ResourceManager::music()
{
	assert(false);
}

sf::Font& ResourceManager::font()
{
	assert(false);
}

void ResourceManager::animation()
{
	assert(false);
}

} //Namespace zge

