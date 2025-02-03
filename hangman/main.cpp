#include "Game.hpp"
#include "Leaderboard.hpp"
#include "SaveManager.hpp"
#include <iostream>
#include <limits>

//Main menu
void displayMainMenu() {
    std::cout << "\n--- Hangman Main Menu ---\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. View Leaderboard\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Leaderboard leaderboard;  //Makes new leaderboard
    SaveManager saveManager;  //Save system

    //Load scores from scores.txt xd
    std::string filename = "scores.txt";
    leaderboard.setScores(saveManager.loadScores(filename));

    Game game(leaderboard, saveManager);  //Make new game

    while (true) {  //Loop for main menu
        displayMainMenu();  //Show menu
        int choice;

        //Check if input is correct
        if (!(std::cin >> choice)) {  
            std::cin.clear();  //Fix input error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //Remove wrong input
            std::cout << "Invalid input. Please enter a number.\n";  //Warn player
            continue;  //Ask again
        }

        switch (choice) {  //Check player choice
            case 1: {  //Start game
                std::string customWord;
                std::cout << "Enter a custom word (or leave empty for random): ";
                std::cin.ignore();  //Ignore newline from last input
                std::getline(std::cin, customWord);  //Get full word from player
                
                if (!customWord.empty()) {  //If player gave word, use it
                    game.setCustomWord(customWord);
                }

                game.start();  //Game BEGIN
                break;
            }
            case 2:  //Show leaderboard
                leaderboard.display();
                break;
            case 3:  //Exit game
                saveManager.saveScores(leaderboard.getScores(), filename);  //Save scores before exit
                std::cout << "Goodbye!" << std::endl;  
                return 0;  //Quit program
            default:  //Wrong input
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
