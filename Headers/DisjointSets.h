#ifndef PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_DISJOINTSETS_H
#define PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_DISJOINTSETS_H

#include <vector>

using namespace std;

class DisjointSets {
public:
    DisjointSets(int n);
    int find(int u);
    void unite(int u, int v);

private:
    vector<int> parent;
    vector<int> rank;
};

#endif //PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_DISJOINTSETS_H
