#include "../Headers/Menu.h"

// Implementacja konstruktora klasy Menu
Menu::Menu() {
    // Inicjalizacja wskaźników na grafy jako null
}

void Menu::displayMainMenu() {
    std::cout << "=== MENU GŁOWNE ===" << std::endl;
    std::cout << "1. Wczytaj dane z pliku" << std::endl;
    std::cout << "2. Wygeneruj graf losowo" << std::endl;
    std::cout << "3. Wyswietl graf" << std::endl;
    std::cout << "4. Algorytmy MST" << std::endl;
    std::cout << "5. Algorytmy najkrotszej sciezki" << std::endl;
    std::cout << "6. Algorytmy maksymalnego przeplywu" << std::endl;
    std::cout << "0. Wyjscie" << std::endl;
}

void Menu::handleMainMenu() {
    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                loadGraphFromFile();
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
                cleanUp();
                std::cout << "Zamykanie programu." << std::endl;
                break;
            default:
                std::cout << "Niepoprawna opcja, sprobuj ponownie." << std::endl;
        }
    } while (choice != 0);
}

void Menu::displayGraphMenu() {
    std::cout << "=== MENU GRAFU ===" << std::endl;
    std::cout << "1. Algorytm macierzowy" << std::endl;
    std::cout << "2. Algorytm listowy" << std::endl;
    std::cout << "0. Powrot" << std::endl;
}

void Menu::handleGraphMenu() {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            executeAlgorithms();
            break;
        case 2:
            executeAlgorithms();
            break;
        case 0:
            break;
        default:
            std::cout << "Niepoprawna opcja, sprobuj ponownie." << std::endl;
    }
}

void Menu::loadGraphFromFile() {
    std::string filename;
    std::cout << "Podaj nazwę pliku: ";
    std::cin >> filename;
    // Implementacja wczytywania grafu z pliku
}

void Menu::generateRandomGraph() {
    int vertices;
    double density;
    std::cout << "Podaj liczbe wierzcholkow: ";
    std::cin >> vertices;
    std::cout << "Podaj gestosc grafu w procentach: ";
    std::cin >> density;
    // Implementacja generowania losowego grafu
}

void Menu::displayGraph() {
    std::cout << "Graf w reprezentacji macierzowej:" << std::endl;
    std::cout << "Graf w reprezentacji listowej:" << std::endl;
}

void Menu::executeAlgorithms() {
        std::cout << "Graf nie zostal wczytany ani wygenerowany." << std::endl;
        return;

    // Implementacja uruchamiania algorytmów na grafie
}

void Menu::cleanUp() {
    std::cout<<"czyszczenie"<<std::endl;
}
