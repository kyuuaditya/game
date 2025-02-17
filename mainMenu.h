#pragma once 
#include <sfml/Graphics.hpp>

class mainMenu {
private:
    sf::Texture backgroundTexture;
    sf::Vector2f backgroundSize;

public:
    sf::Sprite backgroundSprite;

public:
    void Initialize(sf::Vector2f windowSize);
    void Update(sf::RenderWindow& window);
    void Render(sf::RenderWindow& window);
};