#include "button.hpp"


// Constructor
Button::Button(sf::Font& fontRef,
               sf::Vector2f size,
               sf::Vector2f position,
               std::string displayedText,
               sf::Color rectColor,
               sf::Color textColor) 
    : font(fontRef)
{
    // Rect init
    rect.setSize(size);
    rect.setPosition(position);
    rect.setFillColor(rectColor);

    // Text init
    text.setFont(font);
    text.setString(displayedText);
    text.setCharacterSize(TEXTSIZE);
    text.setFillColor(textColor);

    text.setPosition(AlignText());
}

// Handling the mouse events
bool Button::HandleMouse(const Mouse& mouse) {
    if (mouse.clicked)
        if (rect.getGlobalBounds().contains(mouse.position))
            return true;
    return false;
}

// Button rendering
void Button::Draw(sf::RenderWindow& window) {
    // Rectangle
    window.draw(rect);
    // Text
    window.draw(text);
}

// Aligns text to the middle of the rectangle
sf::Vector2f Button::AlignText() {
    return sf::Vector2f(
        rect.getPosition().x + (rect.getSize().x / 2.f) - (text.getLocalBounds().width / 2.f),
        rect.getPosition().y + (rect.getSize().y / 2.f - text.getLocalBounds().height / 2.f) - text.getLocalBounds().top
    );
}