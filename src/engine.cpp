#include "engine.hpp"

#include <iostream>
#include "spdlog/sinks/basic_file_sink.h"
#include "game_state.hpp"

void Engine::initWindow()
{
    // TODO: Make proto files to store config // create struct to store config
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 800), "Sii Game");
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

void Engine::initStates()
{
    this->states.emplace(std::make_unique<GameState>(this->window));
}

Engine::Engine() 
{
    this->initWindow();
    this->initLogger();
    this->initStates();
}

Engine::~Engine()
{
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

    if(!this->states.empty())
    {
        this->states.top()->update(this->delta);
        if(this->states.top()->getQuit())
        {
            this->states.top()->endState();
            this->states.pop();
        }
    }
    else 
    {
        // End of application
        this->window->close();
    }
}

void Engine::renderFrame()
{
    this->window->clear();

    if(!this->states.empty())
    {
        this->states.top()->render();
    }

    this->window->display();
}


void Engine::updateDeltaClock()
{
    // Update delta variable to measure how much time take execution of update and render function (frame update/render)
    this->delta = this->deltaTimeClock.restart().asSeconds();

    // to many for spdlog
    // spdlog::info("Frame render time: {}", this->delta);
    //system("cls");
    //std::cout << "Frame render time:" << this->delta;
}