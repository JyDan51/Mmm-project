#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <set>

class Player {
private:
    std::string name; 
    std::set<char> guessedLetters;

public:
    void setName(const std::string& name); //Set name for player.
    std::string getName() const; //Get name of player.

    void addGuessedLetter(char letter); //Add guessed letter.
    bool hasGuessed(char letter) const; //Check if letter is guessed.

    std::string getGuessedLetters() const; //Get all guessed letters.
};

#endif
