#include "Leaderboard.hpp"
#include <iostream>

void Leaderboard::addScore(const std::string& playerName, int score) {
    scores[playerName] = std::max(scores[playerName], score);
}

void Leaderboard::display() const {
    std::cout << "\nLeaderboard:\n";
    for (const auto& entry : scores) {
        std::cout << entry.first << ": " << entry.second << " points\n";
    }
}
