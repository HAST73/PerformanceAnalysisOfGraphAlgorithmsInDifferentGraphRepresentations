#include "../Headers/MSTree.h"
#include <iostream>

MSTree::MSTree(int vertices)
        : adjacencyList(vertices, nullptr), totalWeight(0) {}

MSTree::~MSTree() {
    for (auto node : adjacencyList) {
        while (node) {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
    }
}

void MSTree::addEdge(int v1, int v2, int weight) {
    Node* node1 = new Node{v2, weight, adjacencyList[v1]};
    adjacencyList[v1] = node1;

    Node* node2 = new Node{v1, weight, adjacencyList[v2]};
    adjacencyList[v2] = node2;

    totalWeight += weight;
}

void MSTree::print() const {
    std::cout << "Minimum Spanning Tree (MST):\n";
    for (int i = 0; i < adjacencyList.size(); ++i) {
        std::cout << "Vertex " << i << ": ";
        Node* node = adjacencyList[i];
        while (node) {
            std::cout << "-> (" << node->vertex << ", " << node->weight << ") ";
            node = node->next;
        }
        std::cout << "\n";
    }
    std::cout << "Total weight of MST: " << totalWeight << "\n";
}
