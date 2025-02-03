#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP

#include <string>
#include <map>
#include <iostream>

//Leaderboard class, store and show best scores
class Leaderboard {
private:
    std::map<std::string, int> scores;  //Map for keep player names and scores

public:
    void addScore(const std::string& playerName, int score);  //Add new score
    void display() const;  //Shows all scores
    void setScores(const std::map<std::string, int>& newScores);  //Changes all scores
    std::map<std::string, int> getScores() const;  //Get all scores
};

#endif
