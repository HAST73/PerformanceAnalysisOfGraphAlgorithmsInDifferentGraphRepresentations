#include "../Headers/PrimAdjacencyList.h"
#include "../Headers/AdjacencyList.h"
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

void PrimAdjacencyList::run(AdjacencyList* graph, int startVertex) {
    // Pobranie liczby wierzchołków w grafie
    int vertices = graph->getVertices(); // chyba ilosc wierzcholkow

    // Inicjalizacja wektorów do śledzenia MST
    std::vector<int> key(vertices, INT_MAX); // wartosc wierzcholka
    std::vector<bool> inMST(vertices, false); // czy wierzcholek jest w MST
    std::vector<int> parent(vertices, -1); // rodzic kolejny dla wierzcholka

    // Ustawienie wagi startowego wierzchołka na 0
    key[startVertex] = 0;

    // Utworzenie kolejki priorytetowej do przechowywania krawędzi
    using PII = std::pair<int, int>;
    std::priority_queue<PII, std::vector<PII>, std::greater<PII>> pq;
    pq.push({0, startVertex});

    // Główna pętla algorytmu Prim
    while (!pq.empty()) {
        // Pobranie wierzchołka o najmniejszej wadze
        int u = pq.top().second;
        pq.pop();

        // Sprawdzenie, czy wierzchołek jest już w MST
        if (inMST[u]) continue;
        inMST[u] = true;

        // Iteracja przez sąsiednie wierzchołki
        for (const auto& [v, weight] : graph->getAdjList()[u]) {
            // Aktualizacja wagi i rodzica, jeśli znaleziono lepszą ścieżkę
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Wyświetlenie MST
    std::cout << "Minimum Spanning Tree (Prim's Algorithm):" << std::endl;
    for (int i = 0; i < vertices; ++i) {
        if (parent[i] != -1) {
            std::cout << parent[i] << " - " << i << std::endl;
        }
    }
}