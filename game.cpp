#include <iostream>
#include <sfml/Graphics.hpp>
#include "mainMenu.h"
#include "checks.h"
#include "player.h"

int main() {
    // Create the window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Run", sf::Style::Fullscreen, settings);
    window.setFramerateLimit(144);
    window.setVerticalSyncEnabled(true);

    // define class object
    mainMenu mainMenu;
    checks checks;
    player player;

    // load
    mainMenu.Load();
    player.Load();

    // initialize 
    mainMenu.Initialize(sf::Vector2f(window.getSize().x, window.getSize().y));
    player.Initialize(sf::Vector2f(window.getSize().x, window.getSize().y));

    sf::Clock clock; // main clock
    sf::Vector2f mousePosition;
    while (window.isOpen()) {
        mousePosition = sf::Vector2f(sf::Mouse::getPosition(window)); // get the mouse position
        // -------------------------------------------event handling-------------------------------------------
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) { // close window on pressing escape
                    if (mainMenu.isOnMenu) {
                        window.close();
                    }
                    if (mainMenu.isInGame) {
                        mainMenu.isInGame = false;
                        mainMenu.isOnMenu = true;
                    }
                }
                if (event.key.code == sf::Keyboard::D) {
                    player.xIndex = (player.xIndex + 1) % 7;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (checks.isMouseOverButton(mainMenu.playButton, mousePosition)) {
                        mainMenu.isOnMenu = false;
                        mainMenu.isInGame = true;
                    }
                    if (checks.isMouseOverButton(mainMenu.settingsButton, mousePosition)) {
                        mainMenu.isOnMenu = false;
                        mainMenu.isOnSettings = true;
                    }
                    if (checks.isMouseOverButton(mainMenu.creditsButton, mousePosition)) {
                        mainMenu.isOnMenu = false;
                        mainMenu.isOnCredits = true;
                    }
                    if (checks.isMouseOverButton(mainMenu.exitButton, mousePosition)) {
                        window.close();
                    }
                }
            }
        }
        // -------------------------------------------event handling-------------------------------------------

        // TODO ------------------------------------------- update -------------------------------------------
        float deltaTime = clock.restart().asMilliseconds(); // restart the clock and get the time since last frame
        mainMenu.Update(window, mousePosition, deltaTime);
        player.Update(window, mousePosition, deltaTime, mainMenu.isInGame);
        // TODO ------------------------------------------- update -------------------------------------------

        // ------------------------------------------- display -------------------------------------------
        window.clear();
        mainMenu.Render(window);
        player.Render(window, mainMenu.isInGame);
        window.display();
        // ------------------------------------------- display -------------------------------------------
    }

    return 0;
}