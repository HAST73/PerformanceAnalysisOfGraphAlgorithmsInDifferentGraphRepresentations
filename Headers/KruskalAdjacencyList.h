#ifndef PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_KRUSKALADJACENCYLIST_H
#define PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_KRUSKALADJACENCYLIST_H

#include <vector>
#include "../Headers/AdjacencyList.h"
#include "../Headers/DisjointSets.h"

using namespace std;

class KruskalAdjacencyList {
public:
    struct Edge {
        int u, v, weight;
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };

    static void run(AdjacencyList* graph, int startVertex, int endVertex, bool directed);
    static vector<Edge> getEdges(const AdjacencyList* graph);
    static void updateAdjacencyList(AdjacencyList* graph, const vector<Edge>& mstEdges, bool directed);
};

#endif //PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_KRUSKALADJACENCYLIST_H
