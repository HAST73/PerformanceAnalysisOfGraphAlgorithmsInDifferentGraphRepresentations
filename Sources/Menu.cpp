#include "../Headers/Menu.h"
#include "../Headers/ReadFile.h"
#include "../Headers/GenerateRandomGraphFile.h"
#include "../Headers/AdjacencyLists.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::vector<std::vector<int>> globalIntData;

void Menu::displayMainMenu() {
    std::cout << std::endl;
    std::cout << "=== MENU ===" << std::endl;
    std::cout << "1. Load file" << std::endl;
    std::cout << "2. Generate random graph file" << std::endl; // ctrl + alt + y
    std::cout << "0. Exit" << std::endl;
    std::cout << "Select an option: ";
}

void Menu::handleMainMenu() {
    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                processSelectFromLoadedFile();
                if (!globalIntData.empty()) {
                    handleFileMenu();
                }
                break;
            case 2:
                generateRandomGraph();
                break;
            case 0:
                std::cout << "Exiting program" << std::endl;
                break;
            default:
                std::cout << "Invalid option, try again" << std::endl;
        }
    } while (choice != 0);
}

void Menu::displayFileMenu() {
    std::cout << std::endl;
    std::cout << "=== FILE MENU ===" << std::endl;
    std::cout << "1. Display file content" << std::endl;
    std::cout << "2. Display incidence matrix (directed)" << std::endl;
    std::cout << "3. Display incidence matrix (undirected)" << std::endl;
    std::cout << "4. Display adjacency list (directed)" << std::endl;
    std::cout << "5. Display adjacency list (undirected)" << std::endl;
    std::cout << "6. MST Algorithms" << std::endl;
    std::cout << "7. Shortest path algorithms" << std::endl;
    std::cout << "8. Max flow algorithms" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;
    std::cout << "Select an option: ";
}

void Menu::handleFileMenu() {
    int choice;
    do {
        displayFileMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayFileContent();
                break;
            case 2:
                displayIncidenceMatrix(true); // Directed incident matrix
                break;
            case 3:
                displayIncidenceMatrix(false); // Undirected incident matrix
                break;
            case 4:
                displayAdjacencyList(true); // Directed adjacency list
                break;
            case 5:
                displayAdjacencyList(false); // Undirected adjacency list
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid option, try again." << std::endl;
        }
    } while (choice != 0);
}

void Menu::displayFileContent() {
    std::cout << "File content:" << std::endl;
    for (const auto& line : globalIntData) {
        for (const auto& num : line) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

void Menu::generateRandomGraph() {
    int vertices;
    double density;
    std::string filename;
    std::cout << "Enter the number of vertices: ";
    std::cin >> vertices;
    std::cout << "Enter the density of the graph in percentage: ";
    std::cin >> density;
    std::cout << "Enter the filename to save the graph with the extension .txt: ";
    std::cin >> filename;

    GenerateRandomGraphFile generator;
    generator.generateGraphFile("../Sources/" + filename, vertices, density);

    std::cout << "Random graph file generated successfully." << std::endl;
}

void Menu::processSelectFromLoadedFile() {
    const std::string basePath = "../Sources/";
    std::string filename;
    std::cout << "Enter the name of the text file with the extension .txt: ";
    std::cin >> filename;
    filename = basePath + filename;

    try {
        globalIntData = ReadFile::readData(filename, true);  // Always read the entire file
        if (globalIntData.empty()) {
            throw std::runtime_error("File is empty or could not be read.");
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Menu::displayIncidenceMatrix(bool directed) {
    if (!globalIntData.empty()) {
        int vertices = globalIntData[0][1];
        int edges = globalIntData[0][0];

        IncidentMatrix incidentMatrix(vertices, edges, directed);

        // Pętla zaczyna się od 1, ponieważ pierwszy wiersz został użyty do przechowywania liczby wierzchołków i krawędzi
        for (int i = 1; i < globalIntData.size(); ++i) {
            int v1 = globalIntData[i][0];
            int v2 = globalIntData[i][1];
            int edgeIndex = i - 1; // Odejmujemy 1, ponieważ pierwszy wiersz nie zawiera informacji o krawędziach
            incidentMatrix.addEdge(v1, v2, edgeIndex);
        }

        std::cout << (directed ? "Directed" : "Undirected") << " Incident Matrix:" << std::endl;
        incidentMatrix.printMatrix();
    } else {
        std::cout << "No graph data available. Load or generate a graph first." << std::endl;
    }
}

void Menu::displayAdjacencyList(bool directed) {
    if (!globalIntData.empty()) {
        int vertices = globalIntData[0][1];

        AdjacencyList adjacencyList(vertices);

        for (int i = 1; i < globalIntData.size(); ++i) {
            int v1 = globalIntData[i][0];
            int v2 = globalIntData[i][1];
            int weight = globalIntData[i][2];
            adjacencyList.addEdge(v1, v2, weight, directed);
        }

        std::cout << (directed ? "Directed" : "Undirected") << " Adjacency List:" << std::endl;
        adjacencyList.printList();
    } else {
        std::cout << "No graph data available. Load or generate a graph first." << std::endl;
    }
}