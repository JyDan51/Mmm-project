#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP

#include <string>
#include <map>

class Leaderboard {
private:
    std::map<std::string, int> scores;

public:
    void addScore(const std::string& playerName, int score);
    void display() const;
};

#endif
