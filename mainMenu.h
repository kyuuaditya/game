#pragma once 
#include <sfml/Graphics.hpp>

class mainMenu {
private:
    sf::Vector2f backgroundSize; // size of the background GIF
    int transparentBoxSizeX; // width of the transparent box behind the buttons
    int transparentBoxSizeY; // height of the transparent box behind the buttons

    sf::RectangleShape transparentBox; // transparent box behind the buttons

    std::vector<sf::Texture> backgroundTextures; // vector of textures for the GIF
    sf::Sprite backgroundSprite; // sprite for the background GIF

    float animationTime; // time since last frame change
    int currentFrame; // current frame number of the GIF
    static const int NUM_FRAMES = 70; // number of frames in the GIF
    static constexpr float FRAME_DURATION = 100; // Duration of each frame in seconds

public:
    void Initialize(sf::Vector2f windowSize);
    void Update(sf::RenderWindow& window, float deltaTime);
    void Render(sf::RenderWindow& window);
};