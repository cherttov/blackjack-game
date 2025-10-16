// Libraries
#include <SFML/Graphics.hpp>
#include <iostream>

// Other code
#include "other/mouse.hpp"
#include "gui/button.hpp"
#include "gui/gui.hpp"
#include "game/game-processing.hpp"



int main() {
    // Define window
    sf::Vector2u windowSize(500, 500);
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Blackjack Game", sf::Style::Close);
    window.setFramerateLimit(60);

    // Instantiate mouse
    Mouse mouse;

    // Load font
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font\n";
        return 1;
    }
    
    // Instantiate GUI
    Gui gui(font);

    // Instantiate buttons
    sf::Vector2f buttonsSize(windowSize.x / 2.f, windowSize.y / 4.f);
    sf::Vector2f hitPos = { 0.f, windowSize.y - buttonsSize.y };
    sf::Vector2f standPos = { buttonsSize.x, windowSize.y - buttonsSize.y };

    Button hitButton(font,
                     buttonsSize,
                     hitPos,
                     "HIT",
                     sf::Color::Green,
                     sf::Color::Black);

    Button standButton(font,
                       buttonsSize,
                       standPos,
                       "STAND",
                       sf::Color::Red,
                       sf::Color::Black);

    // Instantiate game processor
    GameProcessing gameProcessor(gui);


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

        // Button events
        if (hitButton.HandleMouse(mouse)) {
            gameProcessor.PlayerHitEvent();
        }
        if (standButton.HandleMouse(mouse)) {
            gameProcessor.PlayerStandEvent();
        }

        // Window clearing
        window.clear(sf::Color(0, 93, 34)); // <-- Rendering from here

        gameProcessor.ProcessDealerTurn();

        // GUI rendering
        gui.Draw(window);

        // Buttons rendering
        hitButton.Draw(window);
        standButton.Draw(window);

        // Window updating
        window.display(); // <-- Rendering to here
    }
    return 0;
}