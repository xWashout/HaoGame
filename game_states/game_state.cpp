#include "game_state.hpp"
#include <iostream>

GameState::GameState(std::shared_ptr<sf::RenderWindow> window) 
    : State(window)
{

}

void GameState::update(const float& delta)
{
    this->updateKeybinds(delta);
}

void GameState::render(std::shared_ptr<sf::RenderTarget> target)
{

}

void GameState::updateKeybinds(const float& delta)
{
    this->checkForQuit();
}

void GameState::endState()
{
    std::cout << "endState()\n";
}