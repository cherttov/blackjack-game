#include "card.hpp"


// Convert int to Card
Card IntToCard(int id) {
    static const char* ranks[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    static const int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

    Card c;
    int rankIndex = id % 13; // 0 - 12
    int suitIndex = id / 13; // 0 - 3

    c.rank = ranks[rankIndex];
    c.value = values[rankIndex];
    c.suit = (Suit)suitIndex;

    return c;
}

// Convert Card into path to texture
std::string GetTexturePath(Card& card) {
    std::string suitString;

    switch (card.suit) {
        case Suit::SPADES: suitString = "S"; break;
        case Suit::HEARTS: suitString = "H"; break;
        case Suit::DIAMONDS: suitString = "D"; break;
        case Suit::CLUBS: suitString = "C"; break;
    }

    return "assets/cards/" + suitString + card.rank + ".png";
}