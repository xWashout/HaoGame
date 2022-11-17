#include "engine.hpp"

#include <iostream>

void Engine::initWindow()
{
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(200, 200), "Sii Game");
    this->window->setFramerateLimit(120);
    // this->window->setVerticalSyncEnabled(false); disabled by default
}

Engine::Engine() 
{
    this->initWindow();
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


    // todo, add FMT, or logging system
    system("cls");
    std::cout << this->delta;
}