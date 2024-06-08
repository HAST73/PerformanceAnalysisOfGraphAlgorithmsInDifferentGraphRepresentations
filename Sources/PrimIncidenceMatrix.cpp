#include "../Headers/PrimIncidenceMatrix.h"
#include "../Headers/IncidentMatrix.h"
#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <utility>

// Define a comparator for the priority queue
class Compare {
public:
    bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
        return a.second > b.second; // Min-heap based on weight
    }
};

void PrimIncidenceMatrix::run(IncidentMatrix* graph, int startVertex) {
    int vertices = graph->getVertices(); // Liczba wierzchołków
    int edges = graph->getEdges(); // Liczba krawędzi
    std::vector<int> key(vertices, INT_MAX); // Minimalne wagi dołączenia wierzchołków do MST
    std::vector<int> parent(vertices, -1); // Przechowuje MST
    std::vector<bool> inMST(vertices, false); // Przechowuje informacje, czy wierzchołek jest już w MST

    key[startVertex] = 0; // Startujemy od startVertex

    // Kolejka priorytetowa do przetwarzania wierzchołków
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;
    pq.push({startVertex, key[startVertex]});

    while (!pq.empty()) {
        int u = pq.top().first; // Pobierz wierzchołek o minimalnym kluczu
        pq.pop();

        inMST[u] = true; // Dodaj wierzchołek do MST

        const auto& matrix = graph->getMatrix(); // Pobierz macierz incydencji
        for (int e = 0; e < edges; ++e) {
            int v = -1;
            int weight = 0;

            // Znajdź krawędź wychodzącą z u
            if (matrix[u][e] > 0) {
                for (int j = 0; j < vertices; ++j) {
                    if (j != u && matrix[j][e] < 0) {
                        v = j;
                        weight = matrix[u][e];
                        break;
                    }
                }
            }

            // Aktualizacja klucza i rodzica, jeśli znaleziono mniejszą wagę krawędzi
            if (v != -1 && !inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({v, key[v]});
            }
        }
    }

    // Wydrukuj MST
    std::cout << "Minimum Spanning Tree (Prim's Algorithm):" << std::endl;
    for (int i = 0; i < vertices; ++i) {
        if (parent[i] != -1) {
            std::cout << parent[i] << " - " << i << " : " << key[i] << std::endl;
        }
    }
}
