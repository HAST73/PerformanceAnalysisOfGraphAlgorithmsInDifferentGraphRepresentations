#ifndef PROJECT_AIZO_2_MENU_H
#define PROJECT_AIZO_2_MENU_H

#include <vector>
#include <string>
#include "../Headers/IncidentMatrix.h"
#include "../Headers/AdjacencyList.h"

class Menu {
private:
    IncidentMatrix* directedIncidentMatrix;
    IncidentMatrix* undirectedIncidentMatrix;
    AdjacencyList* directedAdjacencyList;
    AdjacencyList* undirectedAdjacencyList;
    std::vector<std::vector<int>> globalIntData;

public:
    Menu() : directedIncidentMatrix(nullptr), undirectedIncidentMatrix(nullptr), directedAdjacencyList(nullptr), undirectedAdjacencyList(nullptr) {}
    ~Menu() {
        delete directedIncidentMatrix;
        delete undirectedIncidentMatrix;
        delete directedAdjacencyList;
        delete undirectedAdjacencyList;
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

    IncidentMatrix* getDirectedIncidentMatrix() { return directedIncidentMatrix; }
    IncidentMatrix* getUndirectedIncidentMatrix() { return undirectedIncidentMatrix; }
    AdjacencyList* getDirectedAdjacencyList() { return directedAdjacencyList; }
    AdjacencyList* getUndirectedAdjacencyList() { return undirectedAdjacencyList; }
};

#endif //PROJECT_AIZO_2_MENU_H