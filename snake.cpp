#include <vector>
#include <iostream>

using namespace std;

class Board {
    public:
        std::vector<std::vector<bool>> board;
        std::queue<std::pair<size_t, size_t>> snake;
        std::vector<std::pair<size_t, size_t>> apples;
}

int main() {
    size_t board_size;
    std::cout << "Welcome to Snake..." << '\n';
    std::cout << "How big would you like the square to be? (Enter a value 2-12): ";
    std::cin >> board_size;
    
    return;
}