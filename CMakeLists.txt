cmake_minimum_required(VERSION 3.23)
project(Project_AIZO_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_AIZO_2 Sources/main.cpp Sources/Menu.cpp Headers/Menu.h Sources/ReadFile.cpp Headers/ReadFile.h Sources/GenerateRandomGraphFile.cpp Headers/GenerateRandomGraphFile.h Sources/IncidentMatrix.cpp Headers/IncidentMatrix.h Sources/AdjacencyList.cpp Headers/AdjacencyList.h Sources/PrimAdjacencyList.cpp Headers/PrimAdjacencyList.h Sources/PrimIncidenceMatrix.cpp Headers/PrimIncidenceMatrix.h Sources/KruskalAdjacencyList.cpp Headers/KruskalAdjacencyList.h Sources/KruskalIncidenceMatrix.cpp Headers/KruskalIncidenceMatrix.h Sources/DisjointSets.cpp Headers/DisjointSets.h Sources/DijkstraAdjacencyList.cpp Headers/DijkstraAdjacencyList.h Sources/DijkstraIncidenceMatrix.cpp Headers/DijkstraIncidenceMatrix.h Sources/BellmanFordIncidenceMatrix.cpp Headers/BellmanFordIncidenceMatrix.h Sources/BellmanFordAdjacencyList.cpp Headers/BellmanFordAdjacencyList.h)
