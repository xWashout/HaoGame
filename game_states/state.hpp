#pragma once

#include "entity.hpp"

class State
{
private:

protected: 
    std::vector<sf::Texture> textures;
    std::shared_ptr<sf::RenderWindow> window;
    bool quit = false;

public:
    State(std::shared_ptr<sf::RenderWindow> window);
    virtual ~State() = default;

    virtual void update(const float& delta) = 0;
    virtual void render(std::shared_ptr<sf::RenderTarget> target = nullptr) = 0;
    virtual void endState() = 0;

    // TODO refactor
    bool getQuit() const; 
    virtual void checkForQuit();
    virtual void updateInput(const float& delta) = 0;
};