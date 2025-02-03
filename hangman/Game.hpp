#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "Player.hpp"
#include "Leaderboard.hpp"
#include "SaveManager.hpp"

//Game class, main game logic
class Game {
private:
    std::string wordToGuess;  //Word player must find
    std::string guessedWord;  //Word player see with _ for unknown
    int attemptsLeft;  //How many tries left
    bool isCustomWordSet; //Check if player give word or no 
    Player player;  //Player object with data
    Leaderboard* leaderboard;  //Pointers
    SaveManager* saveManager;  

    void displayState();  //Show game info to player
    void processGuess(char guess);  //Handle letter from player
    void resetGame();  //Clean game for new round

public:
    Game(Leaderboard& lb, SaveManager& sm); //Makes new game with leaderboard and save
    void start();  //Begin the game
    void setCustomWord(const std::string& word);  //Player can give own word
    std::string getPlayerName() const;  //Get name of player
    int getScore() const;  //Get player score
};

#endif
