#include "GameState.hpp"

GameState::GameState()
{
	sf::VertexArray floor(sf::Quads, 21*21*4);
	m_LevelFloor.setPrimitiveType(sf::Quads);
	m_LevelFloor.resize(21*21*4);

	for (int h = 0; h < 672/32; ++h)
	{
		for (int w = 0; w < 672/32; ++w)
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

    for (int h = 0; h < 21; ++h)
	{
		m_CollisionGrid[h][0] = 1;
		m_CollisionGrid[h][20] = 1;
		m_CollisionGrid[0][h] = 1;
		m_CollisionGrid[20][h] = 1;

		for (int w = 0; w < 21; ++w)
		{
			if (h % 3 == 0 && w % 3 == 0)
			{
				m_CollisionGrid[h][w] = 1;
			}
		}
	}
}

void GameState::handleEvent(sf::Event& event, sf::RenderWindow& window)
{

}

void GameState::update(sf::RenderWindow& window, const sf::Time& delta)
{
    m_Player1.update(delta, m_CollisionGrid);
}

sf::VertexArray GameState::getLevelFloor()
{
    return m_LevelFloor;
}

void GameState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int h = 0; h < 21; ++h)
    {
        for (int w = 0; w < 21; ++w)
        {
            if (m_CollisionGrid[h][w] == 1)
            {
                sf::Sprite s;
                s.setTexture(m_ResMan.texture("tile2"));
                s.setPosition(w*32, h*32);
                target.draw(s, states);
            }
        }
    }

    target.draw(m_Player1, states);
}
