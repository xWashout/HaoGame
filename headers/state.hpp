#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"

#include <vector>

class State
{
private:
    std::vector<sf::Texture> textures;
public:
    State();
    virtual ~State() = default;

    virtual void update() = 0;
    virtual void render() = 0;
};