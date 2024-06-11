#ifndef PROJECT_AIZO_2_INCIDENTMATRIX_H
#define PROJECT_AIZO_2_INCIDENTMATRIX_H

#include <vector>
#include <iostream>

class IncidentMatrix {
public:
    IncidentMatrix(int vertices, int edges, bool directed);
    void addEdge(int v1, int v2, int edgeIndex, int weight = 1);
    void printMatrix();
    void printMatrix(int startVertex, int endVertex);
    int getVertices() const { return vertices; }
    int getEdges() const { return edges; }
    const std::vector<std::vector<int>>& getMatrix() const { return matrix; }
    void initialize(int vertices, int edges);
    void clear();
    void updateMatrixForDijkstra(const std::vector<int>& dist, const std::vector<int>& prev);
    void updateMatrixForBellmanFord(const std::vector<int>& dist, const std::vector<int>& prev);

private:
    std::vector<std::vector<int>> matrix;
    int vertices;
    int edges;
    bool directed;
};

#endif //PROJECT_AIZO_2_INCIDENTMATRIX_H
