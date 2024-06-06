#include "../Headers/Menu.h"
#include "../Headers/ReadFile.h"
#include "../Headers/GenerateRandomGraphFile.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Menu::displayMainMenu() {
    std::cout << std::endl;
    std::cout << "=== MENU ===" << std::endl;
    std::cout << "1. Load file" << std::endl;
    std::cout << "2. Generate random graph file" << std::endl; // ctrl + alt + y
    std::cout << "3. Display graph" << std::endl;
    std::cout << "4. MST Algorithms" << std::endl;
    std::cout << "5. Shortest path algorithms" << std::endl;
    std::cout << "6. Max flow algorithms" << std::endl;
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
                    displayFileMenu();
                    handleFileMenu();
                }
                break;
            case 2:
                generateRandomGraph();
                break;
            case 3:
                displayGraph();
                break;
            case 4:
                displayGraphMenu();
                handleGraphMenu();
                break;
            case 5:
                displayGraphMenu();
                handleGraphMenu();
                break;
            case 6:
                displayGraphMenu();
                handleGraphMenu();
                break;
            case 0:
                std::cout << "Exiting program" << std::endl;
                break;
            default:
                std::cout << "Invalid option, try again" << std::endl;
        }
    } while (choice != 0);
}

void Menu::displayGraphMenu() {
    std::cout << "=== MENU GRAFU ===" << std::endl;
    std::cout << "1. Algorytm macierzowy" << std::endl;
    std::cout << "2. Algorytm listowy" << std::endl;
    std::cout << "0. Powrot" << std::endl;
    std::cout << "Select an option: ";
}

void Menu::displayFileMenu() {
    std::cout << std::endl;
    std::cout << "=== FILE MENU ===" << std::endl;
    std::cout << "1. Display file content" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;
    std::cout << "Select an option: ";
}

void Menu::handleFileMenu() {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            displayFileContent();
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid option, try again." << std::endl;
    }
}

void Menu::handleGraphMenu() {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
        case 2:
            executeAlgorithms();
            break;
        case 0:
            break;
        default:
            std::cout << "Niepoprawna opcja, sprobuj ponownie." << std::endl;
    }
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
    std::cout << "Enter the filename to save the graph: ";
    std::cin >> filename;

    GenerateRandomGraphFile generator;
    generator.generateGraphFile("../Sources/" + filename, vertices, density);

    std::cout << "Random graph file generated successfully." << std::endl;
}

void Menu::displayGraph() {
    std::cout << "Graf w reprezentacji macierzowej:" << std::endl;
    std::cout << "Graf w reprezentacji listowej:" << std::endl;
}

void Menu::executeAlgorithms() {
    if (globalIntData.empty()) {
        std::cout << "Graf nie zostal wczytany ani wygenerowany." << std::endl;
        return;
    }

    // Dummy implementation for executing algorithms
    std::cout << "Executing algorithms on the graph..." << std::endl;
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

std::vector<std::vector<int>> globalIntData;