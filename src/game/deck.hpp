#pragma once
#include "card.hpp"

#define DECK_SIZE 52

class Deck {
    public:
        // Constructor | Destructor
        Deck();
        ~Deck();

        // Game functions
        void Shuffle();
        Card DrawCard();

    private:
        // Private variables
        int* cards;
        int currentIndex;
};