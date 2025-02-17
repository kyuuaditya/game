#pragma once 
#include <sfml/Graphics.hpp>

class mainMenu {
private:
    sf::Vector2f backgroundSize;
    int transparentBoxSizeX;
    int transparentBoxSizeY;

    sf::RectangleShape transparentBox;

    std::vector<sf::Texture> backgroundTextures;
    sf::Sprite backgroundSprite;

    float animationTime;
    int currentFrame;
    static const int NUM_FRAMES = 70; // number of frames in the GIF
    static constexpr float FRAME_DURATION = 100; // Duration of each frame in seconds

public:
    void Initialize(sf::Vector2f windowSize);
    void Update(sf::RenderWindow& window, float deltaTime);
    void Render(sf::RenderWindow& window);
};