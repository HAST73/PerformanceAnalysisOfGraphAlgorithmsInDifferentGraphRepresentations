#include "../Headers/PrimAdjacencyList.h"
#include "../Headers/AdjacencyList.h"
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>
#include <chrono>

using namespace std;

void PrimAdjacencyList::run(AdjacencyList* graph, int startVertex, int endVertex) {
    auto start = chrono::high_resolution_clock::now(); // Start time measurement

    int totalVertices = graph->getVertices();
    int vertices = endVertex - startVertex + 1;

    vector<int> key(totalVertices, INT_MAX);
    vector<bool> inMST(totalVertices, false);
    vector<int> parent(totalVertices, -1);

    key[startVertex] = 0;
    using PII = pair<int, int>;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, startVertex});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u < startVertex || u > endVertex || inMST[u]) continue;
        inMST[u] = true;

        for (const auto& [v, weight] : graph->getAdjList()[u]) {
            if (v >= startVertex && v <= endVertex && !inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    vector<pair<int, int>> mstEdges;
    int totalCost = 0;

    cout << "Minimum Spanning Tree (Prim's Algorithm) from vertex " << startVertex << " to vertex " << endVertex << ":" << endl;
    for (int i = startVertex; i <= endVertex; ++i) {
        if (parent[i] != -1) {
            mstEdges.push_back({parent[i], i});
            int weight = key[i];
            cout << parent[i] << " - " << i << " : " << weight << endl;
            totalCost += weight;
        }
    }

    cout << "Total cost of MST: " << totalCost << endl;

    // Clear the old graph and add MST edges
    graph->clear();
    for (const auto& [u, v] : mstEdges) {
        int weight = key[v];
        graph->addEdge(u, v, weight, false);
    }

    auto end = chrono::high_resolution_clock::now(); // End time measurement
    double elapsed = chrono::duration<double, milli>(end - start).count(); // Calculate elapsed time
    cout << "Execution time: " << elapsed << " ms" << endl; // Print elapsed time
}
