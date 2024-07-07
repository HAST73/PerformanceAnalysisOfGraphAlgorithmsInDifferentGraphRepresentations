#include "../Headers/PrimIncidenceMatrix.h"
#include "../Headers/IncidentMatrix.h"
#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <utility>
#include <chrono>

using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second; // Min-heap based on weight
    }
};

void PrimIncidenceMatrix::run(IncidentMatrix* graph, int startVertex, int endVertex) {
    auto start = chrono::high_resolution_clock::now(); // Start time measurement

    int vertices = graph->getVertices(); // Number of vertices
    int edges = graph->getEdges(); // Number of edges
    vector<int> key(vertices, INT_MAX); // Minimum weights to include vertices in MST
    vector<int> parent(vertices, -1); // Stores the MST
    vector<bool> inMST(vertices, false); // Keeps track of vertices included in MST
    vector<pair<int, int>> mstEdges; // Stores the edges in MST
    int totalCost = 0; // Total cost of MST

    key[startVertex] = 0; // Start from the startVertex

    // Priority queue to process vertices
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({startVertex, key[startVertex]});

    while (!pq.empty()) {
        int u = pq.top().first; // Get the vertex with the minimum key
        pq.pop();

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
                        weight = abs(matrix[u][e]);
                        break;
                    }
                }
            }

            // Only consider vertices in the range [startVertex, endVertex]
            if (v != -1 && v >= startVertex && v <= endVertex && !inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({v, key[v]});
            }
        }
    }

    // Collect the MST edges
    for (int i = startVertex; i <= endVertex; ++i) {
        if (parent[i] != -1 && i != startVertex) {
            mstEdges.push_back({parent[i], i});
        }
    }

    // Print MST paths from startVertex to endVertex and calculate total cost
    cout << "Minimum Spanning Tree (Prim's Algorithm) from vertex " << startVertex << " to vertex " << endVertex << ":" << endl;
    for (const auto& edge : mstEdges) {
        int u = edge.first;
        int v = edge.second;
        int weight = key[v];
        cout << u << " - " << v << " : " << weight << endl;
        totalCost += weight; // Add edge weight to total cost
    }

    // Print the total cost of MST
    cout << "Total cost of MST: " << totalCost << endl;

    // Create a new incidence matrix for the MST
    int newEdges = mstEdges.size();
    int newVertices = endVertex - startVertex + 1;
    IncidentMatrix newIncidentMatrix(newVertices, newEdges, false);

    for (int i = 0; i < mstEdges.size(); ++i) {
        int u = mstEdges[i].first - startVertex;
        int v = mstEdges[i].second - startVertex;
        int weight = key[mstEdges[i].second];
        newIncidentMatrix.addEdge(u, v, i, weight);
    }

    // Replace the old matrix with the new one
    *graph = newIncidentMatrix;

    auto end = chrono::high_resolution_clock::now(); // End time measurement
    double elapsed = chrono::duration<double, milli>(end - start).count(); // Calculate elapsed time
    cout << "Execution time: " << elapsed << " ms" << endl; // Print elapsed time
}
