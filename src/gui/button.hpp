#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "../other/mouse.hpp"
#include <iostream>


// const text size
#define TEXTSIZE 42

// Bounds struct
struct Bounds {
    sf::Vector2f min;
    sf::Vector2f max;
};

// Button class
class Button {
    public:
        // Constructor
        Button(sf::Font& fontRef,
               sf::Vector2f aSize,
               sf::Vector2f aPosition,
               std::string aDisplayedText,
               sf::Color aRectColor,
               sf::Color aTextColor);
        
        // Mouse interaction functions
        bool HandleMouse(const Mouse& mouse);

        // Render function
        void Draw(sf::RenderWindow& window);

    private:
        // Font reference
        sf::Font& font;
        
        // Const after constructor variables
        sf::Vector2f size;
        sf::Vector2f position;
        std::string displayedText;
        sf::Color rectColor;
        sf::Color textColor;

        // Bounds struct
        Bounds GetBounds() const;

        // Buttons objects
        sf::RectangleShape rect;
        sf::Text text;
        sf::Vector2f textPosition;

        // Private functions
        void AlignText();
};