#ifndef PROJECT_AIZO_2_KRUSKALINCIDENCEMATRIX_H
#define PROJECT_AIZO_2_KRUSKALINCIDENCEMATRIX_H

#include <vector>
#include "../Headers/IncidentMatrix.h"
#include "../Headers/DisjointSets.h"

class KruskalIncidenceMatrix {
public:
    struct Edge {
        int u, v, weight;
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };

    static std::vector<Edge> getEdges(const IncidentMatrix* graph);
    static void run(IncidentMatrix* graph, int startVertex, int endVertex);
    static void updateIncidentMatrix(IncidentMatrix* graph, const std::vector<Edge>& mstEdges, int startVertex, int endVertex);
};

#endif //PROJECT_AIZO_2_KRUSKALINCIDENCEMATRIX_H
