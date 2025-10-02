#include "card.hpp"

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