#include "../Headers/Menu.h"
#include "../Headers/ReadFile.h"
#include "../Headers/GenerateRandomGraphFile.h"
#include "../Headers/AdjacencyList.h"
#include "../Headers/IncidentMatrix.h"
#include "../Headers/PrimAdjacencyList.h"
#include "../Headers/PrimIncidenceMatrix.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::vector<std::vector<int>> globalIntData;

Menu::~Menu() {
    delete directedIncidentMatrix;
    delete undirectedIncidentMatrix;
    delete directedWeightedIncidentMatrix;
    delete undirectedWeightedIncidentMatrix;
    delete directedAdjacencyList;
    delete undirectedAdjacencyList;
}

void Menu::displayMainMenu() {
    std::cout << std::endl;
    std::cout << "=== MENU ===" << std::endl;
    std::cout << "1. Load file" << std::endl;
    std::cout << "2. Generate random graph file" << std::endl;
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
    std::cout << "4. Display weighted incidence matrix (directed)" << std::endl;
    std::cout << "5. Display weighted incidence matrix (undirected)" << std::endl;
    std::cout << "6. Display adjacency list (directed)" << std::endl;
    std::cout << "7. Display adjacency list (undirected)" << std::endl;
    std::cout << "8. Select graph type for algorithms" << std::endl;
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
                displayIncidenceMatrix(true); // Directed incidence matrix
                break;
            case 3:
                displayIncidenceMatrix(false); // Undirected incidence matrix
                break;
            case 4:
                displayWeightedIncidenceMatrix(true); // Directed weighted incidence matrix
                break;
            case 5:
                displayWeightedIncidenceMatrix(false); // Undirected weighted incidence matrix
                break;
            case 6:
                displayAdjacencyList(true); // Directed adjacency list
                break;
            case 7:
                displayAdjacencyList(false); // Undirected adjacency list
                break;
            case 8:
                handleGraphTypeMenu();
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid option, try again." << std::endl;
        }
    } while (choice != 0);
}

void Menu::displayGraphTypeMenu() {
    std::cout << std::endl;
    std::cout << "=== SELECT GRAPH TYPE ===" << std::endl;
    std::cout << "1. Directed graph (For Shortest Path and Maximum Flow Algorithms)" << std::endl;
    std::cout << "2. Undirected graph (For Minimum Spanning Tree Algorithms)" << std::endl;
    std::cout << "0. Back to file menu" << std::endl;
    std::cout << "Select an option: ";
}

void Menu::handleGraphTypeMenu() {
    int choice;
    do {
        displayGraphTypeMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleAlgorithmMenu(true);
                break;
            case 2:
                handleAlgorithmMenu(false);
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid option, try again." << std::endl;
        }
    } while (choice != 0);
}

void Menu::displayAlgorithmMenu() {
    std::cout << std::endl;
    std::cout << "=== ALGORITHMS ===" << std::endl;
    std::cout << "1. Minimum Spanning Tree Algorithms" << std::endl;
    std::cout << "2. Shortest Path Algorithms" << std::endl;
    std::cout << "3. Maximum Flow Algorithms" << std::endl;
    std::cout << "0. Back to graph type menu" << std::endl;
    std::cout << "Select an option: ";
}

void Menu::handleAlgorithmMenu(bool isDirected) {
    int choice;
    do {
        displayAlgorithmMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleMSTMenu();
                break;
            case 2:
                // Call Shortest Path Algorithm Menu Function
                break;
            case 3:
                // Call Maximum Flow Algorithm Menu Function
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid option, try again." << std::endl;
        }
    } while (choice != 0);
}

void Menu::displayMSTMenu() {
    std::cout << std::endl;
    std::cout << "=== MINIMUM SPANNING TREE ALGORITHMS ===" << std::endl;
    std::cout << "1. Prim's Algorithm (Adjacency List)" << std::endl;
    std::cout << "2. Prim's Algorithm (Incidence Matrix)" << std::endl;
    std::cout << "0. Back to algorithm menu" << std::endl;
    std::cout << "Select an option: ";
}

void Menu::handleMSTMenu() {
    int choice;
    do {
        displayMSTMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (undirectedAdjacencyList) {
                    int startVertex, endVertex;
                    std::cout << "Enter the start vertex: ";
                    std::cin >> startVertex;
                    std::cout << "Enter the end vertex: ";
                    std::cin >> endVertex;
                    PrimAdjacencyList::run(undirectedAdjacencyList, startVertex, endVertex);
                    handlePostMSTMenuList(startVertex, endVertex);
                } else {
                    std::cout << "No undirected adjacency list available." << std::endl;
                }
                break;
            case 2:
                if (undirectedWeightedIncidentMatrix) {
                    int startVertex, endVertex;
                    std::cout << "Enter the start vertex: ";
                    std::cin >> startVertex;
                    std::cout << "Enter the end vertex: ";
                    std::cin >> endVertex;
                    PrimIncidenceMatrix::run(undirectedWeightedIncidentMatrix, startVertex, endVertex);
                    handlePostMSTMenuMatrix(startVertex, endVertex);
                } else {
                    std::cout << "No undirected weighted incidence matrix available." << std::endl;
                }
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid option, try again." << std::endl;
        }
    } while (choice != 0);
}

void Menu::displayPostMSTMenuMatrix() {
    std::cout << std::endl;
    std::cout << "=== POST MST MENU ===" << std::endl;
    std::cout << "1. Display new weighted incidence matrix (undirected)" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;
    std::cout << "Select an option: ";
}

void Menu::displayPostMSTMenuList() {
    std::cout << std::endl;
    std::cout << "=== POST MST MENU ===" << std::endl;
    std::cout << "1. Display new adjacency list (undirected)" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;
    std::cout << "Select an option: ";
}

