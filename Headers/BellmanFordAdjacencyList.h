#ifndef PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_BELLMANFORDADJACENCYLIST_H
#define PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_BELLMANFORDADJACENCYLIST_H

#include "../Headers/AdjacencyList.h"
#include <vector>

using namespace std;

class BellmanFordAdjacencyList {
public:
    BellmanFordAdjacencyList(const AdjacencyList& adjacencyList);
    bool findShortestPath(int startVertex, int endVertex);
    const vector<int>& getDistances() const { return dist; }
    const vector<int>& getPredecessors() const { return prev; }

private:
    const AdjacencyList& adjList;
    vector<int> dist;
    vector<int> prev;
};

#endif //PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_BELLMANFORDADJACENCYLIST_H
