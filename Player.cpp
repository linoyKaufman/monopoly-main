// Player.cpp
#include "Player.hpp"
#include "Property.hpp"
#include <iostream>

// Constructor - Initializes a new player with a name, starting money, and position
Player::Player(string playerName) 
    : name(playerName), money(1500), position(0), inJail(false), jailTurns(0) {}

// Get the player's name
string Player::getName() const {
    return name;
}

// Get the player's position on the board
int Player::getPosition() const {
    return position;
}

// Get the amount of money the player currently has
int Player::getMoney() const {
    return money;
}

// Check if the player is in jail
bool Player::isInJail() const {
    return inJail;
}

// Move the player by a specified number of steps (wrap around the board if necessary)
void Player::move(int steps) {
    position = (position + steps) % 40; // Ensure position stays within 0 to 39 (circular board)
    std::cout << name << " moved to position " << position << std::endl;
}

// Deduct money from the player (used for paying rent, taxes, etc.)
void Player::deductMoney(int amount) {
    if (money >= amount) {
        money -= amount;
        std::cout << name << " has paid " << amount << " and now has " << money << " left." << std::endl;
    } else {
        std::cout << name << " doesn't have enough money!" << std::endl;
        // Handle bankruptcy or other game rules if needed
    }
}

// Add money to the player (used for collecting rent, passing GO, etc.)
void Player::addMoney(int amount) {
    money += amount;
    std::cout << name << " received " << amount << " and now has " << money << std::endl;
}

// Buy a property (if affordable), and add it to the player's list of owned properties
void Player::buyProperty(Property* property) {
    if (money >= property->getPrice()) {
        money -= property->getPrice();
        properties.push_back(property);
        property->setOwner(this);
        std::cout << name << " bought " << property->getName() << " for " << property->getPrice() << std::endl;
    } else {
        std::cout << name << " doesn't have enough money to buy " << property->getName() << std::endl;
    }
}

// Pay rent to another player (assuming the property is owned by someone else)
void Player::payRent(Property* property) {
    Player* owner = property->getOwner();
    if (owner != this) {
        int rent = property->getRent();
        deductMoney(rent);
        owner->addMoney(rent);
        std::cout << name << " paid " << rent << " in rent to " << owner->getName() << std::endl;
    }
}

// Go to jail (sets inJail flag and moves the player to the jail position)
void Player::goToJail() {
    inJail = true;
    position = 10;  // Jail is typically at position 10 on the board
    jailTurns = 0;  // Reset jail turn counter
    std::cout << name << " has been sent to jail!" << std::endl;
}

// Try to leave jail (e.g., by paying, rolling doubles, etc.)
void Player::attemptToLeaveJail() {
    if (jailTurns < 3) {
        jailTurns++;
        std::cout << name << " is still in jail for " << jailTurns << " turns." << std::endl;
    } else {
        payJailFine();
        inJail = false;
        std::cout << name << " has paid the fine and left jail." << std::endl;
    }
}

// Pay the fine to get out of jail
void Player::payJailFine() {
    if (money >= 50) {
        deductMoney(50);  // Jail fine is typically 50 units
        inJail = false;
        jailTurns = 0;
        std::cout << name << " paid the jail fine and is now free." << std::endl;
    } else {
        std::cout << name << " cannot afford the jail fine!" << std::endl;
    }
}

// Display the list of properties owned by the player
void Player::displayProperties() const {
    if (properties.empty()) {
        std::cout << name << " owns no properties." << std::endl;
    } else {
        std::cout << name << " owns the following properties:" << std::endl;
        for (auto* property : properties) {
            std::cout << " - " << property->getName() << std::endl;
        }
    }
}

// Check if the player has enough money to continue in the game
bool Player::isBankrupt() const {
    return money <= 0;
}
