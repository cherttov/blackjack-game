#pragma once
#include <string>

// Suits enum
enum class Suit {
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS
};

// Card struct
struct Card {
    Suit suit;
    std::string rank;
    int value;
};

// Int to card converter
Card IntToCard(int id);


// spade : 0 - 12
// heart : 13 - 25
// diamond : 26 - 38
// club : 39 - 51