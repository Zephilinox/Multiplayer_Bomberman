#include "Map.hpp"

//STD
#include <iostream>

const int IndestructibleWall = -1;
const int DestructibleWall = 1;

Map::Map()
{
    m_CollisionGrid.resize(22);
    for (unsigned int i = 0; i < m_CollisionGrid.size(); ++i)
    {
        m_CollisionGrid[i].resize(22);
    }

	sf::VertexArray floor(sf::Quads, 21*21*4);
	m_LevelFloor.setPrimitiveType(sf::Quads);
	m_LevelFloor.resize(21*21*4);

	for (int h = 0; h < 704/32; ++h)
	{
		for (int w = 0; w < 704/32; ++w)
		{
			sf::Vertex TL;
			TL.color = sf::Color::White;
			TL.texCoords = sf::Vector2f(0, 0);
			TL.position = sf::Vector2f(w*32, h*32);
			m_LevelFloor.append(TL);

			sf::Vertex TR;
			TR.color = sf::Color::White;
			TR.texCoords = sf::Vector2f(32, 0);
			TR.position = sf::Vector2f(w*32 + 32, h*32);
			m_LevelFloor.append(TR);

			sf::Vertex BR;
			BR.color = sf::Color::White;
			BR.texCoords = sf::Vector2f(32, 32);
			BR.position = sf::Vector2f(w*32 + 32, h*32 + 32);
			m_LevelFloor.append(BR);

			sf::Vertex BL;
			BL.color = sf::Color::White;
			BL.texCoords = sf::Vector2f(0, 32);
			BL.position = sf::Vector2f(w*32, h*32 + 32);
			m_LevelFloor.append(BL);
		}
	}

    for (unsigned int h = 0; h < m_CollisionGrid.size(); ++h)
	{
		m_CollisionGrid[h][0] = IndestructibleWall;
		m_CollisionGrid[h][m_CollisionGrid[0].size() - 1] = IndestructibleWall;
		m_CollisionGrid[0][h] = IndestructibleWall;
		m_CollisionGrid[m_CollisionGrid.size() - 1][h] = IndestructibleWall;

		for (unsigned int w = 0; w < m_CollisionGrid[0].size(); ++w)
		{
			if (h % 3 == 0 && w % 3 == 0)
			{
			    if (m_CollisionGrid[h][w] == 0)
                {
                    m_CollisionGrid[h][w] = DestructibleWall;
                }
			}
		}
	}
}

void Map::update(const sf::Time& delta)
{
}

std::vector<std::vector<int>> Map::getCollisionGrid()
{
    return m_CollisionGrid;
}

void Map::setCollisionGridSquare(sf::Vector2i pos, int val)
{
    m_CollisionGrid[pos.y][pos.x] = val;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_LevelFloor, &m_ResMan.texture("tile"));
    for (unsigned int h = 0; h < m_CollisionGrid.size(); ++h)
    {
        for (unsigned int w = 0; w < m_CollisionGrid[0].size(); ++w)
        {
            if (m_CollisionGrid[h][w] == IndestructibleWall)
            {
                sf::Sprite s;
                s.setTexture(m_ResMan.texture("tile2"));
                s.setPosition(w*32, h*32);
                target.draw(s, states);
            }
            else if (m_CollisionGrid[h][w] == DestructibleWall)
            {
                sf::Sprite s;
                s.setTexture(m_ResMan.texture("tile4"));
                s.setPosition(w*32, h*32);
                target.draw(s, states);
            }
        }
    }
}
