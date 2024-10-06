// Cube.cpp
#include "Cube.hpp"
#include <cstdlib>  // For rand()
#include <ctime>    // For time()

// Constructor - Optionally initialize random seed once 
Cube::Cube() {
    std::srand(std::time(0));  // Use current time as the seed for random generator
}

// Roll two six-sided dice and return the total
int Cube::roll() {
    die1 = rollSingle();  // Roll the first die
    die2 = rollSingle();  // Roll the second die
    return die1 + die2;   // Return the sum of both dice
}

// Roll a single six-sided die and return the value (between 1 and 6)
int Cube::rollSingle() {
    return (std::rand() % 6) + 1;  // Generate a random number between 1 and 6
}

// Check if the last roll was a double (both dice have the same value)
bool Cube::isDouble() const {
    return die1 == die2;
}
