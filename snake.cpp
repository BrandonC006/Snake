#include "board.h"
#include <unordered_map>

std::unordered_map<char, std::pair<int, int>> moves = {
    {'U', {0, 1}},
    {'D', {0, -1}},
    {'L', {-1, 0}},
    {'R', {1, 0}}
};

bool validAction(char action) {
    return (action == 'U' || action == 'L' || action == 'D' || action == 'R');
};

using namespace std;

int main() {
    size_t board_size;
    std::cout << "Welcome to Snake..." << '\n';
    std::cout << "How big would you like the square to be? (Enter a value 2-12): ";
    std::cin >> board_size;
    std::cout << '\n';

    Board board(board_size);

    char action;
    while (board.alive && !board.complete()) {
        board.printBoard();
        std::cout << "Move: ";
        std::cin >> action;
        std::cout << '\n';
        while (!validAction(action)) {
            std::cout << "Invalid move, try again: ";
            std::cin >> action;
            std::cout << '\n';
        }
    }
    
    return;
}