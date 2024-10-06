#include "SpecialSpace.hpp"
#include <iostream>

using namespace std;

// Constructor to initialize the special space with its name
SpecialSpace::SpecialSpace(const std::string& name) : Space(name) {}

// Override the landOn method to define behavior when a player lands on the special space
void SpecialSpace::landOn(Player* player) {
    cout << player->getName() << " landed on " << name << "." << endl;

    // Define behavior based on the type of special space
    if (name == "Go") {
        cout << player->getName() << " collects $200 for passing Go!" << endl;
        player->addMoney(200);
    } else if (name == "Income Tax") {
        cout << player->getName() << " must pay $200 in income tax." << endl;
        player->deductMoney(200);
    } else if (name == "Luxury Tax") {
        cout << player->getName() << " must pay $100 in luxury tax." << endl;
        player->deductMoney(100);
    } else if (name == "Go to Jail") {
        cout << player->getName() << " must go directly to jail!" << endl;
        player->goToJail();
    } else {
        // Other special spaces (Community Chest, Chance, etc.)
        cout << "Special space action for " << name << " is not defined yet." << endl;
    }
}
