#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "Player.hpp"
#include "Leaderboard.hpp"
#include "SaveManager.hpp"

class Game {
private:
    std::string wordToGuess;
    std::string guessedWord;
    int attemptsLeft;
    Player player;
    Leaderboard* leaderboard;
    SaveManager* saveManager;

    void displayState();
    void processGuess(char guess);
    void resetGame(); // Добавляем метод для очистки состояния

public:
    Game(Leaderboard& lb, SaveManager& sm);
    void start();
    void setCustomWord(const std::string& word);
    std::string getPlayerName() const;
    int getScore() const;
};

#endif
