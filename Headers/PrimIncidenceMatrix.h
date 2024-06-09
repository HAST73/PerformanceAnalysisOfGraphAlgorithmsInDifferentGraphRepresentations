#ifndef PROJECT_AIZO_2_PRIMINCIDENCEMATRIX_H
#define PROJECT_AIZO_2_PRIMINCIDENCEMATRIX_H

#include "../Headers/IncidentMatrix.h"

class PrimIncidenceMatrix {
public:
    static void run(IncidentMatrix* graph, int startVertex, int endVertex); // Added endVertex parameter
};

#endif //PROJECT_AIZO_2_PRIMINCIDENCEMATRIX_H