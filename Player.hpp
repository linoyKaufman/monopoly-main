#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Property.hpp"

using namespace std;

class Property;

class Player {
private:
    string name;                   // The name of the player
    int money;                     // The amount of money the player has
    int position;                  // The player's position on the board (0 to 39)
    bool inJail;                   // Flag indicating if the player is in jail
    int jailTurns;                 // Number of turns the player has been in jail
    vector<Property*> properties;  // List of properties the player owns

public:
    // Constructor - Initializes a new player with a name, starting money, and position
    Player(string playerName);

    // Get the player's name
    string getName() const;

    // Get the player's position on the board
    int getPosition() const;

    // Get the amount of money the player currently has
    int getMoney() const;

    // Check if the player is in jail
    bool isInJail() const;

    // Move the player by a specified number of steps (wrap around the board if necessary)
    void move(int steps);

    // Deduct money from the player (used for paying rent, taxes, etc.)
    void deductMoney(int amount);

    // Add money to the player (used for collecting rent, passing GO, etc.)
    void addMoney(int amount);

    // Buy a property (if affordable), and add it to the player's list of owned properties
    void buyProperty(Property* property);

    // Pay rent to another player (assuming the property is owned by someone else)
    void payRent(Property* property);

    // Go to jail (sets inJail flag and moves the player to the jail position)
    void goToJail();

    // Try to leave jail (e.g., by paying, rolling doubles, etc.)
    void attemptToLeaveJail();

    // Pay the fine to get out of jail
    void payJailFine();

    // Display the list of properties owned by the player
    void displayProperties() const;

    // Check if the player has enough money to continue in the game
    bool isBankrupt() const;
};
#endif
