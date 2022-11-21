#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"

#include <vector>
#include <map>
#include <stack>
#include <memory>

class State
{
private: 
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
    virtual void updateKeybinds(const float& delta) = 0;
};