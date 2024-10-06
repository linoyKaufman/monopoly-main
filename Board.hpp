#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
#include "Space.hpp"  // Include Space header to use Space* pointers

// Forward declarations for Property, Railroad, Utility, SpecialSpace
class Property;
class Railroad;
class Utility;
class SpecialSpace;
class Space;

class Board {
private:
    std::vector<Space*> spaces;  // Vector holding all 40 spaces on the board

public:
    // Constructor - Initializes the board
    Board();

    // Destructor - Cleans up dynamically allocated spaces
    ~Board();

    // Initialize the board with the 40 spaces in the standard Monopoly layout
    void initializeBoard();

    // Get the space at a specific position
    Space* getSpace(int position) const;

    // Print the current state of the board, showing the name of each space
    void displayBoard() const;

    // Handle when a player lands on a space
    void landOnSpace(Player* player);
};

#endif  // BOARD_HPP
