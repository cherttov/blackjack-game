#pragma once
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "deck.hpp"
#include "dealer.hpp"


// Game state enum
enum class GameState {
    WAITING_FOR_INPUT,
    PLAYER_TURN,
    DEALER_TURN,
    INTERMISSION
};


// Game processing class
class GameProcessing {
    public:
        // Constructor
        GameProcessing();

        // Game processing events
        void StartNewGame();
        void CheckCards();

        // Player events
        void PlayerHitEvent(); // Hit button
        void PlayerStandEvent(); // Stand button
    
    private:
        GameState state;
        Player player;
        Dealer dealer;
        Deck deck;
        
        void DealInitialHand();
};
