#include "../Headers/DijkstraAdjacencyList.h"
#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

DijkstraAdjacencyList::DijkstraAdjacencyList(const AdjacencyList& adjList)
        : adjList(adjList) {}

void DijkstraAdjacencyList::findShortestPath(int startVertex, int endVertex) {
    auto startTime = chrono::high_resolution_clock::now();

    int vertices = adjList.getVertices();
    vector<int> dist(vertices, numeric_limits<int>::max());
    vector<int> prev(vertices, -1);
    dist[startVertex] = 0;

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, startVertex});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == endVertex) break;

        for (const auto& neighbor : adjList.getAdjList()[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = endTime - startTime; // Changed to milliseconds

    if (dist[endVertex] == numeric_limits<int>::max()) {
        cout << "No path from " << startVertex << " to " << endVertex << endl;
        return;
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

    // Update the adjacency list with the shortest path information
    const_cast<AdjacencyList&>(adjList).updateListForDijkstra(dist, prev);
}
