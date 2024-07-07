#include "../Headers/GenerateRandomGraphFile.h"
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>

using namespace std;

void GenerateRandomGraphFile::generateGraphFile(const string& filename, int vertices, double density) {
    int maxEdges = vertices * (vertices - 1) / 2;
    int edges = static_cast<int>((density / 100.0) * maxEdges);

    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filename);
    }

    file << edges << " " << vertices << endl;

    vector<pair<int, int>> allPossibleEdges;
    for (int i = 0; i < vertices; ++i) {
        for (int j = i + 1; j < vertices; ++j) {
            allPossibleEdges.emplace_back(i, j);
        }
    }

    shuffle(allPossibleEdges.begin(), allPossibleEdges.end(), mt19937{random_device{}()});

    uniform_int_distribution<int> weightDistribution(1, 100);
    mt19937 generator{random_device{}()};

    for (int i = 0; i < edges; ++i) {
        int u = allPossibleEdges[i].first;
        int v = allPossibleEdges[i].second;
        int weight = weightDistribution(generator);
        file << u << " " << v << " " << weight << endl;
    }

    file.close();
}
