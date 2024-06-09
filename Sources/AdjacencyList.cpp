#include "../Headers/AdjacencyList.h"
#include <iostream>
#include <iomanip>
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
    // Calculate the maximum width for vertex numbers
    int maxWidth = std::to_string(vertices - 1).length();
    std::cout<<std::endl;

    for (int i = 0; i < vertices; ++i) {
        std::cout << std::setw(maxWidth) << i << ": ";
        if (adjList[i].empty()) {
            std::cout << "None";
        } else {
            for (const auto& edge : adjList[i]) {
                std::cout << "(" << edge.first << ", " << edge.second << ") ";
            }
        }
        std::cout << std::endl;
    }
}

void AdjacencyList::clear() {
    for (auto& edges : adjList) {
        edges.clear();
    }
}
