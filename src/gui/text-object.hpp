#pragma once
#include <SFML/Graphics.hpp>
#include <string>


// Text class
class TextObject {
    public:
        // Constructor
        TextObject(sf::Font& fontRef,
                   std::string displayedText,
                   int size,
                   sf::Color textColor,
                   sf::Vector2f position);

        // Render function
        void Draw(sf::RenderWindow& window);

        // Setters
        void setString(std::string newDisplayedText) {
            text.setString(newDisplayedText);
        }

    private:
        // Instantiate font reference & text object
        sf::Font& font;
        sf::Text text;
};