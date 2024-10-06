#include "Board.hpp"
#include "Player.hpp"
#include "Cube.hpp"
#include <iostream>

using namespace std;

int main() {
    // Initialize the game board and cube (for dice rolling)
    Board board;
    Cube cube;

    // Create two players for the game
    Player player1("Alice");
    Player player2("Bob");

    // Simple game loop for 10 turns
    for (int turn = 1; turn <= 10; ++turn) {
        cout << "\nTurn " << turn << ":\n";

        // Player 1 rolls and moves
        int roll1 = cube.roll();
        cout << player1.getName() << " rolled " << roll1 << endl;
        player1.move(roll1);
        board.landOnSpace(&player1);

        // Player 2 rolls and moves
        int roll2 = cube.roll();
        cout << player2.getName() << " rolled " << roll2 << endl;
        player2.move(roll2);
        board.landOnSpace(&player2);
    }

    cout << "Game over!\n";

    return 0;
}
