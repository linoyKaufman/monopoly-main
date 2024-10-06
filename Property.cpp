#include "Property.hpp"
#include <iostream>
#include "Player.hpp"
#include "Space.hpp"

using namespace std;

// Constructor for Property
Property::Property(string name, int price, int baseRent, int houseCost, int hotelCost)
    : Space(name), price(price), baseRent(baseRent), houseCost(houseCost), hotelCost(hotelCost), owner(nullptr), houses(0), hotel(false) {
    // Initialize rent with houses
    rentWithHouse[0] = baseRent * 5;   // Rent with 1 house
    rentWithHouse[1] = baseRent * 15;  // Rent with 2 houses
    rentWithHouse[2] = baseRent * 30;  // Rent with 3 houses
    rentWithHouse[3] = baseRent * 50;  // Rent with 4 houses
    rentWithHotel = baseRent * 100;    // Rent with a hotel
}

// Getter for the property name (overrides the Space's getName)
string Property::getName() const {
    return name;
}

// Getter for the purchase price of the property
int Property::getPrice() const {
    return price;
}

// Getter for the rent - depends on the number of houses/hotel built
int Property::getRent() const {
    if (hotel) {
        return rentWithHotel;  // Rent with a hotel
    } else if (houses > 0) {
        return rentWithHouse[houses - 1];  // Rent with houses
    } else {
        return baseRent;  // Base rent if no houses/hotels
    }
}

// Getter for the owner of the property
Player* Property::getOwner() const {
    return owner;
}

// Check if the property is owned by a player
bool Property::isOwned() const {
    return owner != nullptr;
}

// Set the owner of the property
void Property::setOwner(Player* newOwner) {
    owner = newOwner;
}

// Buy a house on the property
void Property::buyHouse() {
    if (houses < 4 && !hotel) {
        houses++;
        cout << owner->getName() << " built a house on " << name << ". Now has " << houses << " houses." << endl;
    } else {
        cout << "Cannot build more houses on " << name << endl;
    }
}

// Buy a hotel on the property (only allowed if there are 4 houses)
void Property::buyHotel() {
    if (houses == 4 && !hotel) {
        hotel = true;
        houses = 0;  // Reset the number of houses when a hotel is built
        cout << owner->getName() << " built a hotel on " << name << endl;
    } else {
        cout << "You need 4 houses before building a hotel on " << name << endl;
    }
}

// Override the landOn method from Space - handles what happens when a player lands on this property
void Property::landOn(Player* player) {
    if (isOwned()) {
        if (player != owner) {
            // If the property is owned by another player, pay rent
            int rent = getRent();
            cout << player->getName() << " landed on " << name << " owned by " << owner->getName() << ". Rent is $" << rent << "." << endl;
            player->deductMoney(rent);  // Deduct rent from the player landing on the property
            owner->addMoney(rent);      // Give rent to the owner
        } else {
            cout << player->getName() << " landed on their own property: " << name << "." << endl;
        }
    } else {
        // If the property is unowned, offer the player a chance to buy it
        cout << player->getName() << " landed on " << name << ". It's available for purchase for $" << price << "." << endl;
        if (player->getMoney() >= price) {
            char decision;
            cout << "Do you want to buy " << name << " for $" << price << "? (y/n): ";
            cin >> decision;
            if (decision == 'y') {
                player->buyProperty(this);  // Player buys the property
            }
        } else {
            cout << player->getName() << " doesn't have enough money to buy " << name << endl;
        }
    }
}

// Display the information of the property (name, price, rent, houses, and owner)
void Property::displayPropertyInfo() const {
    cout << "Property: " << name << endl;
    cout << "Price: $" << price << endl;
    cout << "Base Rent: $" << baseRent << endl;
    cout << "Houses: " << houses << endl;
    cout << "Hotel: " << (hotel ? "Yes" : "No") << endl;
    if (owner != nullptr) {
        cout << "Owned by: " << owner->getName() << endl;
    } else {
        cout << "Currently unowned." << endl;
    }
}
