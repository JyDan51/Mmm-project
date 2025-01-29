#include "Game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game(Leaderboard& lb, SaveManager& sm) 
    : attemptsLeft(6), isCustomWordSet(false), leaderboard(&lb), saveManager(&sm) {}

void Game::setCustomWord(const std::string& word) {
    wordToGuess = word;
    guessedWord = std::string(wordToGuess.length(), '_'); // Заполняем _ для отображения
    isCustomWordSet = true;
}

void Game::resetGame() {
    attemptsLeft = 6;
    player = Player(); // Полностью сбрасываем состояние игрока

    if (!isCustomWordSet) { // Если пользователь не вводил слово, сбрасываем его
        wordToGuess.clear();
        guessedWord.clear();
    }
}

void Game::displayState() {
    std::cout << "\nWord1: " << guessedWord
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
    resetGame(); // Очищаем игру перед стартом

    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;
    player.setName(playerName);

    if (!isCustomWordSet) { // Если слово не задано вручную, выбираем случайное
        std::vector<std::string> words = {"programming", "hangman", "challenge", "player", "keyboard"};
        srand(time(0));
        wordToGuess = words[rand() % words.size()];
    }

    guessedWord = std::string(wordToGuess.length(), '_'); // Теперь `guessedWord` всегда создается корректно

    while (attemptsLeft > 0 && guessedWord != wordToGuess) {
        displayState();
        std::cout << "Enter a letter: ";
        char guess;
        std::cin >> guess;

        processGuess(guess);
    }

    if (guessedWord == wordToGuess) {
        std::cout << "Congratulations, " << player.getName() << "! You guessed the word: " << wordToGuess << "\n";
        leaderboard->addScore(player.getName(), attemptsLeft);
    } else {
        std::cout << "Game over! The word was: " << wordToGuess << "\n";
    }

    saveManager->saveScores(leaderboard->getScores(), "scores.txt");
    isCustomWordSet = false; // После завершения игры сбрасываем кастомное слово
}
