#include "entity.hpp"

Entity::Entity()
{
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->movementSpeed = 100.f;
}

void Entity::move(const float& delta, const float x, const float y)
{
    this->shape.move(x * this->movementSpeed * delta, y * this->movementSpeed * delta);
}

void Entity::update(const float &delta)
{
}

void Entity::render(const std::shared_ptr<sf::RenderTarget>& target)
{
    target->draw(this->shape);
}