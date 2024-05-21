#ifndef PROJECT_AIZO_2_MENU_H
#define PROJECT_AIZO_2_MENU_H

#include <iostream>
#include <vector>
#include <string>

class Menu {
public:
    Menu();
    void displayMainMenu();
    void handleMainMenu();

private:
    void displayGraphMenu();
    void handleGraphMenu();
    void loadGraphFromFile();
    void generateRandomGraph();
    void displayGraph();
    void executeAlgorithms();

    void cleanUp();
};

#endif //PROJECT_AIZO_2_MENU_H
