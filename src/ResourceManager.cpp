#include "ResourceManager.hpp"

//STD
#include <cassert>
#include <iostream>

//SELF
#include "Utility.hpp"

namespace zge
{

std::map<std::string, sf::Texture> ResourceManager::m_Textures;
std::map<std::string, sf::SoundBuffer> ResourceManager::m_SoundBuffers;
std::map<std::string, sf::Font> ResourceManager::m_Fonts;
std::map<std::string, std::unique_ptr<sf::Music>> ResourceManager::m_Music;
std::list<sf::Sound> ResourceManager::m_Sounds;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
    for (std::map<std::string, std::unique_ptr<sf::Music>>::iterator it = m_Music.begin(); it != m_Music.end(); ++it)
    {
        it->second->stop();
    }
}

void ResourceManager::Update()
{
    assert(m_Sounds.size() <= 256);

    for (auto it = m_Sounds.begin(); it != m_Sounds.end();)
    {
        std::cout << "Sound " << std::distance(m_Sounds.begin(), it) << " " << it->getPlayingOffset().asSeconds() << "\n";

        if (it->getStatus() == sf::Sound::Stopped)
        {
            std::cout << "Sound " << std::distance(m_Sounds.begin(), it) << " Killed\n";
            it = m_Sounds.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

sf::Texture& ResourceManager::texture(std::string fileName)
{
	auto it = m_Textures.find(fileName);

	if (it == m_Textures.end())
	{
		sf::Texture t;

		assert(t.loadFromFile("textures/" + fileName + ".png"));

		std::cout << "Texture Loaded: " << "textures/" << fileName << ".png\n";
		m_Textures.insert(std::make_pair(fileName, t));

		return m_Textures.find(fileName)->second;
	}

	return it->second;
}

sf::SoundBuffer& ResourceManager::soundBuffer(std::string fileName)
{
	auto it = m_SoundBuffers.find(fileName);

	if (it == m_SoundBuffers.end())
	{
		sf::SoundBuffer sb;

		assert(sb.loadFromFile("audio/" + fileName + ".wav"));

		std::cout << "SoundBuffer Loaded: " << "audio/" << fileName << ".wav\n";
		m_SoundBuffers.insert(std::make_pair(fileName, sb));

		return m_SoundBuffers.find(fileName)->second;
	}

	return it->second;
}

sf::Music& ResourceManager::music(std::string fileName)
{
	auto it = m_Music.find(fileName);

	if (it == m_Music.end())
	{
		std::unique_ptr<sf::Music> m(new sf::Music);

		assert(m->openFromFile("audio/" + fileName + ".wav"));

		std::cout << "Music Loaded: " << "audio/" << fileName << ".wav\n";
		m_Music.insert(std::make_pair(fileName, std::move(m)));

		return *(m_Music.find(fileName)->second);
	}

	return *(it->second);
}

sf::Font& ResourceManager::font(std::string fileName)
{
	auto it = m_Fonts.find(fileName);

	if (it == m_Fonts.end())
	{
		sf::Font f;

		assert(f.loadFromFile("fonts/" + fileName + ".ttf"));

		std::cout << "Font Loaded: " << "fonts/" << fileName << ".ttf\n";
		m_Fonts.insert(std::make_pair(fileName, f));

		return m_Fonts.find(fileName)->second;
	}

	return it->second;
}

sf::Sound& ResourceManager::sound(std::string fileName)
{
    sf::Sound s;
    s.setBuffer(this->soundBuffer(fileName));
    m_Sounds.push_back(s);
    m_Sounds.back().play();
    return m_Sounds.back();
}

void ResourceManager::animation()
{
	assert(false);
}

} //ZGE

