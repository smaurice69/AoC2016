#include "Engine.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Engine::Engine() : sideToMove('w') {
    for (auto &row : board) {
        for (char &c : row) {
            c = '.';
        }
    }
}

void Engine::parseFEN(const std::string &fen) {
    std::istringstream iss(fen);
    std::string boardPart;
    iss >> boardPart; // pieces
    iss >> sideToMove; // side to move

    std::vector<std::string> ranks;
    std::stringstream ss(boardPart);
    std::string rank;
    while (std::getline(ss, rank, '/')) {
        ranks.push_back(rank);
    }
    if (ranks.size() != 8) return; // invalid FEN, ignore

    for (int r = 0; r < 8; ++r) {
        const std::string &rowStr = ranks[r];
        int c = 0;
        for (char ch : rowStr) {
            if (std::isdigit(ch)) {
                int empty = ch - '0';
                for (int i = 0; i < empty && c < 8; ++i) {
                    board[r][c++] = '.';
                }
            } else {
                if (c < 8)
                    board[r][c++] = ch;
            }
        }
        while (c < 8) {
            board[r][c++] = '.';
        }
    }
}

void Engine::printBoard() const {
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            std::cout << board[r][c] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "Side to move: " << sideToMove << std::endl;
}

static std::vector<std::string> split(const std::string &str) {
    std::istringstream iss(str);
    std::vector<std::string> out;
    std::string token;
    while (iss >> token) {
        out.push_back(token);
    }
    return out;
}

void Engine::loop() {
    std::string line;
    while (std::getline(std::cin, line)) {
        auto tokens = split(line);
        if (tokens.empty()) continue;
        const std::string &cmd = tokens[0];

        if (cmd == "uci") {
            std::cout << "id name SimpleEngine" << std::endl;
            std::cout << "id author Codex" << std::endl;
            std::cout << "uciok" << std::endl;
        } else if (cmd == "isready") {
            std::cout << "readyok" << std::endl;
        } else if (cmd == "position") {
            if (tokens.size() >= 3 && tokens[1] == "fen") {
                std::string fen;
                for (size_t i = 2; i < tokens.size(); ++i) {
                    if (i > 2) fen += ' ';
                    fen += tokens[i];
                }
                parseFEN(fen);
            } else if (tokens.size() >= 2 && tokens[1] == "startpos") {
                parseFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w");
            }
        } else if (cmd == "d") {
            printBoard();
        } else if (cmd == "quit") {
            break;
        }
    }
}
