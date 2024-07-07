#include "../Headers/AdjacencyList.h"
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>

using namespace std;

AdjacencyList::AdjacencyList(int vertices)
        : vertices(vertices) {
    adjList.resize(vertices);
}

void AdjacencyList::addEdge(int v1, int v2, int weight, bool directed) {
    adjList[v1].push_back(make_pair(v2, weight));
    if (!directed) {
        adjList[v2].push_back(make_pair(v1, weight));
    }
}

void AdjacencyList::printList() {
    // Calculate the maximum width for vertex numbers
    int maxWidth = to_string(vertices - 1).length();
    cout << endl;

    for (int i = 0; i < vertices; ++i) {
        cout << setw(maxWidth) << i << ": ";
        if (adjList[i].empty()) {
            cout << "None";
        } else {
            for (const auto& edge : adjList[i]) {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
        }
        cout << endl;
    }
}

void AdjacencyList::clear() {
    for (auto& edges : adjList) {
        edges.clear();
    }
}

void AdjacencyList::updateListForDijkstra(const vector<int>& dist, const vector<int>& prev) {
    // Clear the current adjacency list and rebuild it based on the shortest paths
    clear();
    for (int i = 0; i < vertices; ++i) {
        if (prev[i] != -1) {
            addEdge(prev[i], i, dist[i] - dist[prev[i]], true);
        }
    }
}

void AdjacencyList::updateListForBellmanFord(const vector<int>& dist, const vector<int>& prev) {
    // Clear the current adjacency list and rebuild it based on the shortest paths
    clear();
    for (int i = 0; i < vertices; ++i) {
        if (prev[i] != -1) {
            addEdge(prev[i], i, dist[i] - dist[prev[i]], true);
        }
    }
}
