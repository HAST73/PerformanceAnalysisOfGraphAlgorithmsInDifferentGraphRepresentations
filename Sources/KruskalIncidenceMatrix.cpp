#include "../Headers/KruskalIncidenceMatrix.h"
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<KruskalIncidenceMatrix::Edge> KruskalIncidenceMatrix::getEdges(const IncidentMatrix* graph) {
    std::vector<Edge> edges;
    int vertices = graph->getVertices();
    int edgesCount = graph->getEdges();

    for (int i = 0; i < vertices; ++i) {
        for (int j = i + 1; j < vertices; ++j) {
            for (int k = 0; k < edgesCount; ++k) {
                int weight = graph->getMatrix()[i][k];
                if (weight != 0 && graph->getMatrix()[j][k] == weight) {
                    edges.push_back({i, j, weight});
                    break;
                }
            }
        }
    }

    return edges;
}

void KruskalIncidenceMatrix::updateIncidentMatrix(IncidentMatrix* graph, const std::vector<Edge>& mstEdges, int startVertex, int endVertex) {
    // Wyczyść macierz incydencji
    graph->clear();  // Zakładamy, że metoda clear() usuwa wszystkie dane z macierzy

    int newVerticesCount = endVertex - startVertex + 1;
    graph->initialize(newVerticesCount, mstEdges.size());
    int edgeIndex = 0;

    for (const auto& edge : mstEdges) {
        graph->addEdge(edge.u - startVertex, edge.v - startVertex, edgeIndex++, edge.weight);
    }
}

void KruskalIncidenceMatrix::run(IncidentMatrix* graph, int startVertex, int endVertex) {
    std::vector<Edge> edges = getEdges(graph);
    std::sort(edges.begin(), edges.end());

    DisjointSets ds(endVertex - startVertex + 1); // Initialize with the adjusted vertex range
    std::vector<Edge> result;
    int totalWeight = 0;

    for (const auto& edge : edges) {
        if (edge.u >= startVertex && edge.u <= endVertex && edge.v >= startVertex && edge.v <= endVertex) {
            int adjusted_u = edge.u - startVertex;
            int adjusted_v = edge.v - startVertex;
            if (ds.find(adjusted_u) != ds.find(adjusted_v)) {
                result.push_back({edge.u, edge.v, edge.weight});
                ds.unite(adjusted_u, adjusted_v);
                totalWeight += edge.weight;
            }
        }
    }

    updateIncidentMatrix(graph, result, startVertex, endVertex);

    std::cout << "Minimum Spanning Tree using Kruskal's Algorithm (Incidence Matrix):" << std::endl;
    for (const auto& edge : result) {
        std::cout << edge.u << " -- " << edge.v << " == " << edge.weight << std::endl;
    }
    std::cout << "Total weight of MST: " << totalWeight << std::endl;
}
