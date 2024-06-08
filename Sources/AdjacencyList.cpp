#include "../Headers/AdjacencyList.h"
#include <algorithm>

AdjacencyList::AdjacencyList(int vertices)
        : n(vertices), adjacencyList(vertices) {}

void AdjacencyList::addEdge(int v1, int v2, int weight, bool directed) {
    adjacencyList[v1].emplace_back(v2, weight);
    if (!directed) {
        adjacencyList[v2].emplace_back(v1, weight);
    }
}

void AdjacencyList::printList() const {
    for (int i = 0; i < n; ++i) {
        std::cout << "A[" << i << "] =";
        if (adjacencyList[i].empty()) {
            std::cout << " brak";
        } else {
            // Sort the adjacency list of vertex i
            std::vector<std::tuple<int, int>> sortedNeighbors = adjacencyList[i];
            std::sort(sortedNeighbors.begin(), sortedNeighbors.end());

            for (const auto& [neighbor, weight] : sortedNeighbors) {
                std::cout << " " << neighbor << "(" << weight << ")";
            }
        }
        std::cout << std::endl;
    }
}

int AdjacencyList::vertexDegree(int vertexIndex) const {
    return adjacencyList[vertexIndex].size();
}

std::vector<std::tuple<int, int>> AdjacencyList::neighbors(int vertexIndex) const {
    return adjacencyList[vertexIndex];
}

bool AdjacencyList::isIsolated(int vertexIndex) const {
    return adjacencyList[vertexIndex].empty();
}