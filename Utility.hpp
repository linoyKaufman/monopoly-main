#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
#include "Space.hpp"
#include "Player.hpp"

class Utility : public Space {
private:
    std::string name;    // Utility name
    int price;           // Purchase price of the utility
    Player* owner;       // Owner of the utility

public:
    // Constructor to initialize the utility with a name and price
    Utility(std::string name, int price);

    // Get the name of the utility
    std::string getName() const ;

    // Get the price of the utility
    int getPrice() const;

    // Set the owner of the utility
    void setOwner(Player* newOwner);

    // Get the owner of the utility
    Player* getOwner() const;

    // Calculate the rent based on the dice roll and number of utilities owned
    int getRent(int diceRoll, int ownedUtilities) const;

    // Handle the event when a player lands on the utility
    void landOn(Player* player) override;
};

#endif // UTILITY_HPP
