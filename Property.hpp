#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include "Space.hpp"
#include <string>

// Forward declaration of Player class
class Player;

class Property : public Space {
private:
    int price;             // Purchase price of the property
    int baseRent;          // Base rent without any houses or hotels
    int houseCost;         // Cost of building a house on this property
    int hotelCost;         // Cost of building a hotel on this property
    int rentWithHouse[4];  // Rent with 1, 2, 3, and 4 houses
    int rentWithHotel;     // Rent with a hotel
    Player* owner;         // Pointer to the owner of the property
    int houses;            // Number of houses built on this property
    bool hotel;            // Indicates if a hotel is built

public:
    // Constructor
    Property(std::string name, int price, int baseRent, int houseCost = 50, int hotelCost = 100);

    // Getter methods
    std::string getName() const ;
    int getPrice() const;
    int getRent() const;
    Player* getOwner() const;
    bool isOwned() const;

    // Ownership and building methods
    void setOwner(Player* newOwner);
    void buyHouse();
    void buyHotel();

    // Override landOn method from Space
    void landOn(Player* player) ;

    // Utility methods
    void displayPropertyInfo() const;
};

#endif
