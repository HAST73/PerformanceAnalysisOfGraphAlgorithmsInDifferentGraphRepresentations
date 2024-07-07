#ifndef PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_KRUSKALINCIDENCEMATRIX_H
#define PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_KRUSKALINCIDENCEMATRIX_H

#include <vector>
#include "../Headers/IncidentMatrix.h"
#include "../Headers/DisjointSets.h"

using namespace std;

class KruskalIncidenceMatrix {
public:
    struct Edge {
        int u, v, weight;
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };

    static vector<Edge> getEdges(const IncidentMatrix* graph);
    static void run(IncidentMatrix* graph, int startVertex, int endVertex);
    static void updateIncidentMatrix(IncidentMatrix* graph, const vector<Edge>& mstEdges, int startVertex, int endVertex);
};

#endif //PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_KRUSKALINCIDENCEMATRIX_H
