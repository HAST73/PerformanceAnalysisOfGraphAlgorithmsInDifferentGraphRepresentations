#include "../Headers/PrimAdjacencyList.h"
#include "../Headers/AdjacencyList.h"
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

void PrimAdjacencyList::run(AdjacencyList* graph, int startVertex, int endVertex) {
    int totalVertices = graph->getVertices();
    int vertices = endVertex - startVertex + 1;

    std::vector<int> key(totalVertices, INT_MAX);
    std::vector<bool> inMST(totalVertices, false);
    std::vector<int> parent(totalVertices, -1);

    key[startVertex] = 0;
    using PII = std::pair<int, int>;
    std::priority_queue<PII, std::vector<PII>, std::greater<PII>> pq;
    pq.push({0, startVertex});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u < startVertex || u > endVertex || inMST[u]) continue;
        inMST[u] = true;

        for (const auto& [v, weight] : graph->getAdjList()[u]) {
            if (v >= startVertex && v <= endVertex && !inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    graph->clear();
    for (int i = 0; i < totalVertices; ++i) {
        if (parent[i] != -1 && i >= startVertex && i <= endVertex) {
            graph->addEdge(parent[i], i, key[i], false);
        }
    }
}
