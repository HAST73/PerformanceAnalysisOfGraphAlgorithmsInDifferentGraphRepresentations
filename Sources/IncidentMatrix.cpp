#include "../Headers/IncidentMatrix.h"
#include <iostream>
#include <iomanip>
#include <vector>

IncidentMatrix::IncidentMatrix(int vertices, int edges, bool directed)
        : vertices(vertices), edges(edges), directed(directed) {
    matrix.resize(vertices, std::vector<int>(edges, 0));
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
    std::cout << "   ";
    for (int j = 0; j < edges; ++j) {
        std::cout << std::setw(2) << j << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < vertices; ++i) {
        std::cout << std::setw(2) << i << " ";
        for (const auto& val : matrix[i]) {
            std::cout << std::setw(2) << val << " ";
        }
        std::cout << std::endl;
    }
}

void IncidentMatrix::printMatrix(int startVertex, int endVertex) {
    std::cout << "   ";
    for (int j = 0; j < edges; ++j) {
        std::cout << std::setw(2) << j << " ";
    }
    std::cout << std::endl;

    for (int i = startVertex; i <= endVertex; ++i) {
        std::cout << std::setw(2) << i << " ";
        for (int j = 0; j < edges; ++j) {
            std::cout << std::setw(2) << matrix[i - startVertex][j] << " ";
        }
        std::cout << std::endl;
    }
}

void IncidentMatrix::initialize(int vertices, int edges) {
    matrix.resize(vertices, std::vector<int>(edges, 0));
    this->vertices = vertices;
    this->edges = edges;
}

void IncidentMatrix::clear() {
    for (auto& row : matrix) {
        std::fill(row.begin(), row.end(), 0);
    }
}

void IncidentMatrix::updateMatrixForDijkstra(const std::vector<int>& dist, const std::vector<int>& prev) {
    // Clear the existing matrix
    clear();

    // Determine the number of edges used in the shortest path
    int usedEdges = 0;
    for (int i = 0; i < dist.size(); ++i) {
        if (prev[i] != -1) {
            ++usedEdges;
        }
    }

    // Reinitialize the matrix with reduced columns based on the used edges
    initialize(vertices, usedEdges);

    // Populate the matrix with edge weights from Dijkstra's algorithm
    int edgeIndex = 0;
    for (int i = 0; i < vertices; ++i) {
        if (prev[i] != -1) {
            addEdge(prev[i], i, edgeIndex++, dist[i] - dist[prev[i]]);
        }
    }

    // Remove columns containing only zeros and without any rows
    if (!matrix.empty()) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        for (int j = numCols - 1; j >= 0; --j) {
            bool isZeroColumn = true;
            for (int i = 0; i < numRows; ++i) {
                if (matrix[i][j] != 0) {
                    isZeroColumn = false;
                    break;
                }
            }
            if (isZeroColumn && numRows == vertices) {
                for (int i = 0; i < numRows; ++i) {
                    matrix[i].erase(matrix[i].begin() + j);
                }
            }
        }
    }
}




