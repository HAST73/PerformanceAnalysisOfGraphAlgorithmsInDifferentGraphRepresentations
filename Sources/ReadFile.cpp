#include "../Headers/ReadFile.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

using namespace std;

vector<vector<int>> ReadFile::readData(const string& filename, bool fullRead) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filename);
    }

    vector<vector<int>> data;
    string line;
    while (getline(file, line)) {
        istringstream stream(line);
        vector<int> row;
        int number;
        while (stream >> number) {
            row.push_back(number);
        }
        data.push_back(row);
    }

    if (data.empty()) {
        throw runtime_error("File is empty or data could not be read.");
    }

    file.close();
    return data;
}
