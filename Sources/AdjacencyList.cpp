#include "../Headers/AdjacencyList.h"
#include <iostream>
#include <list>
#include <vector>

AdjacencyList::AdjacencyList(int vertices)
        : vertices(vertices) {
    adjList.resize(vertices);
}

void AdjacencyList::addEdge(int v1, int v2, int weight, bool directed) {
    adjList[v1].push_back(std::make_pair(v2, weight));
    if (!directed) {
        adjList[v2].push_back(std::make_pair(v1, weight));
    }
}

void AdjacencyList::printList() {
    for (int i = 0; i < vertices; ++i) {
        std::cout << i << ": ";
        if (adjList[i].empty()) {
            std::cout << "Brak";
        } else {
            for (const auto& edge : adjList[i]) {
                std::cout << "(" << edge.first << ", " << edge.second << ") ";
            }
        }
        std::cout << std::endl;
    }
}