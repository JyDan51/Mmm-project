#include "Player.hpp"

void Player::setName(const std::string& name) {
    this->name = name;
}

std::string Player::getName() const {
    return name;
}

void Player::addGuessedLetter(char letter) {
    guessedLetters.insert(letter);
}

bool Player::hasGuessed(char letter) const {
    return guessedLetters.find(letter) != guessedLetters.end();
}

std::string Player::getGuessedLetters() const {
    std::string result(guessedLetters.begin(), guessedLetters.end());
    return result;
}
