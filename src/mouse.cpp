#include "mouse.hpp"
#include <SFML/Graphics.hpp>

void Mouse::Update(sf::RenderWindow& window) {
    position = sf::Vector2f(sf::Mouse::getPosition(window));

    clicked = false;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        isPressed = true;
    } else {
        if (isPressed)
            clicked = true;
        isPressed = false;
    }
}