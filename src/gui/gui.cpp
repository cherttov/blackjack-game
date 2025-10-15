#include "gui.hpp"


// Constructor
Gui::Gui(sf::Font& fontRef) 
    : font(fontRef),
    playerText(fontRef, "0", 30, sf::Color::White, {230.f, 210.f}),
    dealerText(fontRef, "0", 30, sf::Color::White, {230.f, 140.f})
{
    Gui::ResetCards();
}

// Renders cards
void Gui::Draw(sf::RenderWindow& window) {
    // Cards
    for (auto& card : dealerCards)
        window.draw(card);
    for (auto& card : playerCards)
        window.draw(card);
    
    // Count text
    playerText.setString(std::to_string(playerTotal));
    playerText.Draw(window);

    dealerText.setString(std::to_string(dealerTotal));
    dealerText.Draw(window);
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
    playerTotal = 0;
    dealerTotal = 0;
}


// Rendering player cards
void Gui::ProcessPlayerCard(std::string cardPath, int total) {
    sf::Sprite sprite(GetCardTexture(cardPath));
    sprite.setPosition(50.f + playerCards.size() * 100.f * 0.9f, 250.f);
    sprite.setScale(0.9f, 0.9f);
    playerCards.push_back(sprite);
    playerTotal = total;
}

// Rendering dealer cards
void Gui::ProcessDealerCard(std::string cardPath, int total) {
    sf::Sprite sprite(GetCardTexture(cardPath));
    sprite.setPosition(50.f + dealerCards.size() * 100.f * 0.9f, 25.f);
    sprite.setScale(0.9f, 0.9f);
    dealerCards.push_back(sprite);
    dealerTotal = total;
}

// Processing round end
void Gui::ProcessRoundResult(bool didPlayerWin) {
    ResetCards();
}