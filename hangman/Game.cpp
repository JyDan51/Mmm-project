#include "Game.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

Game::Game() : attemptsLeft(6) {}

void Game::loadWord() {
    std::vector<std::string> words = {"programming", "hangman", "challenge", "player", "keyboard"};
    srand(time(0));
    wordToGuess = words[rand() % words.size()];
    guessedWord = std::string(wordToGuess.length(), '_');
}

void Game::displayState() {
    std::cout << "\nWord: " << guessedWord
              << "\nAttempts left: " << attemptsLeft
              << "\nGuessed letters: " << player.getGuessedLetters()
              << "\n";
}

void Game::processGuess(char guess) {
    if (player.hasGuessed(guess)) {
        std::cout << "You already guessed that letter!" << std::endl;
        return;
    }

    player.addGuessedLetter(guess);

    bool correct = false;
    for (size_t i = 0; i < wordToGuess.length(); i++) {
        if (wordToGuess[i] == guess) {
            guessedWord[i] = guess;
            correct = true;
        }
    }

    if (!correct) {
        attemptsLeft--;
    }
}

void Game::start() {
    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;
    player.setName(playerName);

    loadWord();

    while (attemptsLeft > 0 && guessedWord != wordToGuess) {
        displayState();
        std::cout << "Enter a letter: ";
        char guess;
        std::cin >> guess;

        processGuess(guess);
    }

    if (guessedWord == wordToGuess) {
        std::cout << "Congratulations, " << player.getName() << "! You guessed the word: " << wordToGuess << "\n";
        leaderboard.addScore(player.getName(), attemptsLeft);
    } else {
        std::cout << "Game over! The word was: " << wordToGuess << "\n";
    }

    leaderboard.display();
}
