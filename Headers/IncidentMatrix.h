#ifndef PROJECT_AIZO_2_INCIDENTMATRIX_H
#define PROJECT_AIZO_2_INCIDENTMATRIX_H

#include <vector>
#include <iostream>
#include <iomanip>

class IncidentMatrix {
private:
    int n; // number of vertices
    int m; // number of edges
    bool directed;
    std::vector<std::vector<signed char>> incidenceMatrix;

public:
    IncidentMatrix(int vertices, int edges, bool isDirected);
    void addEdge(int v1, int v2, int edgeIndex);
    void printMatrix();
    int vertexDegree(int vertexIndex);
    std::vector<int> neighbors(int vertexIndex);
    bool isIsolated(int vertexIndex);
};

#endif //PROJECT_AIZO_2_INCIDENTMATRIX_H
