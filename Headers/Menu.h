#ifndef PROJECT_AIZO_2_MENU_H
#define PROJECT_AIZO_2_MENU_H

#include <vector>
#include <string>
#include "../Headers/IncidentMatrix.h"
#include "../Headers/AdjacencyList.h"

class Menu {
private:
    IncidentMatrix* incidentMatrix;
    AdjacencyList* adjacencyList;
    std::vector<std::vector<int>> globalIntData;

public:
    Menu() : incidentMatrix(nullptr), adjacencyList(nullptr) {}
    ~Menu() {
        delete incidentMatrix;
        delete adjacencyList;
    }

    void displayMainMenu();
    void handleMainMenu();
    void displayFileMenu();
    void handleFileMenu();
    void displayMSTMenu();
    void handleMSTMenu();
    void displayFileContent();
    void generateRandomGraph();
    void processSelectFromLoadedFile();
    void displayIncidenceMatrix(bool directed);
    void displayAdjacencyList(bool directed);
    void runPrimAlgorithm();
    void runKruskalAlgorithm();
    void displayGraphTypeMenu();
    void handleGraphTypeMenu();
    void displayAlgorithmMenu();
    void handleAlgorithmMenu(bool isDirected);

    IncidentMatrix* getIncidenceMatrix() { return incidentMatrix; }
    AdjacencyList* getAdjacencyList() { return adjacencyList; }
};

#endif //PROJECT_AIZO_2_MENU_H