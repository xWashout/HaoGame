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

    void initWindow();
    void initLogger();

public:
    Engine();
    virtual ~Engine() = default;

    void run();
    void updateEvents();
    void update();
    void renderFrame();

    void updateDeltaClock();
};
