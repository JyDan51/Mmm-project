// main.cpp
#include "Game.hpp"
#include "Leaderboard.hpp"
#include "SaveManager.hpp"
#include <iostream>

void displayMainMenu() {
    std::cout << "\n--- Hangman Main Menu ---\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. View Leaderboard\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Game game;
    Leaderboard leaderboard;
    SaveManager saveManager;

    // Load scores from file
    std::string filename = "scores.txt";
    leaderboard.setScores(saveManager.loadScores(filename));

    while (true) {
        displayMainMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                game.start();
                break;
            case 2:
                leaderboard.display();
                break;
            case 3:
                // Save scores to file before exiting
                saveManager.saveScores(leaderboard.getScores(), filename);
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
