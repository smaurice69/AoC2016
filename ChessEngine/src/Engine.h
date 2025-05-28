#ifndef ENGINE_H
#define ENGINE_H

#include <string>

class Engine {
public:
    Engine();

    // Main loop handling UCI commands from stdin.
    void loop();

private:
    void parseFEN(const std::string &fen);
    void printBoard() const;

    char board[8][8];
    char sideToMove;
};

#endif // ENGINE_H
