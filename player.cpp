#include "player.h"
#include <iostream>

void player::Load(sf::Vector2f windowSize) {
    if (playerTexture.loadFromFile("assets/mage/Walk.png")) { // this has 7 images in the sprite sheet
        int xSize = 7;
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(xIndex * width, yIndex * height, width, height));
        playerSprite.setPosition(sf::Vector2f(windowSize.x / 3 - playerSprite.getLocalBounds().left / (xSize * 2), windowSize.y - playerSprite.getLocalBounds().height * scale.y));
        playerSprite.setScale(scale);
        std::cout << "player texture loaded!" << std::endl;
    }
    else {
        std::cout << "player texture failed to load!" << std::endl;
    }
}

void player::Initialize() {
}

void player::Update(sf::RenderWindow& window, sf::Vector2f mousePosition, float deltaTime) {
    playerSprite.setTextureRect(sf::IntRect(xIndex * width, yIndex * height, width, height));
}

void player::Render(sf::RenderWindow& window, bool isInGame) {
    if (isInGame) {
        window.draw(playerSprite);
    }
}
