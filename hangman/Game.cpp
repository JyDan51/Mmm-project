#include "Game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

//Game constructor, make game start settings
Game::Game(Leaderboard& lb, SaveManager& sm) 
    : attemptsLeft(6), isCustomWordSet(false), leaderboard(&lb), saveManager(&sm) {}

//Set word from player for game
void Game::setCustomWord(const std::string& word) {
    wordToGuess = word;  //Save word
    guessedWord = std::string(wordToGuess.length(), '_'); // Make _ for hide word
    isCustomWordSet = true;  //кemember what word is set
}

//clean all data
void Game::resetGame() {
    attemptsLeft = 6;  //Give new tries
    player = Player(); //Restart player data

    //no word was given by player, clean words
    if (!isCustomWordSet) { 
        wordToGuess.clear();
        guessedWord.clear();
    }
}

//Show current game info to player
void Game::displayState() {
    std::cout << "\nWord: " << guessedWord
              << "\nAttempts left: " << attemptsLeft
              << "\nGuessed letters: " << player.getGuessedLetters()
              << "\n";
}

//Check if letter is in word
void Game::processGuess(char guess) {
    // See if letter already tried
    if (player.hasGuessed(guess)) {
        std::cout << "You already say this letter!" << std::endl;
        return;
    }

    player.addGuessedLetter(guess); //Save letter in player memory

    bool correct = false; //Know if letter is in word
    for (size_t i = 0; i < wordToGuess.length(); i++) { //Look in word
        if (wordToGuess[i] == guess) { //If same, change guessed word
            guessedWord[i] = guess;
            correct = true;
        }
    }

    if (!correct) { //If letter not in word, lose try
        attemptsLeft--;
    }
}

//Game loop, player plays here
void Game::start() {
    resetGame(); //Make new game clean

    //player name
    std::cout << "Say your name: ";
    std::string playerName;
    std::cin >> playerName;
    player.setName(playerName);

    //If no word from player, pick random
    if (!isCustomWordSet) {
        std::vector<std::string> words = {"programming", "hangman", "challenge", "player", "keyboard"};
        srand(time(0)); // Make new random
        wordToGuess = words[rand() % words.size()]; //Get random word
    }

    guessedWord = std::string(wordToGuess.length(), '_'); //Make _ for word

    //Game goes until win or no tries
    while (attemptsLeft > 0 && guessedWord != wordToGuess) {
        displayState(); //Show player game info
        std::cout << "Say letter: ";
        char guess;
        std::cin >> guess;

        processGuess(guess); //Check letter
    }

    //Player win or lose
    if (guessedWord == wordToGuess) {
        std::cout << "Wow, " << player.getName() << "! You find word: " << wordToGuess << "\n";
        leaderboard->addScore(player.getName(), attemptsLeft); // Save player result
    } else {
        std::cout << "No more try! Word was: " << wordToGuess << "\n";
    }

    //Save scores in file
    saveManager->saveScores(leaderboard->getScores(), "scores.txt");

    isCustomWordSet = false; //Remove word for new game
}
