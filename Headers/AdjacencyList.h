#ifndef PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_ADJACENCYLISTS_H
#define PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_ADJACENCYLISTS_H

#include <vector>
#include <list>
#include <iostream>
#include <utility>

using namespace std;

class AdjacencyList {
public:
    AdjacencyList(int vertices);
    void addEdge(int v1, int v2, int weight, bool directed);
    void printList();
    int getVertices() const { return vertices; }
    const vector<list<pair<int, int>>>& getAdjList() const { return adjList; }
    void clear();
    void updateListForDijkstra(const vector<int>& dist, const vector<int>& prev);
    void updateListForBellmanFord(const vector<int>& dist, const vector<int>& prev);

private:
    vector<list<pair<int, int>>> adjList;
    int vertices;
};

#endif //PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_ADJACENCYLISTS_H
