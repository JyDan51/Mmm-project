#include "SaveManager.hpp"
#include <fstream>
#include <iostream>

void SaveManager::saveScores(const std::map<std::string, int>& scores, const std::string& filename) {
    std::ofstream file(filename); //Ыaving scores.
    if (!file) { 
        std::cerr << "Error: Unable to open file for saving scores." << std::endl; 
        return; //If file can not open it stops function
    }

    for (const auto& [player, score] : scores) { //Player and score.
        file << player << " " << score << "\n"; //Player name and score to file.
    }

    file.close(); //Close file after writing.
}

std::map<std::string, int> SaveManager::loadScores(const std::string& filename) {
    std::ifstream file(filename); //Open file for reading scores.
    std::map<std::string, int> scores; //Create map for scores.

    if (!file) {
        std::cerr << "Error: Unable to open file for loading scores." << std::endl; //If file can not open print error message.
        return scores;
    }

    std::string player; //Variable for player name.
    int score; //Variable for score.
    while (file >> player >> score) { //While file has player and score.
        scores[player] = score; //Save player score in map.
    }

    file.close(); //Close file after reading.
    return scores; //Return map with scores.
}
