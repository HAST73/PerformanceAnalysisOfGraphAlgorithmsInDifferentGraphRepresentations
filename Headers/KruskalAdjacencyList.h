#ifndef PROJECT_AIZO_2_KRUSKALADJACENCYLIST_H
#define PROJECT_AIZO_2_KRUSKALADJACENCYLIST_H

#include <vector>
#include "../Headers/AdjacencyList.h"
#include "../Headers/DisjointSets.h"

class KruskalAdjacencyList {
public:
    struct Edge {
        int u, v, weight;
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };

    static void run(AdjacencyList* graph, int startVertex, int endVertex, bool directed);
    static std::vector<Edge> getEdges(const AdjacencyList* graph);
    static void updateAdjacencyList(AdjacencyList* graph, const std::vector<Edge>& mstEdges, bool directed);
};

#endif //PROJECT_AIZO_2_KRUSKALADJACENCYLIST_H
