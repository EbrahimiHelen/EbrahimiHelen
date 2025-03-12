#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdbool>
#include <limits>
#include <cstdlib>  // För std::abs
#include <cstring>  // För strtok och strcpy
using namespace std;

// Funktion som kontrollerar om en rapport är säker
bool isSafeReport(const std::vector<int>& levels) {
    if (levels.size() < 2) return true;  // En enda nivå är alltid säker

    bool increasing = (levels[1] > levels[0]);
    
    for (size_t i = 1; i < levels.size(); ++i) {
        int diff = std::abs(levels[i] - levels[i - 1]);
        
        // Om skillnaden inte är mellan 1 och 3 ? osäker rapport
        if (diff < 1 || diff > 3) return false;

        // Kolla om sekvensen byter trend (går från ökande till minskande)
        if ((levels[i] > levels[i - 1]) != increasing) return false;
    }
    return true;
}

int main() {
    std::ifstream inputFile("AOC2.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open AOC2.txt" << std::endl;
        return 1;
    }

    std::string line;
    int safeReports = 0;

    // Läs varje rad i filen
    while (std::getline(inputFile, line)) {
        std::vector<int> levels;
        char buffer[256];
        strcpy(buffer, line.c_str());  // Konvertera std::string till C-sträng

        // Dela upp raden i nummer (skilda med mellanslag)
        char* token = strtok(buffer, " ");
        while (token != nullptr) {
            levels.push_back(std::atoi(token));
            token = strtok(nullptr, " ");
        }

        // Kontrollera om rapporten är säker
        if (isSafeReport(levels)) {
            safeReports++;
        }
    }
    
    inputFile.close();
    std::cout << "Number of safe reports: " << safeReports << std::endl;
    return 0;
}
