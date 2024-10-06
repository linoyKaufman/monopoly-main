#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "Player.hpp"
#include "Board.hpp"

class Game {
private:
    Board gameBoard;                // The board object that holds all the spaces
    std::vector<Player*> players;   // List of players in the game
    int currentPlayerIndex;         // Index to track which player's turn it is
    bool gameOver;                  // Flag to check if the game has ended

    // Function to handle player actions on their turn
    void handlePlayerTurn(Player* player);

    // Function to check if the game is over (all but one player bankrupt)
    bool isGameOver();

public:
    // Constructor to initialize the game with a set number of players
    Game(int numPlayers);

    // Destructor to clean up dynamically allocated memory (players)
    ~Game();

    // Start the game and manage the main game loop
    void start();

    // Roll two dice and return the sum
    int rollDice() const;

    // Move the current player based on the dice roll
    void movePlayer(Player* player, int steps);

    // Handle game logic when a player lands on a space
    void handleLanding(Player* player);
};

#endif  // GAME_HPP
