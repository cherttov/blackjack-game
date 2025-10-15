#include "game-processing.hpp"


// Constructor
GameProcessing::GameProcessing(Gui& guiRef) : gui(guiRef){
    state = GameState::WAITING_FOR_INPUT;
    StartNewGame();
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
    bool didPlayerWin;

    if (playerTotal > 21) {
        std::cout << "You lost" << std::endl;
        didPlayerWin = false;
    } else if (dealerTotal > 21) {
        std::cout << "You won" << std::endl;
        didPlayerWin = true;
    } else {
        if (playerTotal > dealerTotal) {
            std::cout << "You won" << std::endl;
            didPlayerWin = true;
        } else {
            std::cout << "You lost" << std::endl;
            didPlayerWin = false;
        }
    }

    SendRoundResult(didPlayerWin);
    StartNewGame();
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