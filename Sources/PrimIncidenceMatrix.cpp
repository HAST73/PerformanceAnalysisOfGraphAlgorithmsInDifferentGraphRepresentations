#include "../Headers/PrimIncidenceMatrix.h"
#include "../Headers/IncidentMatrix.h"
#include <vector>
#include <iostream>
#include <climits>

void PrimIncidenceMatrix::run(IncidentMatrix* graph, int startVertex) {
    int vertices = graph->getVertices();
    int edges = graph->getEdges();
    std::vector<int> key(vertices, INT_MAX);
    std::vector<bool> inMST(vertices, false);
    std::vector<int> parent(vertices, -1);

    key[startVertex] = 0;

    for (int i = 0; i < vertices - 1; ++i) {
        int u = -1;

        for (int v = 0; v < vertices; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        if (u == -1) break;

        inMST[u] = true;

        for (int e = 0; e < edges; ++ e) {
            int v = -1;
            const auto& matrix = graph->getMatrix();
            if (matrix[u][e] == 1) {
                for (int i = 0; i < vertices; ++i) {
                    if (i != u && matrix[i][e] == 1) {
                        v = i;
                        break;
                    }
                }
            }
            if (v != -1 && !inMST[v] && matrix[u][e] < key[v]) {
                key[v] = matrix[u][e];
                parent[v] = u;
            }
        }
    }

    std::cout << "Minimum Spanning Tree (Prim's Algorithm):" << std::endl;
    for (int i = 0; i < vertices; ++i) {
        if (parent[i] != -1) {
            std::cout << parent[i] << " - " << i << std::endl;
        }
    }
}