#include "Game.hpp"

//STD

//3RD

//SELF
#include "Constants.hpp"

Game::Game()
{
    m_Window.create(sf::VideoMode(Constant::windowWidth, Constant::windowHeight), "Bomberman");
    zge::StateManager::getInstance().addState(zge::StateID::MenuState);
}

Game::~Game()
{
    zge::StateManager::deleteInstance();
}

void Game::run()
{
    while (m_Window.isOpen())
    {
        this->handleEvent();
        this->update();
        this->draw();

		m_PrevFrame = m_Clock.restart();
        m_Fps.setFPS(std::floor(1.f / m_PrevFrame.asSeconds()));
    }
}

void Game::handleEvent()
{
    while (m_Window.pollEvent(m_Event))
    {
        switch(m_Event.type)
        {
            case sf::Event::Closed:
            {
                m_Window.close();
                break;
            }
            default:
            {
            }
        }
        zge::StateManager::getInstance().getActiveState().handleEvent(m_Event, m_Window);
    }
}

void Game::update()
{
    m_Fps.update(m_Window);
    zge::StateManager::getInstance().getActiveState().update(m_Window, m_PrevFrame);
}

void Game::draw()
{
    m_Window.clear(sf::Color(40, 40, 40));
    m_Window.draw(zge::StateManager::getInstance().getActiveState());
    m_Window.draw(m_Fps);
    m_Window.display();
}
