#include "FPS.hpp"

//STD

//3RD

//SELF
#include "Constants.hpp"
#include "Utility.hpp"

FPS::FPS():
m_UpdateRate(100),
m_Font("fonts/arial.ttf")
{
    m_Text.setFont(m_Font.get());
    m_Text.setScale(0.7, 0.7);
    m_Text.setPosition(2, 0);
}

FPS::~FPS()
{
    std::cout << "[FPS] Destructor\n";
}

void FPS::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //target.draw(m_OuterText, states);
    m_Text.setColor(sf::Color::Black);

    m_Text.setPosition(m_Text.getPosition().x - 1, m_Text.getPosition().y);
    target.draw(m_Text, states);

    m_Text.setPosition(m_Text.getPosition().x + 2, m_Text.getPosition().y);
    target.draw(m_Text, states);

    m_Text.setPosition(m_Text.getPosition().x - 1, m_Text.getPosition().y - 1);
    target.draw(m_Text, states);

    m_Text.setPosition(m_Text.getPosition().x, m_Text.getPosition().y + 2);
    target.draw(m_Text, states);

    m_Text.setColor(sf::Color(255, 180, 0));
    m_Text.setPosition(m_Text.getPosition().x, m_Text.getPosition().y - 1);
    target.draw(m_Text, states);
}

void FPS::update(sf::RenderWindow& window)
{
    m_Text.setPosition(0, 0);
}

void FPS::setFPS(float fps)
{
    if (unsigned(rand() % 100) < m_UpdateRate) m_Text.setString(zge::toString(fps));
}

void FPS::setUpdateRate(unsigned int ur)
{
    m_UpdateRate = ur;
}

unsigned int FPS::getUpdateRate()
{
    return m_UpdateRate;
}
