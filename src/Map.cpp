#include "Map.hpp"

//STD
#include <iostream>


//3RD

//SELF
#include "Constants.hpp"

Map::Map(sf::Vector2i size)
{
    m_Textures.add("Floor", "textures/Floor.png");
    m_Textures.add("IndestructibleWall", "textures/IndestructibleWall.png");
    m_Textures.add("DestructibleWall", "textures/DestructibleWall.png");

    this->setMapSize(size);
	this->generateMap();
}

void Map::generateMap()
{
    m_LevelFloor.clear();
    m_CollisionGrid.clear();

    m_CollisionGrid.resize(m_MapSize.y/Constant::tileSize);
    for (unsigned int i = 0; i < m_CollisionGrid.size(); ++i)
    {
        m_CollisionGrid[i].resize(m_MapSize.x/Constant::tileSize);
    }

    this->generateFloor();
    this->generateIndestructibleWalls();
    this->generateDestructibleWalls();
}

void Map::generateFloor()
{
	sf::VertexArray floor(sf::Quads, (m_MapSize.x/Constant::tileSize)*(m_MapSize.y/Constant::tileSize)*4); //4 = number of points in quad
	m_LevelFloor.setPrimitiveType(sf::Quads);
	m_LevelFloor.resize((m_MapSize.x/Constant::tileSize)*(m_MapSize.y/Constant::tileSize)*4); //4 = number of points in quad

	for (int h = 0; h < m_MapSize.y/Constant::tileSize; ++h)
	{
		for (int w = 0; w < m_MapSize.x/Constant::tileSize; ++w)
		{
			sf::Vertex TL;
			TL.color = sf::Color::White;
			TL.texCoords = sf::Vector2f(0, 0);
			TL.position = sf::Vector2f(w*Constant::tileSize, h*Constant::tileSize);
			m_LevelFloor.append(TL);

			sf::Vertex TR;
			TR.color = sf::Color::White;
			TR.texCoords = sf::Vector2f(Constant::tileSize, 0);
			TR.position = sf::Vector2f(w*Constant::tileSize + Constant::tileSize, h*Constant::tileSize);
			m_LevelFloor.append(TR);

			sf::Vertex BR;
			BR.color = sf::Color::White;
			BR.texCoords = sf::Vector2f(Constant::tileSize, Constant::tileSize);
			BR.position = sf::Vector2f(w*Constant::tileSize + Constant::tileSize, h*Constant::tileSize + Constant::tileSize);
			m_LevelFloor.append(BR);

			sf::Vertex BL;
			BL.color = sf::Color::White;
			BL.texCoords = sf::Vector2f(0, Constant::tileSize);
			BL.position = sf::Vector2f(w*Constant::tileSize, h*Constant::tileSize + Constant::tileSize);
			m_LevelFloor.append(BL);
		}
	}
}

void Map::generateIndestructibleWalls()
{
    for (unsigned int h = 0; h < m_CollisionGrid.size(); ++h)
	{
		m_CollisionGrid[h][0] = GridValue::WallIndestructible; //Left layer of tiles
		m_CollisionGrid[h][m_CollisionGrid[0].size() - 1] = GridValue::WallIndestructible; //Right layer of tiles
		m_CollisionGrid[0][h] = GridValue::WallIndestructible; //Top layer of tiles
		m_CollisionGrid[m_CollisionGrid.size() - 1][h] = GridValue::WallIndestructible; //Bottom layer of tiles
	}
}

