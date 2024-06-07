#ifndef PROJECT_AIZO_2_MENU_H
#define PROJECT_AIZO_2_MENU_H

#include <vector>
#include <string>
#include "../Headers/IncidentMatrix.h"

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
    void displayFileContent();
    void generateRandomGraph();
    void processSelectFromLoadedFile();
    void displayIncidenceMatrix(bool directed); // Update the function declaration
    void displayAdjacencyList(bool directed);
};

// Global variable to hold data
extern std::vector<std::vector<int>> globalIntData;

#endif //PROJECT_AIZO_2_MENU_H
