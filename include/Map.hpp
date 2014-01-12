#ifndef MAP_HPP
#define MAP_HPP

//STD
#include <vector>

//3RD
#include <SFML/Graphics.hpp>

//SELF
#include "ResourceManager.hpp"
#include "Player.hpp"

class Map
{
public:
    Map();
    void update(const sf::Time& delta);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    std::vector<std::vector<int>> getCollisionGrid();

private:
    sf::VertexArray m_LevelFloor;
    sf::RenderTexture m_World;
    mutable zge::ResourceManager m_ResMan;
	std::vector<std::vector<int>> m_CollisionGrid;
};

#endif // MAP_HPP
