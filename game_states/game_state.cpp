#include "game_state.hpp"
#include <iostream>

GameState::GameState(std::shared_ptr<sf::RenderWindow> window) 
    : State(window)
{}

void GameState::update(const float& delta)
{
    this->updateInput(delta);

    this->player.update(delta);
}

void GameState::render(std::shared_ptr<sf::RenderTarget> target)
{
    if(not target)
    {
        this->player.render(this->window);
    }
    else
    {
        this->player.render(target);
    }
    
}

void GameState::updateInput(const float& delta)
{
    this->checkForQuit();

    if(sf::Keyboard::isKeyPressed(Key::MoveUp))
    {
        this->player.move(delta, 0.f, -1.f);
    }
    else if(sf::Keyboard::isKeyPressed(Key::MoveDown))
    {
        this->player.move(delta, 0.f, 1.f);
    }
    else if(sf::Keyboard::isKeyPressed(Key::MoveLeft))
    {
        this->player.move(delta, -1.f, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(Key::MoveRight))
    {
        this->player.move(delta, 1.f, 0.f);
    }
}

void GameState::endState()
{
    std::cout << "endState()\n";
}