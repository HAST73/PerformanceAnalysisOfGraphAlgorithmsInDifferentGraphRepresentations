#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include "../Headers/AdjacencyList.h"
#include "../Headers/DisjointSets.h"
#include "../Headers/KruskalAdjacencyList.h"

using namespace std;

vector<KruskalAdjacencyList::Edge> KruskalAdjacencyList::getEdges(const AdjacencyList* graph) {
    vector<Edge> edges;
    int vertices = graph->getVertices();

    for (int u = 0; u < vertices; ++u) {
        for (const auto& [v, weight] : graph->getAdjList()[u]) {
            if (u < v) { // Avoid duplicate edges
                edges.push_back({u, v, weight});
            }
        }
    }

    return edges;
}

void KruskalAdjacencyList::updateAdjacencyList(AdjacencyList* graph, const vector<Edge>& mstEdges, bool directed) {
    graph->clear();
    for (const auto& edge : mstEdges) {
        graph->addEdge(edge.u, edge.v, edge.weight, directed);
    }
}

void KruskalAdjacencyList::run(AdjacencyList* graph, int startVertex, int endVertex, bool directed) {
    auto startTime = chrono::high_resolution_clock::now();

    vector<Edge> edges = getEdges(graph);
    sort(edges.begin(), edges.end()); // Sort edges by weight in ascending order

    DisjointSets ds(graph->getVertices());
    vector<Edge> result;
    int totalWeight = 0;

    for (const auto& edge : edges) {
        // Check if both vertices are within the specified range
        if ((edge.u >= startVertex && edge.u <= endVertex) && (edge.v >= startVertex && edge.v <= endVertex)) {
            if (ds.find(edge.u) != ds.find(edge.v)) {
                result.push_back(edge);
                ds.unite(edge.u, edge.v);
                totalWeight += edge.weight;
            }
        }
    }

    updateAdjacencyList(graph, result, directed);

    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = endTime - startTime; // Changed to milliseconds

    cout << "Minimum Spanning Tree using Kruskal's Algorithm (Adjacency List):" << endl;
    for (const auto& edge : result) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
    cout << "Elapsed time: " << elapsed.count() << " ms" << endl; // Changed output to milliseconds
}
