#ifndef PROJECT_AIZO_2_MENU_H
#define PROJECT_AIZO_2_MENU_H

#include "../Headers/IncidentMatrix.h"
#include "../Headers/AdjacencyList.h"

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

    void displayFileContent();
    void generateRandomGraph();
    void processSelectFromLoadedFile();

    void displayIncidenceMatrix(bool directed);
    void displayWeightedIncidenceMatrix(bool directed); // New function
    void displayAdjacencyList(bool directed);

    IncidentMatrix* directedIncidentMatrix = nullptr;
    IncidentMatrix* undirectedIncidentMatrix = nullptr;
    IncidentMatrix* directedWeightedIncidentMatrix = nullptr; // New variable
    IncidentMatrix* undirectedWeightedIncidentMatrix = nullptr; // New variable
    AdjacencyList* directedAdjacencyList = nullptr;
    AdjacencyList* undirectedAdjacencyList = nullptr;
};

#endif //PROJECT_AIZO_2_MENU_H
