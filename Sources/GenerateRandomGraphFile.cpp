#include "../Headers/GenerateRandomGraphFile.h"
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>

void GenerateRandomGraphFile::generateGraphFile(const std::string& filename, int vertices, double density) {
    int maxEdges = vertices * (vertices - 1) / 2;
    int edges = static_cast<int>((density / 100.0) * maxEdges);

    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    file << edges << " " << vertices << std::endl;

    std::vector<std::pair<int, int>> allPossibleEdges;
    for (int i = 0; i < vertices; ++i) {
        for (int j = i + 1; j < vertices; ++j) {
            allPossibleEdges.emplace_back(i, j);
        }
    }

    std::shuffle(allPossibleEdges.begin(), allPossibleEdges.end(), std::mt19937{std::random_device{}()});

    std::uniform_int_distribution<int> weightDistribution(1, 100);
    std::mt19937 generator{std::random_device{}()};

    for (int i = 0; i < edges; ++i) {
        int u = allPossibleEdges[i].first;
        int v = allPossibleEdges[i].second;
        int weight = weightDistribution(generator);
        file << u << " " << v << " " << weight << std::endl;
    }

    file.close();
}