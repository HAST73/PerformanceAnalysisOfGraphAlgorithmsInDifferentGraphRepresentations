#ifndef PROJECT_AIZO_2_INCIDENTMATRIX_H
#define PROJECT_AIZO_2_INCIDENTMATRIX_H

#include <iostream>
#include <iomanip>
#include <vector>

class IncidentMatrix {
private:
    int n; // liczba wierzchołków
    int m; // liczba krawędzi
    bool directed; // czy graf jest skierowany
    std::vector<std::vector<signed char>> incidenceMatrix; // macierz incydencji

public:
    // Konstruktor
    IncidentMatrix(int vertices, int edges, bool isDirected);

    // Dodawanie krawędzi do macierzy incydencji
    void addEdge(int v1, int v2, int edgeIndex);

    // Wyświetlanie macierzy incydencji
    void printMatrix();

    // Obliczanie stopnia wierzchołka
    int vertexDegree(int vertexIndex);

    // Znajdowanie sąsiadów wierzchołka
    std::vector<int> neighbors(int vertexIndex);

    // Sprawdzanie, czy wierzchołek jest izolowany
    bool isIsolated(int vertexIndex);
};

#endif //PROJECT_AIZO_2_INCIDENTMATRIX_H
