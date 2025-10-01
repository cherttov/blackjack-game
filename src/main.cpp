// Libraries
#include <SFML/Graphics.hpp>
#include <iostream>

// Other code
#include "mouse.hpp"
#include "deck.hpp"
#include "button.hpp"


int main() {
    // Define window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Blackjack Game", sf::Style::Close);
    window.setFramerateLimit(30);

    // Instantiate mouse
    Mouse mouse;

    // Load font
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font\n";
    }

    // Instantiate button
    Button button(font);

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
        //std::cout << mouse.position.x << ":" << mouse.position.y << std::endl;

        // Button event
        if (button.HandleMouse(mouse)) {
            std::cout << "Button Clicked!" << std::endl;
        }

        // Window clearing
        window.clear(sf::Color::Black); // <-- From here

        // Button
        button.Draw(window);

        // Window updating
        window.display(); // <-- To here
    }
    return 0;
}