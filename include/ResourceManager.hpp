#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

//STD
#include <string>
#include <list>
#include <map>
#include <memory>

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

    void Update();

	sf::Texture& texture(std::string fileName);
	sf::SoundBuffer& soundBuffer(std::string fileName);
	sf::Music& music(std::string fileName);
	sf::Font& font(std::string fileName);
	sf::Sound& sound(std::string fileName);
	void animation();

private:
	static std::map<std::string, sf::Texture> m_Textures;
	static std::map<std::string, sf::SoundBuffer> m_SoundBuffers;
	static std::map<std::string, sf::Font> m_Fonts;
	static std::map<std::string, std::unique_ptr<sf::Music>> m_Music; //sf::Music is non-copyable and has no move semantics...
    static std::list<sf::Sound> m_Sounds; //Adding & Deleting elements in a vector causes other elements to be moved and copied. Need to use list due to OpenAL.
};

} //ZGE

#endif // RESOURCEMANAGER_HPP
