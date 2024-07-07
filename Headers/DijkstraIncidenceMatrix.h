#ifndef PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_DIJKSTRAINCIDENCEMATRIX_H
#define PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_DIJKSTRAINCIDENCEMATRIX_H

#include "../Headers/IncidentMatrix.h"

using namespace std;

class DijkstraIncidenceMatrix {
public:
    DijkstraIncidenceMatrix(const IncidentMatrix& incMatrix);
    void findShortestPath(int startVertex, int endVertex);

private:
    const IncidentMatrix& incMatrix;
};

#endif //PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_DIJKSTRAINCIDENCEMATRIX_H
