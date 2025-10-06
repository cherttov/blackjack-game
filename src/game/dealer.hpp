#pragma once
#include <vector>
#include "card.hpp"

//
class Dealer {
    public:
        void AddCard(const Card& card);
        void ClearHand();

        int GetTotal();

        bool ProcessTurn(int playerHandValue);

    private:
        std::vector<Card> hand;
};