#include "Leaderboard.hpp"

//Add score for player, keep only best score
void Leaderboard::addScore(const std::string& playerName, int score) {
    scores[playerName] = std::max(scores[playerName], score);  // Update if new score is better
}

//Shows all scores in console
void Leaderboard::display() const {
    std::cout << "\nLeaderboard:\n";
    for (const auto& entry : scores) {  //Loop all scores
        std::cout << entry.first << ": " << entry.second << " points\n";  //Print name and score
    }
}

//Set new scores from outside, replace old ones
void Leaderboard::setScores(const std::map<std::string, int>& newScores) {
    scores = newScores;  //Replace with given data
}

//Get scores from leaderboard
std::map<std::string, int> Leaderboard::getScores() const {
    return scores;  //Return all scores
}
