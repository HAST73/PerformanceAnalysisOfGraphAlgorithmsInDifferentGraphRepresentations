#include "../Headers/Menu.h"
#include "../Headers/ReadFile.h"
#include "../Headers/GenerateRandomGraphFile.h"
#include "../Headers/AdjacencyList.h"
#include "../Headers/IncidentMatrix.h"
#include "../Headers/PrimAdjacencyList.h"
#include "../Headers/PrimIncidenceMatrix.h"
#include "../Headers/KruskalAdjacencyList.h"
#include "../Headers/KruskalIncidenceMatrix.h"
#include "../Headers/BellmanFordAdjacencyList.h"
#include "../Headers/BellmanFordIncidenceMatrix.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include <random>

using namespace std;

vector<vector<int>> globalIntData;

Menu::~Menu() {
    delete directedIncidentMatrix;
    delete undirectedIncidentMatrix;
    delete directedWeightedIncidentMatrix;
    delete undirectedWeightedIncidentMatrix;
    delete directedAdjacencyList;
    delete undirectedAdjacencyList;
}

void Menu::displayMainMenu() {
    cout << endl;
    cout << "=== MENU ===" << endl;
    cout << "1. Load file" << endl;
    cout << "2. Generate random graph file" << endl;
    cout << "0. Exit" << endl;
    cout << "Select an option: ";
}

void Menu::handleMainMenu() {
    int choice;
    do {
        displayMainMenu();
        cin >> choice;

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
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid option, try again" << endl;
        }
    } while (choice != 0);
}

void Menu::displayFileMenu() {
    cout << endl;
    cout << "=== FILE MENU ===" << endl;
    cout << "1. Display file content" << endl;
    cout << "2. Display incidence matrix (directed)" << endl;
    cout << "3. Display incidence matrix (undirected)" << endl;
    cout << "4. Display weighted incidence matrix (directed)" << endl;
    cout << "5. Display weighted incidence matrix (undirected)" << endl;
    cout << "6. Display adjacency list (directed)" << endl;
    cout << "7. Display adjacency list (undirected)" << endl;
    cout << "8. Select graph type for algorithms" << endl;
    cout << "0. Back to main menu" << endl;
    cout << "Select an option: ";
}

void Menu::handleFileMenu() {
    int choice;
    do {
        displayFileMenu();
        cin >> choice;

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
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 0);
}

void Menu::displayGraphTypeMenu() {
    cout << endl;
    cout << "=== SELECT GRAPH TYPE ===" << endl;
    cout << "1. Directed graph (For Shortest Path and Maximum Flow Algorithms)" << endl;
    cout << "2. Undirected graph (For Minimum Spanning Tree Algorithms)" << endl;
    cout << "0. Back to file menu" << endl;
    cout << "Select an option: ";
}

void Menu::handleGraphTypeMenu() {
    int choice;
    do {
        displayGraphTypeMenu();
        cin >> choice;

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
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 0);
}

void Menu::displayAlgorithmMenu(bool isDirected) {
    cout << endl;
    cout << "=== ALGORITHMS ===" << endl;
    if (!isDirected) {
        cout << "1. Minimum Spanning Tree Algorithms (Prim and Kruskal)" << endl;
    }
    if (isDirected) {
        cout << "2. Shortest Path Algorithms (Dijkstra and Ford-Bellman)" << endl;
        cout << "3. Maximum Flow Algorithms (Ford-Fulkerson)" << endl;
    }
    cout << "0. Back to graph type menu" << endl;
    cout << "Select an option: ";
}

void Menu::handleAlgorithmMenu(bool isDirected) {
    int choice;
    do {
        displayAlgorithmMenu(isDirected);
        cin >> choice;

        if (!isDirected && choice == 1) {
            handleMSTMenu();
        } else if (isDirected && choice == 2) {
            handleSPMenu();
        } else if (isDirected && choice == 3) {
            // Call Maximum Flow Algorithm Menu Function
        } else if (choice == 0) {
            break;
        } else {
            cout << "Invalid option, try again." << endl;
        }
    } while (choice != 0);
}

void Menu::displaySPMenu() {
    cout << endl;
    cout << "=== SHORTEST PATH ALGORITHMS ===" << endl;
    cout << "1. Dijkstra's Algorithm (Adjacency List)" << endl;
    cout << "2. Dijkstra's Algorithm (Incidence Matrix)" << endl;
    cout << "3. Ford-Bellman's Algorithm (Adjacency List)" << endl;
    cout << "4. Ford-Bellman's Algorithm (Incidence Matrix)" << endl;
    cout << "0. Back to algorithm menu" << endl;
    cout << "Select an option: ";
}