void Menu::handlePostMSTMenuMatrix(int startVertex, int endVertex) {
    int choice;
    do {
        displayPostMSTMenuMatrix();
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (undirectedWeightedIncidentMatrix) {
                    std::cout << "New Undirected Weighted Incidence Matrix:" << std::endl;
                    undirectedWeightedIncidentMatrix->printMatrix(startVertex, endVertex);
                } else {
                    std::cout << "No new undirected weighted incidence matrix available." << std::endl;
                }
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid option, try again." << std::endl;
        }
    } while (choice != 0);
}

void Menu::handlePostMSTMenuList(int startVertex, int endVertex) {
    int choice;
    do {
        displayPostMSTMenuList();
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (undirectedAdjacencyList) {
                    std::cout << "New Undirected Adjacency List:" << std::endl;
                    undirectedAdjacencyList->printList();
                } else {
                    std::cout << "No new undirected weighted incidence matrix available." << std::endl;
                }
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid option, try again." << std::endl;
        }
    } while (choice != 0);
}

void Menu::displayFileContent() {
    std::cout << "=== FILE CONTENT ===" << std::endl;
    for (const auto& line : globalIntData) {
        for (const auto& value : line) {
            std::cout << value << " ";
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

        if (directed) {
            delete directedIncidentMatrix; // Free previously allocated memory
            directedIncidentMatrix = new IncidentMatrix(vertices, edges, directed);

            for (int i = 1; i < globalIntData.size(); ++i) {
                int v1 = globalIntData[i][0];
                int v2 = globalIntData[i][1];
                int edgeIndex = i - 1; // Subtract 1 because the first row does not contain edge information
                directedIncidentMatrix->addEdge(v1, v2, edgeIndex);
            }

            std::cout << "Directed Incident Matrix:" << std::endl;
            directedIncidentMatrix->printMatrix();
        } else {
            delete undirectedIncidentMatrix; // Free previously allocated memory
            undirectedIncidentMatrix = new IncidentMatrix(vertices, edges, directed);

            for (int i = 1; i < globalIntData.size(); ++i) {
                int v1 = globalIntData[i][0];
                int v2 = globalIntData[i][1];
                int edgeIndex = i - 1; // Subtract 1 because the first row does not contain edge information
                undirectedIncidentMatrix->addEdge(v1, v2, edgeIndex);
            }

            std::cout << "Undirected Incident Matrix:" << std::endl;
            undirectedIncidentMatrix->printMatrix();
        }
    } else {
        std::cout << "No graph data available. Load or generate a graph first." << std::endl;
    }
}

void Menu::displayAdjacencyList(bool directed) {
    if (!globalIntData.empty()) {
        int vertices = globalIntData[0][1];

        if (directed) {
            delete directedAdjacencyList; // Free previously allocated memory
            directedAdjacencyList = new AdjacencyList(vertices);

            for (int i = 1; i < globalIntData.size(); ++i) {
                int v1 = globalIntData[i][0];
                int v2 = globalIntData[i][1];
                int weight = globalIntData[i][2];
                directedAdjacencyList->addEdge(v1, v2, weight, directed);
            }

            std::cout << "Directed Adjacency List:" << std::endl;
            directedAdjacencyList->printList();
        } else {
            delete undirectedAdjacencyList; // Free previously allocated memory
            undirectedAdjacencyList = new AdjacencyList(vertices);

            for (int i = 1; i < globalIntData.size(); ++i) {
                int v1 = globalIntData[i][0];
                int v2 = globalIntData[i][1];
                int weight = globalIntData[i][2];
                undirectedAdjacencyList->addEdge(v1, v2, weight, directed);
            }

            std::cout << "Undirected Adjacency List:" << std::endl;
            undirectedAdjacencyList->printList();
        }
    } else {
        std::cout << "No graph data available. Load or generate a graph first." << std::endl;
    }
}

void Menu::displayWeightedIncidenceMatrix(bool directed) {
    if (!globalIntData.empty()) {
        int vertices = globalIntData[0][1];
        int edges = globalIntData[0][0];

        if (directed) {
            delete directedWeightedIncidentMatrix; // Free previously allocated memory
            directedWeightedIncidentMatrix = new IncidentMatrix(vertices, edges, directed);

            for (int i = 1; i < globalIntData.size(); ++i) {
                int v1 = globalIntData[i][0];
                int v2 = globalIntData[i][1];
                int weight = globalIntData[i][2];
                int edgeIndex = i - 1; // Subtract 1 because the first row does not contain edge information
                directedWeightedIncidentMatrix->addEdge(v1, v2, edgeIndex, weight);
            }

            std::cout << "Directed Weighted Incident Matrix:" << std::endl;
            directedWeightedIncidentMatrix->printMatrix();
        } else {
            delete undirectedWeightedIncidentMatrix; // Free previously allocated memory
            undirectedWeightedIncidentMatrix = new IncidentMatrix(vertices, edges, directed);

            for (int i = 1; i < globalIntData.size(); ++i) {
                int v1 = globalIntData[i][0];
                int v2 = globalIntData[i][1];
                int weight = globalIntData[i][2];
                int edgeIndex = i - 1; // Subtract 1 because the first row does not contain edge information
                undirectedWeightedIncidentMatrix->addEdge(v1, v2, edgeIndex, weight);
            }

            std::cout << "Undirected Weighted Incident Matrix:" << std::endl;
            undirectedWeightedIncidentMatrix->printMatrix();
        }
    } else {
        std::cout << "No graph data available. Load or generate a graph first." << std::endl;
    }
}