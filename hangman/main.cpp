#include "Game.hpp"
#include "Leaderboard.hpp"
#include "SaveManager.hpp"
#include <iostream>
#include <limits>

void displayMainMenu() {
    std::cout << "\n--- Hangman Main Menu ---\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. View Leaderboard\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Leaderboard leaderboard;
    SaveManager saveManager;

    // Загружаем результаты
    std::string filename = "scores.txt";
    leaderboard.setScores(saveManager.loadScores(filename));

    Game game(leaderboard, saveManager);

    while (true) {
        displayMainMenu();
        int choice;

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::string customWord;
                std::cout << "Enter a custom word (or leave empty for random): ";
                std::cin.ignore();
                std::getline(std::cin, customWord);
                
                if (!customWord.empty()) {
                    game.setCustomWord(customWord);
                }

                game.start();
                break;
            }
            case 2:
                leaderboard.display();
                break;
            case 3:
                saveManager.saveScores(leaderboard.getScores(), filename);
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
