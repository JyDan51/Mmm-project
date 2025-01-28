#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP

#include <string>
#include <map>
#include <iostream>

class Leaderboard {
private:
    std::map<std::string, int> scores;

public:
    void addScore(const std::string& playerName, int score);
    void display() const;
    void setScores(const std::map<std::string, int>& newScores);
    std::map<std::string, int> getScores() const;
};

#endif
