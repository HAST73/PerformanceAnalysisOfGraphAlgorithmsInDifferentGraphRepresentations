#include "../Headers/IncidentMatrix.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

IncidentMatrix::IncidentMatrix(int vertices, int edges, bool directed)
        : vertices(vertices), edges(edges), directed(directed) {
    matrix.resize(vertices, vector<int>(edges, 0));
}

void IncidentMatrix::addEdge(int v1, int v2, int edgeIndex, int weight) {
    if (directed) {
        matrix[v1][edgeIndex] = weight;
        matrix[v2][edgeIndex] = -weight;
    } else {
        matrix[v1][edgeIndex] = weight;
        matrix[v2][edgeIndex] = weight;
    }
}

void IncidentMatrix::printMatrix() {
    int maxWidth = 10; // Set a more practical maximum width for each line
    int numChunks = (edges + maxWidth - 1) / maxWidth; // Calculate number of chunks

    for (int chunk = 0; chunk < numChunks; ++chunk) {
        int startEdge = chunk * maxWidth;
        int endEdge = min(startEdge + maxWidth, edges);

        cout << "   ";
        for (int j = startEdge; j < endEdge; ++j) {
            cout << setw(3) << j << " "; // Adjusted width to 3 for better spacing
        }
        cout << endl;

        for (int i = 0; i < vertices; ++i) {
            cout << setw(2) << i << " ";
            for (int j = startEdge; j < endEdge; ++j) {
                cout << setw(3) << matrix[i][j] << " "; // Adjusted width to 3 for better spacing
            }
            cout << endl;
        }
        cout << endl;
    }
}

void IncidentMatrix::printMatrix(int startVertex, int endVertex) {
    int maxWidth = 10; // Set a more practical maximum width for each line
    int numChunks = (edges + maxWidth - 1) / maxWidth; // Calculate number of chunks

    for (int chunk = 0; chunk < numChunks; ++chunk) {
        int startEdge = chunk * maxWidth;
        int endEdge = min(startEdge + maxWidth, edges);

        cout << "   ";
        for (int j = startEdge; j < endEdge; ++j) {
            cout << setw(3) << j << " "; // Adjusted width to 3 for better spacing
        }
        cout << endl;

        for (int i = startVertex; i <= endVertex; ++i) {
            cout << setw(2) << i << " ";
            for (int j = startEdge; j < endEdge; ++j) {
                cout << setw(3) << matrix[i][j] << " "; // Adjusted width to 3 for better spacing
            }
            cout << endl;
        }
        cout << endl;
    }
}

void IncidentMatrix::initialize(int vertices, int edges) {
    matrix.resize(vertices, vector<int>(edges, 0));
    this->vertices = vertices;
    this->edges = edges;
}

void IncidentMatrix::clear() {
    for (auto& row : matrix) {
        fill(row.begin(), row.end(), 0);
    }
}

void IncidentMatrix::updateMatrixForDijkstra(const vector<int>& dist, const vector<int>& prev) {
    clear();
    int usedEdges = 0;
    for (int i = 0; i < dist.size(); ++i) {
        if (prev[i] != -1) {
            ++usedEdges;
        }
    }

    initialize(vertices, usedEdges);
    int edgeIndex = 0;
    for (int i = 0; i < vertices; ++i) {
        if (prev[i] != -1) {
            addEdge(prev[i], i, edgeIndex++, dist[i] - dist[prev[i]]);
        }
    }
}

void IncidentMatrix::updateMatrixForBellmanFord(const vector<int>& dist, const vector<int>& prev) {
    clear();
    int usedEdges = 0;
    for (int i = 0; i < dist.size(); ++i) {
        if (prev[i] != -1) {
            ++usedEdges;
        }
    }

    initialize(vertices, usedEdges);
    int edgeIndex = 0;
    for (int i = 0; i < vertices; ++i) {
        if (prev[i] != -1) {
            addEdge(prev[i], i, edgeIndex++, dist[i] - dist[prev[i]]);
        }
    }
}
