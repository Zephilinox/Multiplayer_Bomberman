#ifndef MAP_HPP
#define MAP_HPP

//STD
#include <vector>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManagement/ResourceCache.hpp"

class Map : public sf::Drawable
{
public:
    Map(sf::Vector2i size);
    void update(const sf::Time& delta);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Vector2f getValidSpawnLocation();

    int getCollisionGridSquare(sf::Vector2i pos);
    void setCollisionGridSquare(sf::Vector2i pos, int val);

    void setMapSize(sf::Vector2i size);

private:
    sf::VertexArray m_LevelFloor;
    //sf::RenderTexture m_World;
	std::vector<std::vector<int>> m_CollisionGrid;

	mutable ResourceCache<sf::Texture> m_Textures;

	sf::Vector2i m_MapSize;

	void generateMap();
	void generateFloor();
	void generateIndestructibleWalls();
	void generateDestructibleWalls();
};

#endif // MAP_HPP
