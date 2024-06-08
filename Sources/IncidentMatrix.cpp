#include "../Headers/IncidentMatrix.h"
#include <iostream>
#include <iomanip>
#include <vector>

IncidentMatrix::IncidentMatrix(int vertices, int edges, bool directed)
        : vertices(vertices), edges(edges), directed(directed) {
    matrix.resize(vertices, std::vector<int>(edges, 0));
}

void IncidentMatrix::addEdge(int v1, int v2, int edgeIndex) {
    if (directed) {
        matrix[v1][edgeIndex] = 1;
        matrix[v2][edgeIndex] = -1;
    } else {
        matrix[v1][edgeIndex] = 1;
        matrix[v2][edgeIndex] = 1;
    }
}

void IncidentMatrix::printMatrix() {
    // Print column headers
    std::cout << "   ";
    for (int j = 0; j < edges; ++j) {
        std::cout << std::setw(2) << j << " ";
    }
    std::cout << std::endl;

    // Print rows with row indices
    for (int i = 0; i < vertices; ++i) {
        std::cout << std::setw(2) << i << " ";
        for (const auto& val : matrix[i]) {
            std::cout << std::setw(2) << val << " ";
        }
        std::cout << std::endl;
    }
}