#ifndef PROJECT_AIZO_2_MENU_H
#define PROJECT_AIZO_2_MENU_H

#include "../Headers/IncidentMatrix.h"
#include "../Headers/AdjacencyList.h"

class Menu {
public:
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

    void displayFileContent();
    void generateRandomGraph();
    void processSelectFromLoadedFile();

    void displayIncidenceMatrix(bool directed);
    void displayAdjacencyList(bool directed);

    IncidentMatrix* directedIncidentMatrix = nullptr;
    IncidentMatrix* undirectedIncidentMatrix = nullptr;
    AdjacencyList* directedAdjacencyList = nullptr;
    AdjacencyList* undirectedAdjacencyList = nullptr;
};

#endif //PROJECT_AIZO_2_MENU_H