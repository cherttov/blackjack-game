#include "button.hpp"
#include <SFML/Graphics.hpp>

// Constructor
Button::Button(sf::Font& font) {
    text.setFont(font);
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
    rect.setSize(size);
    rect.setPosition(position);
    rect.setFillColor(rectColor);
    window.draw(rect);

    // Text
    text.setString(displayedText);
    text.setCharacterSize(size.y * textScale);
    text.setFillColor(textColor);
    AlignText(); // <-- I tried not calling it every frame, but it doesn't want to work
    text.setPosition(textPosition);
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