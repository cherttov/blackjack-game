#include "player.hpp"


// Add card to hand
void Player::AddCard(const Card& card) {
    hand.push_back(card);
}

// Clear hand
void Player::ClearHand() {
    hand.clear();
}

// Get total value of hand
int Player::GetTotal() {
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

