#include "game-processing.hpp"
#include <iostream>


// Constructor
GameProcessing::GameProcessing() {
    state = GameState::WAITING_FOR_INPUT;
}

// New game
void GameProcessing::StartNewGame() {
    deck.Shuffle();
    player.ClearHand();
    dealer.ClearHand();
    DealInitialHand();
    state = GameState::PLAYER_TURN;
}

// Deal initial cards
void GameProcessing::DealInitialHand() {
    player.AddCard(deck.DrawCard());
    dealer.AddCard(deck.DrawCard());
    player.AddCard(deck.DrawCard());
    dealer.AddCard(deck.DrawCard()); // <- make it a hidden card

    std::cout << "player: " << player.GetTotal() << std::endl;
    std::cout << "dealer: " << dealer.GetTotal() << std::endl;
}

// Player hit event
void GameProcessing::PlayerHitEvent() {
    if (state != GameState::PLAYER_TURN)
        return;
    player.AddCard(deck.DrawCard());
    std::cout << "player: " << player.GetTotal() << std::endl;
    if (player.GetTotal() > 21)
        CheckCards();
}

// Player stand event
void GameProcessing::PlayerStandEvent() {
    if (state != GameState::PLAYER_TURN)
        return;
    state = GameState::DEALER_TURN;
    while (dealer.ProcessTurn(player.GetTotal())) {
        dealer.AddCard(deck.DrawCard());
        std::cout << dealer.GetTotal() << std::endl;
    }
    std::cout << "dealer: " << dealer.GetTotal() << std::endl;
    CheckCards();
}

// Checks for the winner
void GameProcessing::CheckCards() {
    state = GameState::INTERMISSION;
    int playerTotal = player.GetTotal();
    int dealerTotal = dealer.GetTotal();

    if (playerTotal > 21) {
        std::cout << "You lost" << std::endl;
    } else if (dealerTotal > 21) {
        std::cout << "You won" << std::endl;
    } else {
        if (playerTotal > dealerTotal) {
            std::cout << "You won" << std::endl;
        } else {
            std::cout << "You lost" << std::endl;
        }
    }
    GameProcessing::StartNewGame();
}