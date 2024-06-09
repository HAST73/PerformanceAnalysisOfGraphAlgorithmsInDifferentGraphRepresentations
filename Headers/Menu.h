#ifndef PROJECT_AIZO_2_MENU_H
#define PROJECT_AIZO_2_MENU_H

#include "IncidentMatrix.h"
#include "AdjacencyList.h"
#include "PrimIncidenceMatrix.h"
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

    void displayPostMSTMenu();
    void handlePostMSTMenu(int startVertex, int endVertex);

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
