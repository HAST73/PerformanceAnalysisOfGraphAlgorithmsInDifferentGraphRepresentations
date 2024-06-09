#ifndef PROJECT_AIZO_2_INCIDENTMATRIX_H
#define PROJECT_AIZO_2_INCIDENTMATRIX_H

#include <vector>
#include <iostream>

class IncidentMatrix {
public:
    IncidentMatrix(int vertices, int edges, bool directed);
    void addEdge(int v1, int v2, int edgeIndex, int weight = 1); // Add weight parameter
    void printMatrix();
    void printMatrix(int startVertex, int endVertex);
    int getVertices() const { return vertices; }
    int getEdges() const { return edges; }
    const std::vector<std::vector<int>>& getMatrix() const { return matrix; }

private:
    std::vector<std::vector<int>> matrix; // Incident Matrix for unweighted graph
    std::vector<std::vector<int>> weightedMatrix; // Incident Matrix for weighted graph
    int vertices;
    int edges;
    bool directed;
};

#endif //PROJECT_AIZO_2_INCIDENTMATRIX_H