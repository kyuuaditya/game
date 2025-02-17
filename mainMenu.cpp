#include "mainMenu.h"
#include <iostream>

void mainMenu::Initialize(sf::Vector2f windowSize) {
    backgroundSize = windowSize;
    if (backgroundTexture.loadFromFile("assets/mainMenu/background_image.jpg")) {
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setPosition(sf::Vector2f(0, 0));
        backgroundSprite.setTextureRect(sf::IntRect(0, 0, backgroundSize.x, backgroundSize.y));
        std::cout << "main menu background loaded!" << std::endl;
    }
    else {
        std::cout << "main menu background failed to load!" << std::endl;
    }
}

void mainMenu::Update(sf::RenderWindow& window) {
}

void mainMenu::Render(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
}
