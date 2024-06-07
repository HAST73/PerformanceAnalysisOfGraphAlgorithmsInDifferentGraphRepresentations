#ifndef PROJECT_AIZO_2_ADJACENCYLISTS_H
#define PROJECT_AIZO_2_ADJACENCYLISTS_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <tuple>

class AdjacencyList {
private:
    int n;
    std::vector<std::vector<std::tuple<int, int>>> adjacencyList;

public:
    AdjacencyList(int vertices);
    void addEdge(int v1, int v2, int weight, bool directed);
    void printList() const;
    int vertexDegree(int vertexIndex) const;
    std::vector<std::tuple<int, int>> neighbors(int vertexIndex) const;
    bool isIsolated(int vertexIndex) const;
};


#endif //PROJECT_AIZO_2_ADJACENCYLISTS_H
