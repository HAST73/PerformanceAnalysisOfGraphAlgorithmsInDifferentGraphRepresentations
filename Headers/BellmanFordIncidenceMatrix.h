#ifndef PROJECT_AIZO_2_BELLMANFORDINCIDENCEMATRIX_H
#define PROJECT_AIZO_2_BELLMANFORDINCIDENCEMATRIX_H

#include "../Headers/IncidentMatrix.h"
#include <vector>

class BellmanFordIncidenceMatrix {
public:
    BellmanFordIncidenceMatrix(const IncidentMatrix& incidentMatrix);
    bool findShortestPath(int startVertex, int endVertex);
    const std::vector<int>& getDistances() const { return dist; }
    const std::vector<int>& getPredecessors() const { return prev; }

private:
    const IncidentMatrix& incMatrix;
    std::vector<int> dist;
    std::vector<int> prev;
};

#endif //PROJECT_AIZO_2_BELLMANFORDINCIDENCEMATRIX_H
