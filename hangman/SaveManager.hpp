#ifndef SAVEMANAGER_HPP
#define SAVEMANAGER_HPP

#include <string>
#include <map>

class SaveManager {
public:
    void saveScores(const std::map<std::string, int>& scores, const std::string& filename);
    std::map<std::string, int> loadScores(const std::string& filename);
};

#endif
