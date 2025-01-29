#include "SaveManager.hpp"
#include <fstream>
#include <iostream>

void SaveManager::saveScores(const std::map<std::string, int>& scores, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file for saving scores." << std::endl;
        return;
    }

    for (const auto& [player, score] : scores) {
        file << player << " " << score << "\n";
    }

    file.close();
}

std::map<std::string, int> SaveManager::loadScores(const std::string& filename) {
    std::ifstream file(filename);
    std::map<std::string, int> scores;

    if (!file) {
        std::cerr << "Error: Unable to open file for loading scores." << std::endl;
        return scores;
    }

    std::string player;
    int score;
    while (file >> player >> score) {
        scores[player] = score;
    }

    file.close();
    return scores;
}