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
    SendPlayerCards(temp);
    player.AddCard(temp);

    temp = deck.DrawCard();
    SendPlayerCards(temp);
    dealer.AddCard(temp);

    temp = deck.DrawCard();
    SendDealerCards(temp);
    player.AddCard(temp);

    temp = deck.DrawCard();
    SendDealerCards(temp);
    dealer.AddCard(temp); // <- make it a hidden card

    std::cout << "player: " << player.GetTotal() << std::endl;
    std::cout << "dealer: " << dealer.GetTotal() << std::endl;
}

// Player hit event
void GameProcessing::PlayerHitEvent() {
    if (state != GameState::PLAYER_TURN)
        return;

    Card temp = deck.DrawCard();
    SendPlayerCards(temp);
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
        Card temp = deck.DrawCard();
        SendDealerCards(temp);
        dealer.AddCard(temp);
    }
    std::cout << "dealer: " << dealer.GetTotal() << std::endl;
    CheckCards();
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

    SendRoundResult(temp);
    GameProcessing::StartNewGame();
}


// Gui helper functions
void GameProcessing::SendPlayerCards(Card& card) {
    std::string temp = GetTexturePath(card);
    gui.ProcessPlayerCard(temp);
}

void GameProcessing::SendDealerCards(Card& card) {
    std::string temp = GetTexturePath(card);
    gui.ProcessDealerCard(temp);
}

void GameProcessing::SendRoundResult(bool didPlayerWin) {
    gui.ProcessRoundResult(didPlayerWin);
}