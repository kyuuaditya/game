#include "mainMenu.h"
#include <iostream>

void mainMenu::Load() {

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
        std::cout << "main menu background loaded!" << std::endl;
    }
    else {
        std::cout << "main menu background failed to load!" << std::endl;
    }

    if (font.loadFromFile("assets/fonts/HomeVideo-BLG6G.ttf")) { // loading font
        std::cout << "font loaded" << std::endl;
    }
    else {
        std::cout << "font not loaded" << std::endl;
    }
}

void mainMenu::Initialize(sf::Vector2f windowSize) {
    backgroundSize = windowSize; // size of the background GIF
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, backgroundSize.x, backgroundSize.y));
    animationTime = 0.0f;
    currentFrame = 0;

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

    playButtonText.setFont(font);
    playButtonText.setCharacterSize(36);
    playButtonText.setFillColor(sf::Color::White);
    playButtonText.setString(playButtonTextString);
    playButtonText.setPosition(playButton.getPosition().x + playButton.getSize().x / 2 - playButtonText.getLocalBounds().width / 2, playButton.getPosition().y + playButton.getSize().y / 2 - playButtonText.getLocalBounds().height);

    // settings button
    settingsButton.setSize(sf::Vector2f(transparentBoxSizeX / 3, transparentBoxSizeY / 12));
    settingsButton.setFillColor(sf::Color(0, 0, 0, 100));
    settingsButton.setOutlineColor(sf::Color::White);
    settingsButton.setOutlineThickness(2.0f);
    settingsButton.setPosition(sf::Vector2f(transparentBox.getPosition().x + transparentBox.getSize().x / 3, 5 * transparentBox.getSize().y / 12));

    settingsButtonText.setFont(font);
    settingsButtonText.setCharacterSize(36);
    settingsButtonText.setFillColor(sf::Color::White);
    settingsButtonText.setString(settingsButtonTextString);
    settingsButtonText.setPosition(settingsButton.getPosition().x + settingsButton.getSize().x / 2 - settingsButtonText.getLocalBounds().width / 2, settingsButton.getPosition().y + settingsButton.getSize().y / 2 - settingsButtonText.getLocalBounds().height);

    // credits button
    creditsButton.setSize(sf::Vector2f(transparentBoxSizeX / 3, transparentBoxSizeY / 12));
    creditsButton.setFillColor(sf::Color(0, 0, 0, 100));
    creditsButton.setOutlineColor(sf::Color::White);
    creditsButton.setOutlineThickness(2.0f);
    creditsButton.setPosition(sf::Vector2f(transparentBox.getPosition().x + transparentBox.getSize().x / 3, 5 * transparentBox.getSize().y / 12 + 1 * (transparentBox.getSize().y / 8)));

    creditsButtonText.setFont(font);
    creditsButtonText.setCharacterSize(36);
    creditsButtonText.setFillColor(sf::Color::White);
    creditsButtonText.setString(creditsButtonTextString);
    creditsButtonText.setPosition(creditsButton.getPosition().x + creditsButton.getSize().x / 2 - creditsButtonText.getLocalBounds().width / 2, creditsButton.getPosition().y + creditsButton.getSize().y / 2 - creditsButtonText.getLocalBounds().height);

    // exit button
    exitButton.setSize(sf::Vector2f(transparentBoxSizeX / 3, transparentBoxSizeY / 12));
    exitButton.setFillColor(sf::Color(0, 0, 0, 100));
    exitButton.setOutlineColor(sf::Color::White);
    exitButton.setOutlineThickness(2.0f);
    exitButton.setPosition(sf::Vector2f(transparentBox.getPosition().x + transparentBox.getSize().x / 3, 5 * transparentBox.getSize().y / 12 + 2 * (transparentBox.getSize().y / 8)));

    exitButtonText.setFont(font);
    exitButtonText.setCharacterSize(36);
    exitButtonText.setFillColor(sf::Color::White);
    exitButtonText.setString(exitButtonTextString);
    exitButtonText.setPosition(exitButton.getPosition().x + exitButton.getSize().x / 2 - exitButtonText.getLocalBounds().width / 2, exitButton.getPosition().y + exitButton.getSize().y / 2 - exitButtonText.getLocalBounds().height);

    // big box outside credits
    boxForMenusSizeY = 7 * backgroundSize.y / 8;
    boxForMenusSizeX = backgroundSize.x - backgroundSize.y / 8;
    boxForMenus.setSize(sf::Vector2f(boxForMenusSizeX, boxForMenusSizeY));
    boxForMenus.setFillColor(sf::Color(0, 0, 0, 127));
    boxForMenus.setPosition(sf::Vector2f(backgroundSize.y / 16, backgroundSize.y / 16));
}

void mainMenu::Update(sf::RenderWindow& window, sf::Vector2f mousePosition, float deltaTime) {
    if (isOnMenu || isOnSettings || isOnCredits) {
        animationTime += deltaTime; // add the time since last frame change
        if (animationTime >= FRAME_DURATION) { // change the background if more than FRAME_DURATION has passed
            animationTime = 0.0f;
            currentFrame = (currentFrame + 1) % backgroundTextures.size();
            backgroundSprite.setTexture(backgroundTextures[currentFrame]);
        }
    }
}

void mainMenu::Render(sf::RenderWindow& window) {
    if (isOnMenu || isOnSettings || isOnCredits) {
        window.draw(backgroundSprite); // background GIF
    }

    if (isOnMenu) {
        window.draw(transparentBox); // transparent box behind the buttons

        window.draw(playButton);
        window.draw(settingsButton);
        window.draw(creditsButton);
        window.draw(exitButton);

        window.draw(playButtonText);
        window.draw(settingsButtonText);
        window.draw(creditsButtonText);
        window.draw(exitButtonText);
    }

    if (isOnCredits) {
        window.draw(boxForMenus);
    }

    if (isOnSettings) {
        window.draw(boxForMenus);
    }
}