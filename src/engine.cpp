#include "engine.hpp"

#include <iostream>
#include "spdlog/sinks/basic_file_sink.h"

void Engine::initWindow()
{
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(200, 200), "Sii Game");
    this->window->setFramerateLimit(120);
    // this->window->setVerticalSyncEnabled(false); disabled by default
}

void Engine::initLogger()
{
    try 
    {
        logger = spdlog::basic_logger_mt("logger", "logs/logs.txt");
        spdlog::set_default_logger(logger);
        spdlog::flush_on(spdlog::level::info);
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cerr << "Log init failed: " << ex.what() << std::endl;
    }
}

Engine::Engine() 
{
    this->initWindow();
    this->initLogger();
}

void Engine::run() 
{
    while(this->window->isOpen())
    {
        this->updateDeltaClock();
        this->update();
        this->renderFrame();
    }
}

void Engine::updateEvents()
{
    while(this->window->pollEvent(this->event))
    {
        if(this->event.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}

void Engine::update()
{
    this->updateEvents();
}

void Engine::renderFrame()
{
    this->window->clear();

    this->window->display();
}


void Engine::updateDeltaClock()
{
    // Update delta variable to measure how much time take execution of update and render function (frame update/render)
    this->delta = this->deltaTimeClock.restart().asSeconds();

    // to many for spdlog
    // spdlog::info("Frame render time: {}", this->delta);
    system("cls");
    std::cout << "Frame render time:" << this->delta;
}