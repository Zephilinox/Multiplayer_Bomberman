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
}

FPS::~FPS()
{
    std::cout << "[FPS] Destructor\n";
}

void FPS::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Text, states);
}

void FPS::update(sf::RenderWindow& window)
{
    m_Text.setPosition(Constants::windowWidth - m_Text.getLocalBounds().width, 0);
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
