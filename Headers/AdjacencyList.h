#ifndef PROJECT_AIZO_2_ADJACENCYLISTS_H
#define PROJECT_AIZO_2_ADJACENCYLISTS_H

#include <vector>
#include <list>
#include <iostream>
#include <utility>

class AdjacencyList {
public:
    AdjacencyList(int vertices);
    void addEdge(int v1, int v2, int weight, bool directed);
    void printList();
    int getVertices() const { return vertices; }
    const std::vector<std::list<std::pair<int, int>>>& getAdjList() const { return adjList; }
    void clear();
    void updateListForDijkstra(const std::vector<int>& dist, const std::vector<int>& prev);
    void updateListForBellmanFord(const std::vector<int>& dist, const std::vector<int>& prev);

private:
    std::vector<std::list<std::pair<int, int>>> adjList;
    int vertices;
};

#endif //PROJECT_AIZO_2_ADJACENCYLISTS_H
