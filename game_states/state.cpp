#include "state.hpp"

State::State(std::shared_ptr<sf::RenderWindow> window)
{
    this->window = window;
}

void State::checkForQuit()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->quit = true;
    }
}

bool State::getQuit() const
{
    return this->quit;
}