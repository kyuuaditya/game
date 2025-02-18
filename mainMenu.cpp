#include "mainMenu.h"
#include <iostream>

void mainMenu::Initialize(sf::Vector2f windowSize) {
    backgroundSize = windowSize; // size of the background GIF

    animationTime = 0.0f;
    currentFrame = 0;

    for (int i = 1; i <= NUM_FRAMES; ++i) { // importing all the images in the GIF
        sf::Texture texture;
        if (texture.loadFromFile("assets/mainMenu/background_GIF/" + std::to_string(i) + ".gif")) {
            backgroundTextures.push_back(texture);
        }
        else {
            std::cout << "Failed to load frame " << i << std::endl;
        }
    }

    if (!backgroundTextures.empty()) { // setting the first frame as the background
        backgroundSprite.setTexture(backgroundTextures[0]);
        backgroundSprite.setPosition(sf::Vector2f(0, 0));
        backgroundSprite.setTextureRect(sf::IntRect(0, 0, backgroundSize.x, backgroundSize.y));
        std::cout << "main menu background loaded!" << std::endl;
    }
    else {
        std::cout << "main menu background failed to load!" << std::endl;
    }

    // transparent box behind the buttons
    transparentBoxSizeX = 3 * backgroundSize.x / 8;
    transparentBoxSizeY = backgroundSize.y;
    transparentBox.setSize(sf::Vector2f(transparentBoxSizeX, transparentBoxSizeY));
    transparentBox.setFillColor(sf::Color(0, 0, 0, 127));
    transparentBox.setPosition(sf::Vector2f(3 * backgroundSize.x / 8, 0));

    // play button
    playButton.setSize(sf::Vector2f(transparentBoxSizeX / 3, transparentBoxSizeY / 12));
    playButton.setFillColor(sf::Color(0, 0, 0, 100));
    playButton.setOutlineColor(sf::Color::White);
    playButton.setOutlineThickness(2.0f);
    playButton.setPosition(sf::Vector2f(transparentBox.getPosition().x + transparentBox.getSize().x / 3, 5 * transparentBox.getSize().y / 12 - 1 * (transparentBox.getSize().y / 8)));

    // play button
    settingsButton.setSize(sf::Vector2f(transparentBoxSizeX / 3, transparentBoxSizeY / 12));
    settingsButton.setFillColor(sf::Color(0, 0, 0, 100));
    settingsButton.setOutlineColor(sf::Color::White);
    settingsButton.setOutlineThickness(2.0f);
    settingsButton.setPosition(sf::Vector2f(transparentBox.getPosition().x + transparentBox.getSize().x / 3, 5 * transparentBox.getSize().y / 12));

    // play button
    creditsButton.setSize(sf::Vector2f(transparentBoxSizeX / 3, transparentBoxSizeY / 12));
    creditsButton.setFillColor(sf::Color(0, 0, 0, 100));
    creditsButton.setOutlineColor(sf::Color::White);
    creditsButton.setOutlineThickness(2.0f);
    creditsButton.setPosition(sf::Vector2f(transparentBox.getPosition().x + transparentBox.getSize().x / 3, 5 * transparentBox.getSize().y / 12 + 1 * (transparentBox.getSize().y / 8)));

    // play button
    exitButton.setSize(sf::Vector2f(transparentBoxSizeX / 3, transparentBoxSizeY / 12));
    exitButton.setFillColor(sf::Color(0, 0, 0, 100));
    exitButton.setOutlineColor(sf::Color::White);
    exitButton.setOutlineThickness(2.0f);
    exitButton.setPosition(sf::Vector2f(transparentBox.getPosition().x + transparentBox.getSize().x / 3, 5 * transparentBox.getSize().y / 12 + 2 * (transparentBox.getSize().y / 8)));
}

void mainMenu::Update(sf::RenderWindow& window, float deltaTime) {
    animationTime += deltaTime; // add the time since last frame change
    if (animationTime >= FRAME_DURATION) { // change the background if more than FRAME_DURATION has passed
        animationTime = 0.0f;
        currentFrame = (currentFrame + 1) % backgroundTextures.size();
        backgroundSprite.setTexture(backgroundTextures[currentFrame]);
    }
}

void mainMenu::Render(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
    window.draw(transparentBox);
    window.draw(playButton);
    window.draw(settingsButton);
    window.draw(creditsButton);
    window.draw(exitButton);
}