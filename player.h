#pragma once
#include <sfml/Graphics.hpp>

class player {
private:
    sf::Texture playerTexture; // texture for the player
    sf::Vector2f scale = sf::Vector2f(2.0f, 2.0f); // scale of the player sprite

public:
    int height = 128;
    int width = 128;

    sf::Sprite playerSprite; // sprite for the player
    int xIndex = 0; // sprite sheet x index
    int yIndex = 0; // sprite sheet y index

public:
    void Load();
    void Initialize(sf::Vector2f windowSize);
    void Update(sf::RenderWindow& window, sf::Vector2f mousePosition, float deltaTime);
    void Render(sf::RenderWindow& window, bool isInGame);
};