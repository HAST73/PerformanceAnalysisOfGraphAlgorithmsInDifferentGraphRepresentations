#include "../Headers/PrimIncidenceMatrix.h"
#include "../Headers/IncidentMatrix.h"
#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <utility>

// Define a comparator for the priority queue
class Compare {
public:
    bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
        return a.second > b.second; // Min-heap based on weight
    }
};

void PrimIncidenceMatrix::run(IncidentMatrix* graph, int startVertex, int endVertex) {
    int vertices = graph->getVertices(); // Number of vertices
    int edges = graph->getEdges(); // Number of edges
    std::vector<int> key(vertices, INT_MAX); // Minimum weights to include vertices in MST
    std::vector<int> parent(vertices, -1); // Stores the MST
    std::vector<bool> inMST(vertices, false); // Keeps track of vertices included in MST

    key[startVertex] = 0; // Start from the startVertex

    // Priority queue to process vertices
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;
    pq.push({startVertex, key[startVertex]});

    while (!pq.empty()) {
        int u = pq.top().first; // Get the vertex with the minimum key
        pq.pop();

        if (u == endVertex) break; // Stop if we reached the end vertex

        inMST[u] = true; // Add vertex to MST

        const auto& matrix = graph->getMatrix(); // Get the incidence matrix
        for (int e = 0; e < edges; ++e) {
            int v = -1;
            int weight = 0;

            // Find the edge incident to u
            if (matrix[u][e] != 0) {
                for (int j = 0; j < vertices; ++j) {
                    if (j != u && matrix[j][e] != 0) {
                        v = j;
                        weight = matrix[u][e];
                        break;
                    }
                }
            }

            // Only consider vertices in the range [startVertex, endVertex]
            if (v >= startVertex && v <= endVertex && !inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({v, key[v]});
            }
        }
    }

    // Print MST paths from startVertex to endVertex
    std::cout << "Minimum Spanning Tree (Prim's Algorithm) from vertex " << startVertex << " to vertex " << endVertex << ":" << std::endl;
    for (int i = startVertex; i <= endVertex; ++i) {
        if (parent[i] != -1 && i != startVertex) {
            std::cout << parent[i] << " - " << i << " : " << key[i] << std::endl;
        }
    }
}
