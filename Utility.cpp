#include "Utility.hpp"
#include <iostream>

using namespace std;

// Constructor to initialize the utility with a name and price
Utility::Utility(string name, int price) 
    : Space(name),  // Call Space constructor
      price(price), 
      owner(nullptr) {}

// Get the name of the utility
string Utility::getName() const {
    return name;
}

// Get the price of the utility
int Utility::getPrice() const {
    return price;
}

// Set the owner of the utility
void Utility::setOwner(Player* newOwner) {
    owner = newOwner;
}

// Get the owner of the utility
Player* Utility::getOwner() const {
    return owner;
}

// Calculate the rent based on the number of utilities owned and the dice roll
int Utility::getRent(int diceRoll, int ownedUtilities) const {
    if (ownedUtilities == 2) {
        return 10 * diceRoll;  // Rent is 10 times the dice roll if both utilities are owned
    } else {
        return 4 * diceRoll;   // Rent is 4 times the dice roll if only one utility is owned
    }
}

// Handle the event when a player lands on the utility
void Utility::landOn(Player* player) {
    if (owner == nullptr) {
        cout << player->getName() << " landed on " << name << ". It's available for purchase for $" << price << "." << endl;
        // Logic for purchasing the utility can be added here
    } else if (owner == player) {
        cout << player->getName() << " landed on their own utility." << endl;
    } else {
        // int diceRoll = rand() % 6 + 1 + rand() % 6 + 1;  // Simulate rolling two dice
        // int rent = getRent(diceRoll, owner->getNumberOfUtilities());  // Assume Player class has this method
        // player->deductMoney(rent);
        // owner->addMoney(rent);
        // cout << player->getName() << " rolled a " << diceRoll << " and paid $" << rent << " to " << owner->getName() << " for landing on " << name << "." << endl;
    }
}
