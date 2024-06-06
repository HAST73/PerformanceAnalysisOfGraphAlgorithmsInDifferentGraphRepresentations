#ifndef PROJECT_AIZO_2_MENU_H
#define PROJECT_AIZO_2_MENU_H

#include <vector>
#include <string>

class Menu {
public:
    void displayMainMenu();
    void handleMainMenu();
    void displayGraphMenu();
    void displayFileMenu();
    void handleFileMenu();
    void handleGraphMenu();
    void displayFileContent();
    void generateRandomGraph();
    void displayGraph();
    void executeAlgorithms();
    void processSelectFromLoadedFile();
};

// Global variable to hold data
extern std::vector<std::vector<int>> globalIntData;

#endif //PROJECT_AIZO_2_MENU_H
