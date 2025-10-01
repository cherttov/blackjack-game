#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "mouse.hpp"

// Bounds struct
struct Bounds {
    sf::Vector2f min;
    sf::Vector2f max;
};

// Button class
class Button {
    public:
        // Constructor
        Button(sf::Font& font);

        // Parameters + defaults
        sf::Vector2f size = {200.f, 100.f};
        sf::Vector2f position = {0.f, 0.f};
        std::string displayedText = "Button";
        float textScale = 0.5f;

        // Mouse interaction functions
        bool HandleMouse(const Mouse& mouse);

        // Render function
        void Draw(sf::RenderWindow& window);

    private:
        // Bounds struct
        Bounds GetBounds() const;

        // Buttons objects
        sf::RectangleShape rect;
        sf::Text text;
        sf::Vector2f textPosition;

        // Private functions
        void AlignText();
};