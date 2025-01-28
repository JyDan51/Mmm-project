#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "Player.hpp"
#include "Leaderboard.hpp"

class Game {
private:
    std::string wordToGuess;
    std::string guessedWord;
    int attemptsLeft;
    Player player;
    Leaderboard leaderboard;

    void displayState();
    void processGuess(char guess);
    void loadWord();

public:
    Game();
    void start();
};

#endif
