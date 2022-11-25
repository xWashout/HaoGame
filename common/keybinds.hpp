#pragma once

#include <SFML/Window/Keyboard.hpp>

namespace Key
{
    using Key = sf::Keyboard::Key;

    constexpr auto MoveUp = Key::W;
    constexpr auto MoveDown = Key::S;
    constexpr auto MoveLeft = Key::A;
    constexpr auto MoveRight = Key::D;
    constexpr auto Close = Key::Escape;
}
