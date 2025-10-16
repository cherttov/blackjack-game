#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "../other/mouse.hpp"
#include <iostream>


// const text size
#define TEXTSIZE 42


// Button class
class Button {
    public:
        // Constructor
        Button(sf::Font& fontRef,
               sf::Vector2f size,
               sf::Vector2f position,
               std::string displayedText,
               sf::Color rectColor,
               sf::Color textColor);
        
        // Mouse interaction functions
        bool HandleMouse(const Mouse& mouse);

        // Render function
        void Draw(sf::RenderWindow& window);

    private:
        // Font reference & text
        sf::Font& font;

        // Buttons objects
        sf::RectangleShape rect;
        sf::Text text;

        // Private functions
        sf::Vector2f AlignText();
};