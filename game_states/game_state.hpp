#pragma once

#include "state.hpp"

class GameState : public State
{
    public:
    GameState(std::shared_ptr<sf::RenderWindow> window);
    virtual ~GameState() = default;

    void update(const float& delta) override;
    void render(std::shared_ptr<sf::RenderTarget> target = nullptr) override;

    void updateKeybinds(const float& delta) override;
    void endState() override;
};