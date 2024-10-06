#include "Board.hpp"
#include "Property.hpp"
#include "Railroad.hpp"
#include "Utility.hpp"
#include "SpecialSpace.hpp"

// Constructor
Board::Board() {
    initializeBoard();
}

// Destructor
Board::~Board() {
    // Clean up all dynamically allocated spaces
    for (Space* space : spaces) {
        delete space;
    }
}

// Initialize the board with the 40 spaces in the standard Monopoly layout
void Board::initializeBoard() {
    // Initialize the board with all the predefined spaces
    spaces.push_back(new SpecialSpace("Go"));  // 0: Go
    spaces.push_back(new Property("Mediterranean Avenue", 60, 2));  // 1: Property
    spaces.push_back(new SpecialSpace("Community Chest"));  // 2: Community Chest
    spaces.push_back(new Property("Baltic Avenue", 60, 4));  // 3: Property
    spaces.push_back(new SpecialSpace("Income Tax"));  // 4: Income Tax
    spaces.push_back(new Railroad("Reading Railroad", 200));  // 5: Railroad
    spaces.push_back(new Property("Oriental Avenue", 100, 6));  // 6: Property
    spaces.push_back(new SpecialSpace("Chance"));  // 7: Chance
    spaces.push_back(new Property("Vermont Avenue", 100, 6));  // 8: Property
    spaces.push_back(new Property("Connecticut Avenue", 120, 8));  // 9: Property
    spaces.push_back(new SpecialSpace("Jail"));  // 10: Jail (Just visiting)
    spaces.push_back(new Property("St. Charles Place", 140, 10));  // 11: Property
    spaces.push_back(new Utility("Electric Company", 150));  // 12: Utility
    spaces.push_back(new Property("States Avenue", 140, 10));  // 13: Property
    spaces.push_back(new Property("Virginia Avenue", 160, 12));  // 14: Property
    spaces.push_back(new Railroad("Pennsylvania Railroad", 200));  // 15: Railroad
    spaces.push_back(new Property("St. James Place", 180, 14));  // 16: Property
    spaces.push_back(new SpecialSpace("Community Chest"));  // 17: Community Chest
    spaces.push_back(new Property("Tennessee Avenue", 180, 14));  // 18: Property
    spaces.push_back(new Property("New York Avenue", 200, 16));  // 19: Property
    spaces.push_back(new SpecialSpace("Free Parking"));  // 20: Free Parking
    spaces.push_back(new Property("Kentucky Avenue", 220, 18));  // 21: Property
    spaces.push_back(new SpecialSpace("Chance"));  // 22: Chance
    spaces.push_back(new Property("Indiana Avenue", 220, 18));  // 23: Property
    spaces.push_back(new Property("Illinois Avenue", 240, 20));  // 24: Property
    spaces.push_back(new Railroad("B. & O. Railroad", 200));  // 25: Railroad
    spaces.push_back(new Property("Atlantic Avenue", 260, 22));  // 26: Property
    spaces.push_back(new Property("Ventnor Avenue", 260, 22));  // 27: Property
    spaces.push_back(new Utility("Water Works", 150));  // 28: Utility
    spaces.push_back(new Property("Marvin Gardens", 280, 24));  // 29: Property
    spaces.push_back(new SpecialSpace("Go to Jail"));  // 30: Go to Jail
    spaces.push_back(new Property("Pacific Avenue", 300, 26));  // 31: Property
    spaces.push_back(new Property("North Carolina Avenue", 300, 26));  // 32: Property
    spaces.push_back(new SpecialSpace("Community Chest"));  // 33: Community Chest
    spaces.push_back(new Property("Pennsylvania Avenue", 320, 28));  // 34: Property
    spaces.push_back(new Railroad("Short Line", 200));  // 35: Railroad
    spaces.push_back(new SpecialSpace("Chance"));  // 36: Chance
    spaces.push_back(new Property("Park Place", 350, 35));  // 37: Property
    spaces.push_back(new SpecialSpace("Luxury Tax"));  // 38: Luxury Tax
    spaces.push_back(new Property("Boardwalk", 400, 50));  // 39: Property
}

// Get the space at a specific position
Space* Board::getSpace(int position) const {
    if (position >= 0 && position < static_cast<int>(spaces.size())) {
        return spaces[position];
    }
    return nullptr;
}


// Print the current state of the board, showing the name of each space
void Board::displayBoard() const {
    cout << "Board Layout:" << endl;
    for (size_t i = 0; i < spaces.size(); i++) {
        cout << "Position " << i << ": " << spaces[i]->getName() << endl;
    }
}

// Handle when a player lands on a space
void Board::landOnSpace(Player* player) {
    int position = player->getPosition();
    Space* space = getSpace(position);

    if (space != nullptr) {
        cout << player->getName() << " landed on " << space->getName() << endl;
        space->landOn(player);  // Each space will have its own landOn() behavior
    }
}
