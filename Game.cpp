#include "Game.hpp"
#include <iostream>
#include <cstdlib>  // For rand() in dice roll

using namespace std;

// Constructor: Initialize the game with the specified number of players
Game::Game(int numPlayers) : currentPlayerIndex(0), gameOver(false) {
    // Initialize the board
    gameBoard = Board();

    // Create players and add them to the game
    for (int i = 0; i < numPlayers; i++) {
        string playerName = "Player " + to_string(i + 1);
        players.push_back(new Player(playerName));
    }

    cout << "Game initialized with " << numPlayers << " players." << endl;
}

// Destructor: Clean up dynamically allocated players
Game::~Game() {
    for (Player* player : players) {
        delete player;
    }
}

// Start the game loop
void Game::start() {
    while (!gameOver) {
        // Get the current player based on the index
        Player* currentPlayer = players[currentPlayerIndex];

        // Handle the current player's turn
        handlePlayerTurn(currentPlayer);

        // Check if the game is over
        if (isGameOver()) {
            gameOver = true;
            cout << currentPlayer->getName() << " wins the game!" << endl;
        }

        // Move to the next player
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }
}

// Roll two dice and return the sum
int Game::rollDice() const {
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    cout << "Rolled: " << die1 << " + " << die2 << " = " << (die1 + die2) << endl;
    return die1 + die2;
}

// Move the player based on the number of steps rolled
void Game::movePlayer(Player* player, int steps) {
    player->move(steps);
    handleLanding(player);  // Handle what happens when they land on a space
}

// Handle player landing on a space (e.g., buying property, paying rent)
void Game::handleLanding(Player* player) {
    int position = player->getPosition();
    Space* space = gameBoard.getSpace(position);

    if (space != nullptr) {
        cout << player->getName() << " landed on " << space->getName() << endl;
        space->landOn(player);  // Each space has its own behavior
    } else {
        cout << "Error: Invalid space!" << endl;
    }
}

// Handle a player's turn
void Game::handlePlayerTurn(Player* player) {
    cout << player->getName() << "'s turn." << endl;

    // Roll the dice
    int roll = rollDice();

    // Move the player
    movePlayer(player, roll);

    // Check if the player is bankrupt
    if (player->isBankrupt()) {
        cout << player->getName() << " is bankrupt and out of the game." << endl;
        // Logic to remove bankrupt players from the game
    }
}

// Check if the game is over (all but one player bankrupt)
bool Game::isGameOver() {
    int activePlayers = 0;
    for (Player* player : players) {
        if (!player->isBankrupt()) {
            activePlayers++;
        }
    }
    return activePlayers == 1;
}
