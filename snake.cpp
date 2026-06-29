#include "board.h"
#include <unordered_map>

std::unordered_map<char, std::pair<int, int>> moves = {
    {'U', {0, 1}},
    {'D', {0, -1}},
    {'L', {-1, 0}},
    {'R', {1, 0}}
};

using namespace std;

int main() {
    size_t board_size = 0;
    std::cout << "Welcome to Snake..." << '\n';
    std::cout << "How big would you like the square to be? (Enter a value 2-12): ";
    while (board_size < 2 || board_size > 20) {
        std::cin >> board_size;
        std::cout << '\n';
    }

    Board board(board_size);

    char action;
    while (board.alive && !board.complete()) {
        board.printBoard();
        std::cout << "Move: ";
        std::cin >> action;
        std::cout << '\n';
        while (moves.find(action) == moves.end()) {
            std::cout << "Invalid move, try again: ";
            std::cin >> action;
            std::cout << '\n';
        }
        board.moveSnake(moves[action]);
    }
    
    return 0;
}