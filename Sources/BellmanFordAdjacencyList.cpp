#include "../Headers/BellmanFordAdjacencyList.h"
#include <limits>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

BellmanFordAdjacencyList::BellmanFordAdjacencyList(const AdjacencyList& adjacencyList)
        : adjList(adjacencyList) {}

bool BellmanFordAdjacencyList::findShortestPath(int startVertex, int endVertex) {
    auto startTime = chrono::high_resolution_clock::now();

    int vertices = adjList.getVertices();
    dist.resize(vertices, numeric_limits<int>::max());
    prev.resize(vertices, -1);

    dist[startVertex] = 0;

    for (int i = 1; i < vertices; ++i) {
        bool updated = false;
        for (int u = 0; u < vertices; ++u) {
            for (const auto& edge : adjList.getAdjList()[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    updated = true;
                }
            }
        }
        if (!updated) {
            break;
        }
    }

    for (int u = 0; u < vertices; ++u) {
        for (const auto& edge : adjList.getAdjList()[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                cout << "Negative weight cycle detected!" << endl;
                return false;
            }
        }
    }

    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = endTime - startTime; // Changed to milliseconds

    // Update adjacency list
    const_cast<AdjacencyList&>(adjList).updateListForBellmanFord(dist, prev);

    if (dist[endVertex] == numeric_limits<int>::max()) {
        cout << "No path from " << startVertex << " to " << endVertex << endl;
        return false;
    }

    vector<int> path;
    for (int at = endVertex; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    cout << "Shortest path from " << startVertex << " to " << endVertex << ": ";
    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0) cout << " -> ";
        cout << path[i];
    }
    cout << " with total weight " << dist[endVertex] << endl;
    cout << "Elapsed time: " << elapsed.count() << " ms" << endl; // Changed output to milliseconds

    return true;
}
