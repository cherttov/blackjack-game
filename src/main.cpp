// Libraries
#include <SFML/Graphics.hpp>
#include <iostream>

// Other code
#include "other/mouse.hpp"
#include "game/deck.hpp"
#include "game/card.hpp"
#include "gui/button.hpp"


int main() {
    // Define window
    sf::Vector2u windowSize(500, 500);
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Blackjack Game", sf::Style::Close);
    window.setFramerateLimit(30);

    // Instantiate mouse
    Mouse mouse;
    int posDelay = 0;

    // Load font
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font\n";
    }
    
    // Instantiate buttons
    sf::Vector2f buttonsSize(windowSize.x / 2.f, windowSize.y / 4.f);

    Button hitButton(font);
    hitButton.position = { 0.f, windowSize.y - buttonsSize.y };
    hitButton.size = buttonsSize;
    hitButton.displayedText = "HIT";
    hitButton.rectColor = sf::Color::Green;
    
    Button standButton(font);
    standButton.position = { buttonsSize.x, windowSize.y - buttonsSize.y };
    standButton.size = buttonsSize;
    standButton.displayedText = "STAND";
    standButton.rectColor = sf::Color::Red;


    // Main loop
    while (window.isOpen()) {
        // Close window event
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Mouse event
        mouse.Update(window);
        if (mouse.clicked)
            std::cout << "Clicked\n";
        posDelay++;
        if (posDelay == 15) {
            std::cout << mouse.position.x << ":" << mouse.position.y << std::endl;
            posDelay = 0;
        }

        // Button event
        if (hitButton.HandleMouse(mouse)) {
            std::cout << "HIT" << std::endl;
        }
        if (standButton.HandleMouse(mouse)) {
            std::cout << "STAND" << std::endl;
        }

        // Window clearing
        window.clear(sf::Color::Black); // <-- Rendering from here

        // Buttons rendering
        hitButton.Draw(window);
        standButton.Draw(window);

        // Window updating
        window.display(); // <-- Rendering to here
    }
    return 0;
}