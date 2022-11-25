#pragma once

#include "state.hpp"

class GameState : public State
{
private:
    Entity player;
public:
    GameState(std::shared_ptr<sf::RenderWindow> window);
    virtual ~GameState() = default;

    void update(const float& delta) override;
    void render(const std::shared_ptr<sf::RenderTarget> target = nullptr) override;

    void updateInput(const float& delta) override;
    void endState() override;
};