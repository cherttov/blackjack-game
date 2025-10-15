#include "button.hpp"


// Constructor
Button::Button(sf::Font& fontRef,
               sf::Vector2f aSize,
               sf::Vector2f aPosition,
               std::string aDisplayedText,
               sf::Color aRectColor,
               sf::Color aTextColor) 
    : font(fontRef),
    size(aSize),
    position(aPosition),
    textPosition({0.f, 0.f})
{
    // Rect init
    rect.setSize(aSize);
    rect.setPosition(aPosition);
    rect.setFillColor(aRectColor);

    // Text init
    text.setFont(font);
    text.setString(aDisplayedText);
    text.setCharacterSize(TEXTSIZE);
    text.setFillColor(aTextColor);

    AlignText();
    text.setPosition(textPosition);
}

// Handling the mouse events
bool Button::HandleMouse(const Mouse& mouse) {
    if (mouse.clicked) {
        Bounds b = GetBounds();

        if (mouse.position.x >= b.min.x &&
            mouse.position.x <= b.max.x &&
            mouse.position.y >= b.min.y &&
            mouse.position.y <= b.max.y) {
                return true;
        }
    }
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
void Button::AlignText() {
    textPosition.x = position.x + size.x / 2.f - text.getLocalBounds().width / 2.f;
    textPosition.y = position.y + size.y / 2.f - text.getLocalBounds().height / 2.f - text.getLocalBounds().top;
}


// Get the bounds of the rectangle
Bounds Button::GetBounds() const {
    Bounds b;
    b.min = position;
    b.max = sf::Vector2f( position.x + size.x, position.y + size.y );
    return b;
}