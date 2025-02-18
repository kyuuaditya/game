#pragma once
#include <sfml/Graphics.hpp>

class checks {

public:
    bool isMouseOverButton(const sf::RectangleShape& button, sf::Vector2f& mousePos);
};