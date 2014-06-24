#include "GUI.hpp"

//STD

//3RD

//SELF
#include "Constants.hpp"

GUI::GUI()
{
    m_Textures.add("Player", "textures/Player.png");

    m_Player1.setTexture(m_Textures.get("Player"));
    m_Player2.setTexture(m_Textures.get("Player"));

    m_Player1.setColor(sf::Color(0, 100, 200));
    m_Player2.setColor(sf::Color(200, 50, 50));

    m_Player1.setPosition(Constant::windowWidth - (Constant::windowWidth - Constant::windowHeight) + ((Constant::windowWidth - Constant::windowHeight)/2) - (m_Textures.get("Player").getSize().x / 2),
                          0 + (m_Textures.get("Player").getSize().y / 2));

    m_Player2.setPosition(Constant::windowWidth - (Constant::windowWidth - Constant::windowHeight) + ((Constant::windowWidth - Constant::windowHeight)/2) - (m_Textures.get("Player").getSize().x / 2),
                          (Constant::windowHeight / 2) + (m_Textures.get("Player").getSize().y / 2));
}

void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Player1, states);
    target.draw(m_Player2, states);

    sf::VertexArray divider(sf::Lines, 2);
    divider[0] = sf::Vertex(sf::Vector2f(Constant::windowWidth - (Constant::windowWidth - Constant::windowHeight),
                                        Constant::windowHeight / 2),
                                        sf::Color(200, 200, 200));
    divider[1] = sf::Vertex(sf::Vector2f(Constant::windowWidth,
                                        Constant::windowHeight / 2),
                                        sf::Color(200, 200, 200));
    target.draw(divider, states);
}
