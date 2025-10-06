#pragma once
#include <vector>
#include "card.hpp"

//
class Player {
    public:
        void AddCard(const Card& card);
        void ClearHand();

        int GetTotal();

    private:
        std::vector<Card> hand;
};