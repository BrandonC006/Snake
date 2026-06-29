#include <random>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>

using namespace std;

struct PairHash {
    size_t operator()(const std::pair<size_t, size_t>& p) const {
        return std::hash<size_t>()(p.first) * std::hash<size_t>()(p.second);
    }
};

class Snake {
    public:
        size_t size() {
            return snake1.size();
        };

        void pop() {
            snake2.erase(snake1.front());
            snake1.pop();
        };

        void add(std::pair<size_t, size_t> next) {
            snake1.push(next);
            snake2.insert(next);
        };

        bool find(size_t x, size_t y) {
            return (snake2.find({x, y}) != snake2.end());
        }

        std::pair<size_t, size_t> head() {
            return snake1.back();
        }

        std::queue<std::pair<size_t, size_t>> snake1;
        std::unordered_set<std::pair<size_t, size_t>, PairHash> snake2;
};

class Board {
    public:
        Board(size_t board_size) : board(board_size, vector<bool>(board_size, false)), alive(true) {
            generateApple();
        }

        std::vector<std::vector<bool>> board;
        Snake snake;
        std::pair<size_t, size_t> apple;
        bool alive;

        std::pair<size_t, size_t> addCoord(std::pair<size_t, size_t> a, std::pair<int, int> b) {
            int x = static_cast<int>(a.first) + b.first;
            int y = static_cast<int>(a.second) + b.second;

            if (x < 0 || y < 0 ||
                x >= static_cast<int>(board.size()) ||
                y >= static_cast<int>(board.size()))
                return a;

            return {static_cast<size_t>(x),
                    static_cast<size_t>(y)};
        }

        bool complete() {
            return (board.size() * board[0].size() == snake.size());
        }

        void printBoard() {
            for (size_t i = 0; i < board.size() - 1; ++i) {
                std::cout << board[i][0];
                for (size_t j = 1; j < board[i].size(); ++j) {
                    std::cout << '|' << board[i][j];
                }
                for (size_t k = 0; k < board[i].size() * 2; ++k) {
                    std::cout << '-';
                }
            }
            std::cout << board[board.size() - 1][0];
            for (size_t j = 1; j < board[board.size() - 1].size(); ++j) {
                std::cout << '|' << board[board.size() - 1][j];
            }
        };

        void moveSnake(std::pair<int, int> move) {
            std::pair<size_t, size_t> next = addCoord(snake.head(), move);
            if (next == snake.head()) alive = false;
            else {
                if (next == apple) {
                    snake.add(next);
                    if (!complete()) generateApple();
                }
                else {
                    snake.add(next);
                    snake.pop();
                }
            }
        };

        void generateApple() {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(0, static_cast<int>(board.size() - 1)); 
            size_t x = static_cast<size_t>(distr(gen));
            size_t y = static_cast<size_t>(distr(gen));
            while (snake.find(x, y)) {
                //if the random apple lands on a snake tile, linear probe to a new spot
                x = (x + 1) % board.size();
                if (x == 0) y = (y + 1) % board.size();
            }
            apple = {x, y};
        }
};