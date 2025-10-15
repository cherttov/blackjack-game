#include "game-processing.hpp"
#include <iostream>


// Constructor
GameProcessing::GameProcessing(Gui& guiRef) : gui(guiRef){
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
    Card temp;

    temp = deck.DrawCard();
    player.AddCard(temp);
    SendPlayerCards(temp);

    temp = deck.DrawCard();
    dealer.AddCard(temp);
    SendDealerCards(temp);

    temp = deck.DrawCard();
    player.AddCard(temp);
    SendPlayerCards(temp);

    temp = deck.DrawCard();
    dealer.AddCard(temp); // <- make it a hidden card
    SendDealerCards(temp);
}

// Player hit event
void GameProcessing::PlayerHitEvent() {
    if (state != GameState::PLAYER_TURN)
        return;

    Card temp = deck.DrawCard();
    player.AddCard(temp);
    SendPlayerCards(temp);

    if (player.GetTotal() > 21)
        CheckCards();
}

// Player stand event
void GameProcessing::PlayerStandEvent() {
    if (state != GameState::PLAYER_TURN)
        return;
    state = GameState::DEALER_TURN;
}

// For now just an alternative to a loop to not block main loop
void GameProcessing::ProcessDealerTurn() {
    if (state == GameState::DEALER_TURN) {
        if (dealer.ProcessTurn(player.GetTotal())) {
            Card temp = deck.DrawCard();
            dealer.AddCard(temp);
            SendDealerCards(temp);
        } else {
            CheckCards();
        }
    }
}

// Checks for the winner
void GameProcessing::CheckCards() {
    state = GameState::INTERMISSION;
    int playerTotal = player.GetTotal();
    int dealerTotal = dealer.GetTotal();
    bool temp;

    if (playerTotal > 21) {
        std::cout << "You lost" << std::endl;
        temp = false;
    } else if (dealerTotal > 21) {
        std::cout << "You won" << std::endl;
        temp = true;
    } else {
        if (playerTotal > dealerTotal) {
            std::cout << "You won" << std::endl;
            temp = true;
        } else {
            std::cout << "You lost" << std::endl;
            temp = false;
        }
    }

    // To waste time a bit, for now
    int delay = 0;
    for (int i = 0; i < 1000000000; i++) {
        delay = (i * 2 - 30 + 200) / 2 + 68 / 3;
        if (delay > 2)
            delay /= 3;
        else
            delay += 3;
    }

    SendRoundResult(temp);
    GameProcessing::StartNewGame();
}


// Gui helper functions
void GameProcessing::SendPlayerCards(Card& card) {
    std::string temp = GetTexturePath(card);
    int total = player.GetTotal();
    gui.ProcessPlayerCard(temp, total);
}

void GameProcessing::SendDealerCards(Card& card) {
    std::string temp = GetTexturePath(card);
    int total = dealer.GetTotal();
    gui.ProcessDealerCard(temp, total);
}

void GameProcessing::SendRoundResult(bool didPlayerWin) {
    gui.ProcessRoundResult(didPlayerWin);
}