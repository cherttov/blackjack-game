#include "dealer.hpp"


// Add card to hand
void Dealer::AddCard(const Card& card) {
    hand.push_back(card);
}

// Clear hand
void Dealer::ClearHand() {
    hand.clear();
}

// Get total value of hand
int Dealer::GetTotal() {
    int total = 0;
    int aces = 0;

    for (int i = 0; i < hand.size(); i++) {
        if (hand[i].value == 1) {
            aces++;
        }
        total += hand[i].value; 
    }
    if (aces > 0) {
        for (int i = 0; i < aces; i++) {
            if (total + 10 <= 21) {
                total += 10;
                aces--;
            }
        }
    }

    return total;
}

// Calculate dealer's next move
bool Dealer::ProcessTurn(int playerHandValue) {
    int total = Dealer::GetTotal();
    if (playerHandValue > total) {
        if (total < 17)
            return true;
    }
    return false;
}
