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

#include "keybinds.hpp"

class Entity
{
private:

protected:
    sf::RectangleShape shape;
    float movementSpeed;

public:
    Entity();
    virtual ~Entity() = default;

    virtual void move(const float& delta, const float x, const float y);
    virtual void update(const float &delta);
    virtual void render(const std::shared_ptr<sf::RenderTarget>& target);
};