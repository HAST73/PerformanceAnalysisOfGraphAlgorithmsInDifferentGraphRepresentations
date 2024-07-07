#include "../Headers/KruskalIncidenceMatrix.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<KruskalIncidenceMatrix::Edge> KruskalIncidenceMatrix::getEdges(const IncidentMatrix* graph) {
    vector<Edge> edges;
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

void KruskalIncidenceMatrix::updateIncidentMatrix(IncidentMatrix* graph, const vector<Edge>& mstEdges, int startVertex, int endVertex) {
    graph->clear();
    int newVerticesCount = endVertex - startVertex + 1;
    graph->initialize(newVerticesCount, mstEdges.size());
    int edgeIndex = 0;

    for (const auto& edge : mstEdges) {
        graph->addEdge(edge.u - startVertex, edge.v - startVertex, edgeIndex++, edge.weight);
    }
}

void KruskalIncidenceMatrix::run(IncidentMatrix* graph, int startVertex, int endVertex) {
    auto startTime = chrono::high_resolution_clock::now();

    vector<Edge> edges = getEdges(graph);
    sort(edges.begin(), edges.end());
    DisjointSets ds(endVertex - startVertex + 1);
    vector<Edge> result;
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

    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = endTime - startTime; // Changed to milliseconds

    cout << "Minimum Spanning Tree using Kruskal's Algorithm (Incidence Matrix):" << endl;
    for (const auto& edge : result) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
    cout << "Elapsed time: " << elapsed.count() << " ms" << endl; // Changed output to milliseconds
}
