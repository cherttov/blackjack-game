#pragma once
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "deck.hpp"
#include "dealer.hpp"
#include "../gui/gui.hpp"
#include <iostream>



// Game state enum
enum class GameState {
    WAITING_FOR_INPUT,
    PLAYER_TURN,
    DEALER_TURN,
    INTERMISSION,
    END_OF_ROUND
};


// Game processing class
class GameProcessing {
    public:
        // Constructor
        GameProcessing(Gui& guiRef);

        // Game processing events
        void StartNewGame();
        void CheckCards();
        void ProcessDealerTurn();

        // Player events
        void PlayerHitEvent(); // Hit button
        void PlayerStandEvent(); // Stand button
    
    private:
        // Private variables
        GameState state;
        Player player;
        Dealer dealer;
        Deck deck;
        int actionDelay = 0;

        // Gui ref
        Gui& gui;
        
        // Private function
        void DealInitialHand();

        // Gui helper functions
        void SendPlayerCards(Card& card);
        void SendDealerCards(Card& card);
        void SendRoundResult(bool didPlayerWin);
};
