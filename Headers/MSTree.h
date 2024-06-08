#ifndef PROJECT_AIZO_2_MSTREE_H
#define PROJECT_AIZO_2_MSTREE_H


#include <vector>
#include <tuple>

class MSTree {
public:
    MSTree(int vertices);
    ~MSTree();
    void addEdge(int v1, int v2, int weight);
    void print() const;

private:
    struct Node {
        int vertex;
        int weight;
        Node* next;
    };

    std::vector<Node*> adjacencyList;
    int totalWeight;
};


#endif //PROJECT_AIZO_2_MSTREE_H
