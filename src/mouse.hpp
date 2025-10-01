#pragma once
#include <SFML/Graphics.hpp>

// Mouse class
class Mouse {
    public:
        // Button states
        bool isPressed = false;
        bool clicked = false;

        // Position vector
        sf::Vector2f position;

        // Update function
        void Update(sf::RenderWindow& window);
};