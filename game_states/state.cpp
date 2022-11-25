#include "state.hpp"
#include "keybinds.hpp"

State::State(std::shared_ptr<sf::RenderWindow> window)
{
    this->window = window;
}

void State::checkForQuit()
{
    if(sf::Keyboard::isKeyPressed(Key::Close))
    {
        this->quit = true;
    }
}

bool State::getQuit() const
{
    return this->quit;
}