#ifndef PROJECT_AIZO_2_MENU_H
#define PROJECT_AIZO_2_MENU_H

#include <vector>
#include <string>
#include "../Headers/IncidentMatrix.h"
#include "../Headers/AdjacencyLists.h"

class Menu {
private:
    IncidentMatrix* graph;

public:
    Menu() : graph(nullptr) {}
    ~Menu() { delete graph; }

    void displayMainMenu();
    void handleMainMenu();
    void displayFileMenu();
    void handleFileMenu();
    void displayMSTMenu();
    void handleMSTMenu();
    void displayFileContent();
    void generateRandomGraph();
    void processSelectFromLoadedFile();
    void displayIncidenceMatrix(bool directed); // Update the function declaration
    void displayAdjacencyList(bool directed);
    void runPrimAlgorithm();
    void runKruskalAlgorithm();
    void displayGraphTypeMenu();
    void handleGraphTypeMenu();
    void displayAlgorithmMenu();
    void handleAlgorithmMenu(bool isDirected);
};

#endif //PROJECT_AIZO_2_MENU_H
