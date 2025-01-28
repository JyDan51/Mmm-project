#include "Leaderboard.hpp"

void Leaderboard::addScore(const std::string& playerName, int score) {
    scores[playerName] = std::max(scores[playerName], score);
}

void Leaderboard::display() const {
    std::cout << "\nLeaderboard:\n";
    for (const auto& entry : scores) {
        std::cout << entry.first << ": " << entry.second << " points\n";
    }
}

void Leaderboard::setScores(const std::map<std::string, int>& newScores) {
    scores = newScores;
}

std::map<std::string, int> Leaderboard::getScores() const {
    return scores;
}
