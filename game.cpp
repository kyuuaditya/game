#include <iostream>
#include <sfml/Graphics.hpp>
#include "mainMenu.h"

int main() {
    // Create the window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Run", sf::Style::Fullscreen, settings);
    window.setFramerateLimit(144);
    window.setVerticalSyncEnabled(true);

    // define class object
    mainMenu mainMenu;

    // load
    mainMenu.Load(sf::Vector2f(window.getSize().x, window.getSize().y));

    // initialize 
    mainMenu.Initialize();

    sf::Clock clock; // main clock
    while (window.isOpen()) {
        // event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) { // close window on pressing escape
                    window.close();
                }
            }
        }

        float deltaTime = clock.restart().asMilliseconds(); // restart the clock and get the time since last frame
        mainMenu.Update(window, deltaTime);

        window.clear();
        mainMenu.Render(window);
        window.display();
    }

    return 0;
}