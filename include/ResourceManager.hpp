#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

//STD
#include <string>
#include <map>

//3RD
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//SELF

namespace zge
{

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	sf::Texture& texture(std::string fileName);
	sf::SoundBuffer& sound(std::string fileName);
	sf::Music& music();
	sf::Font& font();
	void animation();

private:
	static std::map<std::string, sf::Texture> m_Textures;
	static std::map<std::string, sf::SoundBuffer> m_SoundBuffers;
};

} //Namespace zge

#endif // RESOURCEMANAGER_HPP
