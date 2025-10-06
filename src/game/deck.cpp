#include "deck.hpp"
#include <random>
#include <iostream>

// Constructor
Deck::Deck() {
    Shuffle();
}

// Destructor
Deck::~Deck() {
    if (cards) {
        delete[] cards;
        cards = nullptr;
    }
}

// Shuffles the deck (int)
void Deck::Shuffle() {
    // Declaration
    if (!cards)
        cards = new int[DECK_SIZE];
    
    for (int i = 0; i < DECK_SIZE; i++) {
        int temp = rand() % DECK_SIZE;
        bool exists = false;
        // Check if already in deck
        for (int j = 0; j < i; j++) {
            if (cards[j] == temp) {
                exists = true;
                break;
            }
        }
        // Retry || Set value
        if (exists == true) {
            i--; 
        } else {
            cards[i] = temp;
        }
    }

    currentIndex = 0;
}

// Checks and draws cards
Card Deck::DrawCard() {
    if (currentIndex >= DECK_SIZE) {
        delete[] cards;
        Shuffle();
    }

    int cardId = cards[currentIndex++];
    return IntToCard(cardId);
}