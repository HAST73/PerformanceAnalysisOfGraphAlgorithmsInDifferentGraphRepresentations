#include "../Headers/ReadFile.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

std::vector<std::vector<int>> ReadFile::readData(const std::string& filename, bool fullRead) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::vector<std::vector<int>> data;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::vector<int> row;
        int number;
        while (stream >> number) {
            row.push_back(number);
        }
        data.push_back(row);
    }

    if (data.empty()) {
        throw std::runtime_error("File is empty or data could not be read.");
    }

    file.close();
    return data;
}