#ifndef PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_BELLMANFORDINCIDENCEMATRIX_H
#define PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_BELLMANFORDINCIDENCEMATRIX_H

#include "../Headers/IncidentMatrix.h"
#include <vector>

using namespace std;

class BellmanFordIncidenceMatrix {
public:
    BellmanFordIncidenceMatrix(const IncidentMatrix& incidentMatrix);
    bool findShortestPath(int startVertex, int endVertex);
    const vector<int>& getDistances() const { return dist; }
    const vector<int>& getPredecessors() const { return prev; }

private:
    const IncidentMatrix& incMatrix;
    vector<int> dist;
    vector<int> prev;
};

#endif //PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_BELLMANFORDINCIDENCEMATRIX_H
