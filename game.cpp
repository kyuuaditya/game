#include <iostream>
#include <sfml/Graphics.hpp>
#include "mainMenu.h"

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Run", sf::Style::Fullscreen, settings);
    window.setFramerateLimit(144);
    window.setVerticalSyncEnabled(true);

    mainMenu mainMenu;
    mainMenu.Initialize(sf::Vector2f(window.getSize().x, window.getSize().y));

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        float deltaTime = clock.restart().asMilliseconds();
        mainMenu.Update(window, deltaTime);

        window.clear();
        mainMenu.Render(window);
        window.display();
    }

    return 0;
}