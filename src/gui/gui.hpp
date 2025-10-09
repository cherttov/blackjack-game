#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>


// Gui class
class Gui {
    public:
        // Constructor
        Gui(sf::Font& loadedFont);

        // Load assets function
        void LoadAssets();

        // Game processing accepting functions
        void ProcessPlayerCard(std::string card);
        void ProcessDealerCard(std::string card);
        void ProcessRoundResult(bool didPlayerWin);

        // Render function
        void Draw(sf::RenderWindow& window); // Player&, Dealer&
    
    private:
        // Instantiate font reference
        sf::Font& font;

        // Instantiate texture map
        std::map<std::string, sf::Texture> cardTextures;
        std::vector<sf::Sprite> playerCards;
        std::vector<sf::Sprite> dealerCards;

        // Private helper functions
        sf::Texture& GetCardTexture(std::string& path);
        float CalculatePosition(size_t cardsAmount);
        void ResetCards();
};