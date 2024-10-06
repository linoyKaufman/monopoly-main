#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>

// Forward declaration of Player class
class Player;

// Base class for all board spaces
class Space {
protected:
    std::string name;  // Protected, so derived classes can access this member

public:
    // Constructor that initializes the name of the space
    Space(const std::string& spaceName) : name(spaceName) {}

    // Virtual function for when a player lands on the space
    virtual void landOn(Player* player) = 0;

    // Getter for the name of the space
    std::string getName() const {
        return name;
    }

    // Virtual destructor
    virtual ~Space() {}
};

#endif
