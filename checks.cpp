#include "checks.h"

// function to check if the mouse is over the RectangleShape button
bool checks::isMouseOverButton(const sf::RectangleShape& button, sf::Vector2f& mousePos) {
    return button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}