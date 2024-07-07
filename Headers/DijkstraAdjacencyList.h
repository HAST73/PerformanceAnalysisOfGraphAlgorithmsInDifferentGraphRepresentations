#ifndef PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_DIJKSTRAADJACENCYLIST_H
#define PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_DIJKSTRAADJACENCYLIST_H

#include "../Headers/AdjacencyList.h"

using namespace std;

class DijkstraAdjacencyList {
public:
    DijkstraAdjacencyList(const AdjacencyList& adjList);
    void findShortestPath(int startVertex, int endVertex);

private:
    const AdjacencyList& adjList;
};

#endif //PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_DIJKSTRAADJACENCYLIST_H
