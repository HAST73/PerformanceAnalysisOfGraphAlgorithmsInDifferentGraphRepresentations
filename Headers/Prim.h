#ifndef PROJECT_AIZO_2_PRIM_H
#define PROJECT_AIZO_2_PRIM_H

#include <vector>
#include <tuple>

class Prim {
public:
    Prim(int vertices);
    void addEdge(int v1, int v2, int weight);
    void findMST();
    void printMST() const;

private:
    int n;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;
    std::vector<std::tuple<int, int, int>> mst;
};

#endif //PROJECT_AIZO_2_PRIM_H