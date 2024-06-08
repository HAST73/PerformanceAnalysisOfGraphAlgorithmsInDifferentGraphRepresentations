#include "../Headers/Prim.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>
#include <limits>

Prim::Prim(int vertices)
        : n(vertices), adjacencyList(vertices) {}

void Prim::addEdge(int v1, int v2, int weight) {
    adjacencyList[v1].emplace_back(v2, weight);
    adjacencyList[v2].emplace_back(v1, weight);
}

void Prim::findMST() {
    std::vector<bool> inMST(n, false);
    std::vector<int> key(n, std::numeric_limits<int>::max());
    std::vector<int> parent(n, -1);
    key[0] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (const auto& [v, weight] : adjacencyList[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.emplace(key[v], v);
                parent[v] = u;
            }
        }
    }

    mst.clear();
    for (int i = 1; i < n; ++i) {
        if (parent[i] != -1) {
            for (const auto& [v, weight] : adjacencyList[i]) {
                if (v == parent[i]) {
                    mst.emplace_back(parent[i], i, weight);
                    break;
                }
            }
        }
    }
}

void Prim::printMST() const {
    int totalWeight = 0;
    std::cout << "Edge   Weight" << std::endl;
    for (const auto& [u, v, weight] : mst) {
        std::cout << u << " - " << v << "    " << weight << std::endl;
        totalWeight += weight;
    }
    std::cout << "Total weight of MST: " << totalWeight << std::endl;
}