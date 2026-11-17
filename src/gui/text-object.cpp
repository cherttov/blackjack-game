#include "text-object.hpp"


// Constructor
TextObject::TextObject(sf::Font& fontRef,
                       std::string displayedText,
                       int size,
                       sf::Color textColor,
                       sf::Vector2f position) 
    : font(fontRef),
      text(fontRef, displayedText, static_cast<unsigned int>(size))
{
    text.setFillColor(textColor);
    text.setPosition(position);  
}

// Renders text
void TextObject::Draw(sf::RenderWindow& window) {
    window.draw(text);
}