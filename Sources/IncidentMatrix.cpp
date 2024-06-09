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

void IncidentMatrix::printMatrix(int startVertex, int endVertex) {
    // Print column headers
    std::cout << "   ";
    for (int j = 0; j < edges; ++j) {
        std::cout << std::setw(2) << j << " ";
    }
    std::cout << std::endl;

    // Print rows with row indices based on the given range
    for (int i = startVertex; i <= endVertex; ++i) {
        std::cout << std::setw(2) << i << " "; // Print the original vertex index
        for (int j = 0; j < edges; ++j) {
            std::cout << std::setw(2) << matrix[i - startVertex][j] << " "; // Adjust index for proper alignment
        }
        std::cout << std::endl;
    }
}