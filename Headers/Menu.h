#ifndef PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_MENU_H
#define PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_MENU_H

#include "../Headers/IncidentMatrix.h"
#include "../Headers/AdjacencyList.h"
#include "../Headers/PrimIncidenceMatrix.h"
#include "../Headers/DijkstraAdjacencyList.h"
#include "../Headers/DijkstraIncidenceMatrix.h"
#include <vector>
#include <string>

class Menu {
public:
    ~Menu();
    void displayMainMenu();
    void handleMainMenu();

private:
    void displayFileMenu();
    void handleFileMenu();

    void displayGraphTypeMenu();
    void handleGraphTypeMenu();

    void displayAlgorithmMenu(bool isDirected);
    void handleAlgorithmMenu(bool isDirected);

    void displayMSTMenu();
    void handleMSTMenu();

    void displaySPMenu();
    void handleSPMenu();

    void handlePostSPMenuListDijkstra(int startVertex, int endVertex);
    void displayPostSPMenuListDijkstra();

    void handlePostSPMenuMatrixDijkstra(int startVertex, int endVertex);
    void displayPostSPMenuMatrixDijkstra();

    void handlePostSPMenuListBellmanFord(int startVertex, int endVertex);
    void displayPostSPMenuListBellmanFord();

    void handlePostSPMenuMatrixBellmanFord(int startVertex, int endVertex);
    void displayPostSPMenuMatrixBellmanFord();

    void displayPostMSTMenuMatrixPrim();
    void handlePostMSTMenuMatrixPrim(int startVertex, int endVertex);

    void displayPostMSTMenuListPrim();
    void handlePostMSTMenuListPrim(int startVertex, int endVertex);

    void displayPostMSTMenuMatrixKruskal();
    void handlePostMSTMenuMatrixKruskal(int startVertex, int endVertex);

    void displayPostMSTMenuListKruskal();
    void handlePostMSTMenuListKruskal(int startVertex, int endVertex);

    void displayFileContent();
    void generateRandomGraph();
    void processSelectFromLoadedFile();

    void displayIncidenceMatrix(bool directed);
    void displayWeightedIncidenceMatrix(bool directed);
    void displayAdjacencyList(bool directed);

    IncidentMatrix* directedIncidentMatrix = nullptr;
    IncidentMatrix* undirectedIncidentMatrix = nullptr;
    IncidentMatrix* directedWeightedIncidentMatrix = nullptr;
    IncidentMatrix* undirectedWeightedIncidentMatrix = nullptr;
    AdjacencyList* directedAdjacencyList = nullptr;
    AdjacencyList* undirectedAdjacencyList = nullptr;
};

#endif // PERFORMANCE_ANALYSIS_OF_GRAPH_ALGORITHMS_IN_DIFFERENT_GRAPH_REPRESENTATIONS_MENU_H
