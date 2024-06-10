#ifndef PROJECT_AIZO_2_BELLMANFORDADJACENCYLIST_H
#define PROJECT_AIZO_2_BELLMANFORDADJACENCYLIST_H

#include "../Headers/AdjacencyList.h"
#include <vector>

class BellmanFordAdjacencyList {
public:
    BellmanFordAdjacencyList(const AdjacencyList& adjacencyList);
    bool findShortestPath(int startVertex, int endVertex);
    const std::vector<int>& getDistances() const { return dist; }
    const std::vector<int>& getPredecessors() const { return prev; }

private:
    const AdjacencyList& adjList;
    std::vector<int> dist;
    std::vector<int> prev;
};

#endif //PROJECT_AIZO_2_BELLMANFORDADJACENCYLIST_H
