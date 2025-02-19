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

    sf::Font font;

    sf::Text playButtonText;
    std::string playButtonTextString = "Play";
    sf::Text settingsButtonText;
    std::string settingsButtonTextString = "Settings";
    sf::Text creditsButtonText;
    std::string creditsButtonTextString = "Credits";
    sf::Text exitButtonText;
    std::string exitButtonTextString = "Exit";

    int boxForMenusSizeX;
    int boxForMenusSizeY;

    sf::RectangleShape boxForMenus; // transparent box behind the buttons

public:
    bool isOnMenu = true; // is the game on the main menu
    bool isInGame = false; // is the game in progress
    bool isOnCredits = false; // is the game in the credits
    bool isOnSettings = false; // is the game in the settings

    sf::RectangleShape playButton; // play button
    sf::RectangleShape settingsButton; // settings button
    sf::RectangleShape creditsButton; // credits button
    sf::RectangleShape exitButton; // exit button

public:
    void Load();
    void Initialize(sf::Vector2f windowSize);
    void Update(sf::RenderWindow& window, sf::Vector2f mousePosition, float deltaTime);
    void Render(sf::RenderWindow& window);
};