void Menu::handleSPMenu() {
    int choice;
    do {
        displaySPMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                if (directedAdjacencyList) {
                    int startVertex, endVertex;
                    cout << "Enter the start vertex: ";
                    cin >> startVertex;
                    cout << "Enter the end vertex: ";
                    cin >> endVertex;
                    DijkstraAdjacencyList dijkstra(*directedAdjacencyList);
                    dijkstra.findShortestPath(startVertex, endVertex);
                    handlePostSPMenuListDijkstra(startVertex, endVertex);
                } else {
                    cout << "No directed adjacency list available." << endl;
                }
                break;
            case 2:
                if (directedWeightedIncidentMatrix) {
                    int startVertex, endVertex;
                    cout << "Enter the start vertex: ";
                    cin >> startVertex;
                    cout << "Enter the end vertex: ";
                    cin >> endVertex;
                    DijkstraIncidenceMatrix dijkstra(*directedWeightedIncidentMatrix);
                    dijkstra.findShortestPath(startVertex, endVertex);
                    handlePostSPMenuMatrixDijkstra(startVertex, endVertex);
                } else {
                    cout << "No directed weighted incidence matrix available." << endl;
                }
                break;
            case 3:
                if (directedAdjacencyList) {
                    int startVertex, endVertex;
                    cout << "Enter the start vertex: ";
                    cin >> startVertex;
                    cout << "Enter the end vertex: ";
                    cin >> endVertex;
                    BellmanFordAdjacencyList bellmanford(*directedAdjacencyList);
                    if (bellmanford.findShortestPath(startVertex, endVertex)) {
                        handlePostSPMenuListBellmanFord(startVertex, endVertex);
                    } else {
                        cout << "Negative weight cycle detected!" << endl;
                    }
                } else {
                    cout << "No directed adjacency list available." << endl;
                }
                break;
            case 4:
                if (directedWeightedIncidentMatrix) {
                    int startVertex, endVertex;
                    cout << "Enter the start vertex: ";
                    cin >> startVertex;
                    cout << "Enter the end vertex: ";
                    cin >> endVertex;
                    BellmanFordIncidenceMatrix bellmanford(*directedWeightedIncidentMatrix);
                    if (bellmanford.findShortestPath(startVertex, endVertex)) {
                        handlePostSPMenuMatrixBellmanFord(startVertex, endVertex);
                    } else {
                        cout << "Negative weight cycle detected!" << endl;
                    }
                } else {
                    cout << "No directed weighted incidence matrix available." << endl;
                }
                break;
            case 0:
                cout << "Returning to main menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void Menu::handlePostSPMenuListBellmanFord(int startVertex, int endVertex) {
    int choice;
    do {
        displayPostSPMenuListBellmanFord();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Shortest path from vertex " << startVertex << " to vertex " << endVertex << ":" << endl;
                if (directedAdjacencyList) {
                    BellmanFordAdjacencyList bellmanford(*directedAdjacencyList);
                    bellmanford.findShortestPath(startVertex, endVertex);
                    directedAdjacencyList->printList();
                } else {
                    cout << "Directed Adjacency List not loaded!" << endl;
                }
                break;
            case 0:
                cout << "Returning to shortest path menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void Menu::handlePostSPMenuMatrixBellmanFord(int startVertex, int endVertex) {
    int choice;
    do {
        displayPostSPMenuMatrixBellmanFord();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Shortest path from vertex " << startVertex << " to vertex " << endVertex << ":" << endl;
                if (directedWeightedIncidentMatrix) {
                    BellmanFordIncidenceMatrix bellmanford(*directedWeightedIncidentMatrix);
                    bellmanford.findShortestPath(startVertex, endVertex);
                    directedWeightedIncidentMatrix->printMatrix();
                } else {
                    cout << "Directed Incident Matrix not loaded!" << endl;
                }
                break;
            case 0:
                cout << "Returning to shortest path menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

void Menu::displayPostSPMenuListBellmanFord() {
    cout << endl;
    cout << "=== POST SHORTEST PATH MENU (ADJACENCY LIST) ===" << endl;
    cout << "1. Display shortest path result" << endl;
    cout << "0. Back to algorithm menu" << endl;
    cout << "Select an option: ";
}

void Menu::displayPostSPMenuMatrixBellmanFord() {
    cout << endl;
    cout << "=== POST SHORTEST PATH MENU (INCIDENCE MATRIX) ===" << endl;
    cout << "1. Display shortest path result" << endl;
    cout << "0. Back to algorithm menu" << endl;
    cout << "Select an option: ";
}

void Menu::handlePostSPMenuListDijkstra(int startVertex, int endVertex) {
    int choice;
    do {
        displayPostSPMenuListDijkstra();
        cin >> choice;

        switch (choice) {
            case 1:
                if (directedAdjacencyList) {
                    DijkstraAdjacencyList dijkstra(*directedAdjacencyList);
                    dijkstra.findShortestPath(startVertex, endVertex);
                    directedAdjacencyList->printList();
                } else {
                    cout << "Directed Adjacency List not loaded!" << endl;
                }
                break;
            case 0:
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 0);
}

void Menu::handlePostSPMenuMatrixDijkstra(int startVertex, int endVertex) {
    int choice;
    do {
        displayPostSPMenuMatrixDijkstra();
        cin >> choice;

        switch (choice) {
            case 1:
                if (directedWeightedIncidentMatrix) {
                    DijkstraIncidenceMatrix dijkstra(*directedWeightedIncidentMatrix);
                    dijkstra.findShortestPath(startVertex, endVertex);
                    directedWeightedIncidentMatrix->printMatrix();
                } else {
                    cout << "Directed Incident Matrix not loaded!" << endl;
                }
                break;
            case 0:
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 0);
}

void Menu::displayPostSPMenuListDijkstra() {
    cout << endl;
    cout << "=== POST SHORTEST PATH MENU (ADJACENCY LIST) ===" << endl;
    cout << "1. Display shortest path result" << endl;
    cout << "0. Back to algorithm menu" << endl;
    cout << "Select an option: ";
}

void Menu::displayPostSPMenuMatrixDijkstra() {
    cout << endl;
    cout << "=== POST SHORTEST PATH MENU (INCIDENCE MATRIX) ===" << endl;
    cout << "1. Display shortest path result" << endl;
    cout << "0. Back to algorithm menu" << endl;
    cout << "Select an option: ";
}

void Menu::displayMSTMenu() {
    cout << endl;
    cout << "=== MINIMUM SPANNING TREE ALGORITHMS ===" << endl;
    cout << "1. Prim's Algorithm (Adjacency List)" << endl;
    cout << "2. Prim's Algorithm (Incidence Matrix)" << endl;
    cout << "3. Kruskal's Algorithm (Adjacency List)" << endl;
    cout << "4. Kruskal's Algorithm (Incidence Matrix)" << endl;
    cout << "0. Back to algorithm menu" << endl;
    cout << "Select an option: ";
}

void Menu::handleMSTMenu() {
    int choice;
    do {
        displayMSTMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                if (undirectedAdjacencyList) {
                    int startVertex, endVertex;
                    cout << "Enter the start vertex: ";
                    cin >> startVertex;
                    cout << "Enter the end vertex: ";
                    cin >> endVertex;
                    PrimAdjacencyList::run(undirectedAdjacencyList, startVertex, endVertex);
                    handlePostMSTMenuListPrim(startVertex, endVertex);
                } else {
                    cout << "No undirected adjacency list available." << endl;
                }
                break;
            case 2:
                if (undirectedWeightedIncidentMatrix) {
                    int startVertex, endVertex;
                    cout << "Enter the start vertex: ";
                    cin >> startVertex;
                    cout << "Enter the end vertex: ";
                    cin >> endVertex;
                    PrimIncidenceMatrix::run(undirectedWeightedIncidentMatrix, startVertex, endVertex);
                    handlePostMSTMenuMatrixPrim(startVertex, endVertex);
                } else {
                    cout << "No undirected weighted incidence matrix available." << endl;
                }
                break;
            case 3:
                if (undirectedAdjacencyList) {
                    int startVertex, endVertex;
                    cout << "Enter the start vertex: ";
                    cin >> startVertex;
                    cout << "Enter the end vertex: ";
                    cin >> endVertex;
                    KruskalAdjacencyList::run(undirectedAdjacencyList, startVertex, endVertex, false);
                    handlePostMSTMenuListKruskal(startVertex, endVertex);
                } else {
                    cout << "No undirected adjacency list available." << endl;
                }
                break;
            case 4:
                if (undirectedWeightedIncidentMatrix) {
                    int startVertex, endVertex;
                    cout << "Enter the start vertex: ";
                    cin >> startVertex;
                    cout << "Enter the end vertex: ";
                    cin >> endVertex;
                    KruskalIncidenceMatrix::run(undirectedWeightedIncidentMatrix, startVertex, endVertex);
                    handlePostMSTMenuMatrixKruskal(startVertex, endVertex);
                } else {
                    cout << "No undirected weighted incidence matrix available." << endl;
                }
                break;
            case 5:
                cout << "Returning to main menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
}

void Menu::displayPostMSTMenuMatrixPrim() {
    cout << endl;
    cout << "=== POST MST MENU ===" << endl;
    cout << "1. Display new weighted incidence matrix (undirected)" << endl;
    cout << "0. Back to main menu" << endl;
    cout << "Select an option: ";
}

void Menu::displayPostMSTMenuListPrim() {
    cout << endl;
    cout << "=== POST MST MENU ===" << endl;
    cout << "1. Display new adjacency list (undirected)" << endl;
    cout << "0. Back to main menu" << endl;
    cout << "Select an option: ";
}

void Menu::displayPostMSTMenuMatrixKruskal() {
    cout << endl;
    cout << "=== POST MST MENU ===" << endl;
    cout << "1. Display new weighted incidence matrix (undirected)" << endl;
    cout << "0. Back to main menu" << endl;
    cout << "Select an option: ";
}

void Menu::displayPostMSTMenuListKruskal() {
    cout << endl;
    cout << "=== POST MST MENU ===" << endl;
    cout << "1. Display new adjacency list (undirected)" << endl;
    cout << "0. Back to main menu" << endl;
    cout << "Select an option: ";
}

void Menu::handlePostMSTMenuMatrixKruskal(int startVertex, int endVertex) {
    int choice;
    do {
        displayPostMSTMenuMatrixKruskal();
        cin >> choice;

        switch (choice) {
            case 1:
                if (undirectedWeightedIncidentMatrix) {
                    cout << "New Undirected Weighted Incidence Matrix:" << endl;
                    undirectedWeightedIncidentMatrix->printMatrix(startVertex, endVertex);
                } else {
                    cout << "No new undirected weighted incidence matrix available." << endl;
                }
                break;
            case 0:
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 0);
}

void Menu::handlePostMSTMenuListKruskal(int startVertex, int endVertex) {
    int choice;
    do {
        displayPostMSTMenuListKruskal();
        cin >> choice;

        switch (choice) {
            case 1:
                if (undirectedAdjacencyList) {
                    cout << "New Undirected Adjacency List:" << endl;
                    undirectedAdjacencyList->printList();
                } else {
                    cout << "No new undirected weighted incidence matrix available." << endl;
                }
                break;
            case 0:
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 0);
}

void Menu::handlePostMSTMenuMatrixPrim(int startVertex, int endVertex) {
    int choice;
    do {
        displayPostMSTMenuMatrixPrim();
        cin >> choice;

        switch (choice) {
            case 1:
                if (undirectedWeightedIncidentMatrix) {
                    cout << "New Undirected Weighted Incidence Matrix:" << endl;
                    undirectedWeightedIncidentMatrix->printMatrix(startVertex, endVertex);
                } else {
                    cout << "No new undirected weighted incidence matrix available." << endl;
                }
                break;
            case 0:
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 0);
}

void Menu::handlePostMSTMenuListPrim(int startVertex, int endVertex) {
    int choice;
    do {
        displayPostMSTMenuListPrim();
        cin >> choice;

        switch (choice) {
            case 1:
                if (undirectedAdjacencyList) {
                    cout << "New Undirected Adjacency List:" << endl;
                    undirectedAdjacencyList->printList();
                } else {
                    cout << "No new undirected weighted incidence matrix available." << endl;
                }
                break;
            case 0:
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 0);
}

void Menu::displayFileContent() {
    cout << "=== FILE CONTENT ===" << endl;
    for (const auto& line : globalIntData) {
        for (const auto& value : line) {
            cout << value << " ";
        }
        cout << endl;
    }
}

void Menu::generateRandomGraph() {
    int vertices;
    double density;
    string filename;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the density of the graph in percentage: ";
    cin >> density;
    cout << "Enter the filename to save the graph with extension (e.g., graph.txt): ";
    cin >> filename;

    GenerateRandomGraphFile generator;
    generator.generateGraphFile("../Sources/" + filename, vertices, density);

    cout << "Random graph file generated successfully." << endl;
}

void Menu::processSelectFromLoadedFile() {
    const string basePath = "../Sources/";
    string filename;
    cout << "Enter the name of the text file with the extension .txt: ";
    cin >> filename;
    filename = basePath + filename;

    try {
        globalIntData = ReadFile::readData(filename, true);  // Always read the entire file
        if (globalIntData.empty()) {
            throw runtime_error("File is empty or could not be read.");
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
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

            cout << "Directed Incident Matrix:" << endl;
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

            cout << "Undirected Incident Matrix:" << endl;
            undirectedIncidentMatrix->printMatrix();
        }
    } else {
        cout << "No graph data available. Load or generate a graph first." << endl;
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

            cout << "Directed Adjacency List:" << endl;
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

            cout << "Undirected Adjacency List:" << endl;
            undirectedAdjacencyList->printList();
        }
    } else {
        cout << "No graph data available. Load or generate a graph first." << endl;
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

            cout << "Directed Weighted Incident Matrix:" << endl;
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

            cout << "Undirected Weighted Incident Matrix:" << endl;
            undirectedWeightedIncidentMatrix->printMatrix();
        }
    } else {
        cout << "No graph data available. Load or generate a graph first." << endl;
    }
}
