#include <random>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>

using namespace std;

class Snake {
    public:
        size_t size() {
            return snake1.size();
        };

        void pop() {
            snake2.erase(snake1.front());
            snake1.pop();
        };

        void add(size_t x, size_t y) {
            snake1.push({x, y});
            snake2.insert({x, y});
        };

        bool find(size_t x, size_t y) {
            return (snake2.find({x, y}) == snake2.end());
        }

        std::queue<std::pair<size_t, size_t>> snake1;
        std::unordered_set<std::pair<size_t, size_t>> snake2;
};

class Board {
    public:
        Board(size_t board_size) {
            generateApple();

            alive = true;
        }

        std::vector<std::vector<bool>> board;
        Snake snake;
        std::pair<size_t, size_t> apple;
        bool alive;
        bool complete() {
            return (board.size() * board[0].size() == snake.size());
        }

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

        void generateApple() {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(0, board.size() - 1); 
            size_t x = static_cast<size_t>(distr(gen));
            size_t y = static_cast<size_t>(distr(gen));
            while (snake.find(x, y)) {
                if (snake.find((x + 1) % board.size(), y)) {
                    apple = {(x + 1) % board.size(), y};
                }
                else if (snake.find(x, (y + 1) % board.size())) {
                    apple = {x, (y + 1) % board.size()};
                }
                else {
                    x = (x + 1) % board.size();
                    y = (y + 1) % board.size();
                }
            }
        }
};