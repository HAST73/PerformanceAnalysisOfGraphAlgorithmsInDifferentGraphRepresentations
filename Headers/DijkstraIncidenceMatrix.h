#ifndef PROJECT_AIZO_2_DIJKSTRAINCIDENCEMATRIX_H
#define PROJECT_AIZO_2_DIJKSTRAINCIDENCEMATRIX_H

#include "../Headers/IncidentMatrix.h"

class DijkstraIncidenceMatrix {
public:
    DijkstraIncidenceMatrix(const IncidentMatrix& incMatrix);
    void findShortestPath(int startVertex, int endVertex);

private:
    const IncidentMatrix& incMatrix;
};


#endif //PROJECT_AIZO_2_DIJKSTRAINCIDENCEMATRIX_H
