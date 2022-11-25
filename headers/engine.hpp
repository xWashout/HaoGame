#pragma once

#include "state.hpp"

#include <memory>
#include "spdlog/spdlog.h"

class Engine {
private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::Event event;
    sf::Clock deltaTimeClock;
    float delta;
    std::shared_ptr<spdlog::logger> logger;
    std::stack<std::unique_ptr<State>> states;

    void initWindow();
    void initLogger();
    void initStates();

public:
    Engine();
    virtual ~Engine();

    void run();
    void updateEvents();
    void update();
    void renderFrame();

    void updateDeltaClock();
};