void Map::generateDestructibleWalls()
{
    for (unsigned int h = 0; h < m_CollisionGrid.size(); ++h)
	{
		for (unsigned int w = 0; w < m_CollisionGrid[0].size(); ++w)
		{
            if (rand() % 1000 < 100)
            {
                if (m_CollisionGrid[h][w] == GridValue::Empty)
                {
                    m_CollisionGrid[h][w] = GridValue::WallDestructible;
                }
            }
        }
    }

    //top left
    m_CollisionGrid[1][1] = GridValue::Empty;
    m_CollisionGrid[1][2] = GridValue::Empty;
    m_CollisionGrid[2][1] = GridValue::Empty;

    //top right
    m_CollisionGrid[1][m_CollisionGrid[0].size() - 2] = GridValue::Empty;
    m_CollisionGrid[1][m_CollisionGrid[0].size() - 3] = GridValue::Empty;
    m_CollisionGrid[2][m_CollisionGrid[0].size() - 2] = GridValue::Empty;

    //bottom left
    m_CollisionGrid[m_CollisionGrid.size() - 2][1] = GridValue::Empty;
    m_CollisionGrid[m_CollisionGrid.size() - 2][2] = GridValue::Empty;
    m_CollisionGrid[m_CollisionGrid.size() - 3][1] = GridValue::Empty;

    //bottom right
    m_CollisionGrid[m_CollisionGrid.size() - 2][m_CollisionGrid[0].size() - 2] = GridValue::Empty;
    m_CollisionGrid[m_CollisionGrid.size() - 2][m_CollisionGrid[0].size() - 3] = GridValue::Empty;
    m_CollisionGrid[m_CollisionGrid.size() - 3][m_CollisionGrid[0].size() - 2] = GridValue::Empty;
}

void Map::update(const sf::Time& delta)
{
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_LevelFloor, &m_Textures.get("Floor"));
    for (unsigned int h = 0; h < m_CollisionGrid.size(); ++h)
    {
        for (unsigned int w = 0; w < m_CollisionGrid[0].size(); ++w)
        {
            if (m_CollisionGrid[h][w] == GridValue::WallIndestructible)
            {
                sf::Sprite s;
                s.setTexture(m_Textures.get("IndestructibleWall"));
                s.setPosition(w*Constant::tileSize, h*Constant::tileSize);
                target.draw(s, states);
            }
            else if (m_CollisionGrid[h][w] == GridValue::WallDestructible)
            {
                sf::Sprite s;
                s.setTexture(m_Textures.get("DestructibleWall"));
                s.setPosition(w*Constant::tileSize, h*Constant::tileSize);
                target.draw(s, states);
            }
        }
    }
}

int Map::getCollisionGridSquare(sf::Vector2i pos)
{
    if (pos.x < 0 ||
        unsigned(pos.x) >= m_CollisionGrid[pos.y].size() ||
        pos.y < 0 ||
        unsigned(pos.y) >= m_CollisionGrid.size())
    {
        std::cout << "[GET] The requested collision grid square [" << pos.y << "][" << pos.x <<"] is invalid!\n";
        assert(false);
    }

    return m_CollisionGrid[pos.y][pos.x];
}

void Map::setCollisionGridSquare(sf::Vector2i pos, int val)
{
    if (pos.x < 0 ||
        unsigned(pos.x) >= m_CollisionGrid[pos.y].size() ||
        pos.y < 0 ||
        unsigned(pos.y) >= m_CollisionGrid.size())
    {
        std::cout << "[SET] The requested collision grid square [" << pos.y << "][" << pos.x <<"] is invalid!\n";
        assert(false);
    }

    m_CollisionGrid[pos.y][pos.x] = val;
}

void Map::setMapSize(sf::Vector2i size)
{
    if (size.x % Constant::tileSize != 0 ||
        size.y % Constant::tileSize != 0)
    {
        std::cout << "The size of the map [" << size.x << ", " << size.y << "is not divisible by the tile size\n";
        assert(false);
    }

    m_MapSize = size;
    this->generateMap();
}

sf::Vector2f Map::getValidSpawnLocation()
{
    if (m_CollisionGrid[1][1] != GridValue::Player)
    {
        m_CollisionGrid[1][1] = GridValue::Player;
        return sf::Vector2f(Constant::tileSize, Constant::tileSize);
    }
    else if (m_CollisionGrid[m_CollisionGrid.size() - 2][m_CollisionGrid[0].size() - 2] != GridValue::Player)
    {
        m_CollisionGrid[m_CollisionGrid.size() - 2][m_CollisionGrid[0].size() - 2] = GridValue::Player;
        return sf::Vector2f(Constant::tileSize * (m_CollisionGrid[0].size() - 2), Constant::tileSize * (m_CollisionGrid.size() - 2));
    }

    return sf::Vector2f(0, 0);
}
