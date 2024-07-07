#include "../Headers/DijkstraIncidenceMatrix.h"
#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

DijkstraIncidenceMatrix::DijkstraIncidenceMatrix(const IncidentMatrix& incMatrix)
        : incMatrix(incMatrix) {}

void DijkstraIncidenceMatrix::findShortestPath(int startVertex, int endVertex) {
    auto startTime = chrono::high_resolution_clock::now();

    int vertices = incMatrix.getVertices();
    int edges = incMatrix.getEdges();
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

    const_cast<IncidentMatrix&>(incMatrix).updateMatrixForDijkstra(dist, prev);
}
