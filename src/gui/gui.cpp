#include "gui.hpp"
#include <iostream>


// Constructor
Gui::Gui(sf::Font& loadedFont) : font(loadedFont) {
    
}


void Gui::LoadAssets() {

}

// Renders cards
void Gui::Draw(sf::RenderWindow& window) {
    for (auto& card : dealerCards)
        window.draw(card);
    for (auto& card : playerCards)
        window.draw(card);
}

// Gets card textures
sf::Texture& Gui::GetCardTexture(std::string& path) {
    if (cardTextures.find(path) == cardTextures.end()) {
        sf::Texture tex;
        if (!tex.loadFromFile(path))
            std::cerr << "Failed to load card texture: " << path << std::endl;
        cardTextures[path] = std::move(tex);
        return cardTextures[path];
    }
    return cardTextures.find(path) -> second;
}

// Reset rendering cards
void Gui::ResetCards() {
    playerCards.clear();
    dealerCards.clear();
}


// Rendering player cards
void Gui::ProcessPlayerCard(std::string cardPath) {
    sf::Sprite sprite(GetCardTexture(cardPath));
    sprite.setPosition(50.f + playerCards.size() * 100.f * 0.9f, 250.f);
    sprite.setScale(0.9f, 0.9f);
    playerCards.push_back(sprite);
}

// Rendering dealer cards
void Gui::ProcessDealerCard(std::string cardPath) {
    sf::Sprite sprite(GetCardTexture(cardPath));
    sprite.setPosition(50.f + dealerCards.size() * 100.f * 0.9f, 25.f);
    sprite.setScale(0.9f, 0.9f);
    dealerCards.push_back(sprite);
}

// Processing round end
void Gui::ProcessRoundResult(bool didPlayerWin) {
    ResetCards();
}