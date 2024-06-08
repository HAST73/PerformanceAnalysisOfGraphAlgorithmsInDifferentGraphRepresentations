cmake_minimum_required(VERSION 3.23)
project(Project_AIZO_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_AIZO_2 Sources/main.cpp Sources/Menu.cpp Headers/Menu.h Sources/ReadFile.cpp Headers/ReadFile.h Sources/GenerateRandomGraphFile.cpp Headers/GenerateRandomGraphFile.h Sources/IncidentMatrix.cpp Headers/IncidentMatrix.h Sources/AdjacencyList.cpp Headers/AdjacencyList.h Sources/Prim.cpp Headers/Prim.h)
