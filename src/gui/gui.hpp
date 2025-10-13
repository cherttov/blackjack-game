#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "text-object.hpp"


// Gui class
class Gui {
    public:
        // Constructor
        Gui(sf::Font& fontRef);

        // Game processing accepting functions
        void ProcessPlayerCard(std::string card, int total);
        void ProcessDealerCard(std::string card, int total);
        void ProcessRoundResult(bool didPlayerWin);

        // Render function
        void Draw(sf::RenderWindow& window); // Player&, Dealer&
    
    private:
        // Instantiate font reference
        sf::Font& font;

        // Instantiate counter text
        TextObject playerText;
        // TextObject dealerText;

        int playerTotal = 0;
        int dealerTotal = 0;

        // Instantiate texture map
        std::map<std::string, sf::Texture> cardTextures;
        std::vector<sf::Sprite> playerCards;
        std::vector<sf::Sprite> dealerCards;

        // Private helper functions
        sf::Texture& GetCardTexture(std::string& path);
        float CalculatePosition(size_t cardsAmount);
        void ResetCards();
};