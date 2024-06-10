#ifndef PROJECT_AIZO_2_DIJKSTRAADJACENCYLIST_H
#define PROJECT_AIZO_2_DIJKSTRAADJACENCYLIST_H

#include "../Headers/AdjacencyList.h"

class DijkstraAdjacencyList {
public:
    DijkstraAdjacencyList(const AdjacencyList& adjList);
    void findShortestPath(int startVertex, int endVertex);

private:
    const AdjacencyList& adjList;
};

#endif //PROJECT_AIZO_2_DIJKSTRAADJACENCYLIST_H
