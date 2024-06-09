#ifndef PROJECT_AIZO_2_MENU_H
#define PROJECT_AIZO_2_MENU_H

#include "../Headers/IncidentMatrix.h"
#include "../Headers/AdjacencyList.h"
#include "../Headers/PrimIncidenceMatrix.h"
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

    void displayAlgorithmMenu();
    void handleAlgorithmMenu(bool isDirected);

    void displayMSTMenu();
    void handleMSTMenu();

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

#endif // PROJECT_AIZO_2_MENU_H
