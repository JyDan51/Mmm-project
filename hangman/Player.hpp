#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <set>

class Player {
private:
    std::string name;
    std::set<char> guessedLetters;

public:
    void setName(const std::string& name);
    std::string getName() const;

    void addGuessedLetter(char letter);
    bool hasGuessed(char letter) const;

    std::string getGuessedLetters() const;
};

#endif // PLAYER_HPP
