#ifndef PROJECT_AIZO_2_DISJOINTSETS_H
#define PROJECT_AIZO_2_DISJOINTSETS_H


#include <vector>

class DisjointSets {
public:
    DisjointSets(int n);
    int find(int u);
    void unite(int u, int v);

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

#endif //PROJECT_AIZO_2_DISJOINTSETS_H
