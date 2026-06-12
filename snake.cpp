#include <vector>
#include <iostream>
#include <random>

using namespace std;

class Board {
    public:
        Board(size_t board_size) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(0, board_size - 1); 
            size_t x = distr(gen);
            size_t y = distr(gen);
        }
        std::vector<std::vector<bool>> board;
        std::queue<std::pair<size_t, size_t>> snake;
        std::vector<std::pair<size_t, size_t>> apples;
        void printBoard() {
            for (size_t i = 0; i < board.size() - 1; ++i) {
                std::cout << board[i][0];
                for (size_t j = 1; j < board[i].size(); ++j) {
                    std::cout << board[i][j];
                }
                for (size_t k = 0; k < board[i].size() * 2; ++k) {
                    std::cout << '-';
                }
            }
            std::cout << board[board.size() - 1][0];
            for (size_t j = 1; j < board[board.size() - 1].size(); ++j) {
                std::cout << board[board.size() - 1][j];
            }
        };
};

int main() {
    size_t board_size;
    std::cout << "Welcome to Snake..." << '\n';
    std::cout << "How big would you like the square to be? (Enter a value 2-12): ";
    std::cin >> board_size;
    
    return;
}