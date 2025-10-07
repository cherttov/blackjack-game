#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>


// Gui class
class Gui {
    public:
        // Constructor
        Gui(sf::Font& loadedFont);

        // Load assets function
        void LoadAssets();

        // Render function
        void Draw(sf::RenderWindow& window); // Player&, Dealer&
    
    private:
        // Instantiate texture map
        std::map<std::string, sf::Texture> cardTextures;

        // Instantiate font reference
        sf::Font& font;

        // Convert Card to string
        //std::string CardToString(const Card& card);
};