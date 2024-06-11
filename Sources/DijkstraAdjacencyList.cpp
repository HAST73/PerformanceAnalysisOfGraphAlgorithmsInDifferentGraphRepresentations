#include "../Headers/DijkstraAdjacencyList.h"
#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <algorithm>
#include <chrono>

DijkstraAdjacencyList::DijkstraAdjacencyList(const AdjacencyList& adjList)
        : adjList(adjList) {}

void DijkstraAdjacencyList::findShortestPath(int startVertex, int endVertex) {
//    auto startTime = std::chrono::high_resolution_clock::now();

    int vertices = adjList.getVertices();
    std::vector<int> dist(vertices, std::numeric_limits<int>::max());
    std::vector<int> prev(vertices, -1);
    dist[startVertex] = 0;

    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
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
//
//    auto endTime = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double, std::milli> elapsed = endTime - startTime; // Changed to milliseconds

    if (dist[endVertex] == std::numeric_limits<int>::max()) {
        std::cout << "No path from " << startVertex << " to " << endVertex << std::endl;
        return;
    }

    std::vector<int> path;
    for (int at = endVertex; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());

    std::cout << "Shortest path from " << startVertex << " to " << endVertex << ": ";
    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0) std::cout << " -> ";
        std::cout << path[i];
    }
    std::cout << " with total weight " << dist[endVertex] << std::endl;
//    std::cout << "Elapsed time: " << elapsed.count() << " ms" << std::endl; // Changed output to milliseconds

    // Update the adjacency list with the shortest path information
    const_cast<AdjacencyList&>(adjList).updateListForDijkstra(dist, prev);
}

