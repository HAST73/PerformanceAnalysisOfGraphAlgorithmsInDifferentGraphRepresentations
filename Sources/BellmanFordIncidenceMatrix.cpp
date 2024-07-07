#include "../Headers/BellmanFordIncidenceMatrix.h"
#include <limits>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

BellmanFordIncidenceMatrix::BellmanFordIncidenceMatrix(const IncidentMatrix& incidentMatrix)
        : incMatrix(incidentMatrix) {}

bool BellmanFordIncidenceMatrix::findShortestPath(int startVertex, int endVertex) {
    auto startTime = chrono::high_resolution_clock::now();

    int vertices = incMatrix.getVertices();
    int edges = incMatrix.getEdges();
    dist.resize(vertices, numeric_limits<int>::max());
    prev.resize(vertices, -1);

    dist[startVertex] = 0;

    for (int i = 1; i < vertices; ++i) {
        bool updated = false;
        for (int e = 0; e < edges; ++e) {
            int u = -1, v = -1, weight = 0;
            for (int vertex = 0; vertex < vertices; ++vertex) {
                int edgeValue = incMatrix.getMatrix()[vertex][e];
                if (edgeValue != 0) {
                    if (edgeValue > 0) {
                        u = vertex;
                    } else {
                        v = vertex;
                        weight = edgeValue;
                    }
                }
            }
            if (u != -1 && v != -1 && dist[u] != numeric_limits<int>::max() && dist[u] + (-weight) < dist[v]) {
                dist[v] = dist[u] + (-weight);
                prev[v] = u;
                updated = true;
            }
        }
        if (!updated) {
            break;
        }
    }

    for (int e = 0; e < edges; ++e) {
        int u = -1, v = -1, weight = 0;
        for (int vertex = 0; vertex < vertices; ++vertex) {
            int edgeValue = incMatrix.getMatrix()[vertex][e];
            if (edgeValue != 0) {
                if (edgeValue > 0) {
                    u = vertex;
                } else {
                    v = vertex;
                    weight = edgeValue;
                }
            }
        }
        if (u != -1 && v != -1 && dist[u] != numeric_limits<int>::max() && dist[u] + (-weight) < dist[v]) {
            cout << "Negative weight cycle detected!" << endl;
            return false;
        }
    }

    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = endTime - startTime; // Changed to milliseconds

    const_cast<IncidentMatrix&>(incMatrix).updateMatrixForBellmanFord(dist, prev);

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
