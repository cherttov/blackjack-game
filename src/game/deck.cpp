#include "deck.hpp"
#include <random>
#include <iostream>

// Constructor
Deck::Deck() {
    cards = Shuffle();
}

// Destructor
Deck::~Deck() {
    if (cards) {
        delete[] cards;
        cards = nullptr;
    }
}

// Shuffles the deck (int)
int* Deck::Shuffle() {
    // Declaration
    int* arr = new int[DECK_SIZE];
    
    for (int i = 0; i < DECK_SIZE; i++) {
        int temp = rand() % DECK_SIZE;
        bool exists = false;
        // Check if already in deck
        for (int j = 0; j < i; j++) {
            if (arr[j] == temp) {
                exists = true;
                break;
            }
        }
        // Retry || Set value
        if (exists == true) {
            i--; 
        } else {
            arr[i] = temp;
        }
    }

    currentIndex = 0;
    return arr;
}

// Checks and draws cards
Card Deck::DrawCard() {
    if (currentIndex >= DECK_SIZE) {
        delete[] cards;
        cards = Shuffle();
    }

    int cardId = cards[currentIndex++];
    return IntToCard(cardId);
}