#pragma once

#include "state.hpp"

#include <memory> 

class Engine {
private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::Event event;

    sf::Clock deltaTimeClock;
    float delta;

    void initWindow();

public:
    Engine();
    virtual ~Engine() = default;

    void run();
    void updateEvents();
    void update();
    void renderFrame();

    void updateDeltaClock();
};
