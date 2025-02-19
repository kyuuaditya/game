#include "player.h"
#include <iostream>

void player::Load() {
    if (playerTexture.loadFromFile("assets/mage/Walk.png")) {
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(xIndex * width, yIndex * height, width, height));
        playerSprite.setScale(scale);
        std::cout << "player texture loaded!" << std::endl;
    }
    else {
        std::cout << "player texture failed to load!" << std::endl;
    }
}

void player::Initialize(sf::Vector2f windowSize) {
    playerSprite.setPosition(sf::Vector2f(playerCoordX - playerSprite.getLocalBounds().left / (xSize * 2), windowSize.y - playerCoordY - playerSprite.getLocalBounds().height * scale.y));
}

void player::Update(sf::RenderWindow& window, sf::Vector2f mousePosition, float deltaTime, bool isInGame) {
    if (isInGame) {
        playerSprite.setTextureRect(sf::IntRect(xIndex * width, yIndex * height, width, height));
    }
    playerSprite.setPosition(sf::Vector2f(playerCoordX - playerSprite.getLocalBounds().left / (xSize * 2), window.getSize().y - playerCoordY - playerSprite.getLocalBounds().height * scale.y));
}

void player::Render(sf::RenderWindow& window, bool isInGame) {
    if (isInGame) {
        window.draw(playerSprite);
    }
}
