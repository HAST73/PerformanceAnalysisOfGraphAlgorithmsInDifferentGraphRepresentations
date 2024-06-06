#ifndef PROJECT_AIZO_2_READFILE_H
#define PROJECT_AIZO_2_READFILE_H


#include <vector>
#include <string>

class ReadFile {
public:
    static std::vector<std::vector<int>> readData(const std::string& filename, bool fullRead);
};


#endif //PROJECT_AIZO_2_READFILE_H
