#include "Player.hpp"

void Player::setName(const std::string& name) {
    this->name = name;  //Saves player name
}

std::string Player::getName() const {
    return name;  // Return name
}

//Add guessed letter to memory
void Player::addGuessedLetter(char letter) {
    guessedLetters.insert(letter);  //Save letter in set
}

//Check if player already guessed letter before
bool Player::hasGuessed(char letter) const {
    return guessedLetters.find(letter) != guessedLetters.end();  //Return true if letter is found
}

//Get all guessed letters as string
std::string Player::getGuessedLetters() const {
    std::string result(guessedLetters.begin(), guessedLetters.end());  //Convert set to string
    return result;  //Return guessed letters
}
