#ifndef PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_INCIDENTMATRIX_H
#define PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_INCIDENTMATRIX_H

#include <vector>
#include <iostream>

using namespace std;

class IncidentMatrix {
public:
    IncidentMatrix(int vertices, int edges, bool directed);
    void addEdge(int v1, int v2, int edgeIndex, int weight = 1);
    void printMatrix();
    void printMatrix(int startVertex, int endVertex);
    int getVertices() const { return vertices; }
    int getEdges() const { return edges; }
    const vector<vector<int>>& getMatrix() const { return matrix; }
    void initialize(int vertices, int edges);
    void clear();
    void updateMatrixForDijkstra(const vector<int>& dist, const vector<int>& prev);
    void updateMatrixForBellmanFord(const vector<int>& dist, const vector<int>& prev);

private:
    vector<vector<int>> matrix;
    int vertices;
    int edges;
    bool directed;
};

#endif //PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_INCIDENTMATRIX_H
