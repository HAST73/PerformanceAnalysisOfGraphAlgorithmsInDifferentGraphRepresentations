#include "../Headers/DijkstraIncidenceMatrix.h"
#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <algorithm>
#include <chrono>

DijkstraIncidenceMatrix::DijkstraIncidenceMatrix(const IncidentMatrix& incMatrix)
        : incMatrix(incMatrix) {}

void DijkstraIncidenceMatrix::findShortestPath(int startVertex, int endVertex) {
//    auto startTime = std::chrono::high_resolution_clock::now();

    int vertices = incMatrix.getVertices();
    int edges = incMatrix.getEdges();
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

        for (int edge = 0; edge < edges; ++edge) {
            if (incMatrix.getMatrix()[u][edge] > 0) {
                int v = -1;
                for (int i = 0; i < vertices; ++i) {
                    if (incMatrix.getMatrix()[i][edge] < 0) {
                        v = i;
                        break;
                    }
                }

                if (v != -1) {
                    int weight = incMatrix.getMatrix()[u][edge];
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        prev[v] = u;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
    }

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

    const_cast<IncidentMatrix&>(incMatrix).updateMatrixForDijkstra(dist, prev);
}

