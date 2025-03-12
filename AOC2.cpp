#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdbool>
using namespace std;

bool diff_valid(std::vector<int> report, size_t index){
	int diff = abs(report[index] - report[index-1]);
	return diff >=1 && diff <= 3;
	
}
bool increasing_valid(std::vector<int> report){
	for(size_t i=1; i<report.size(); i++){
		if(report[i] <= report[i-1]){
			return false;
		}
		if (!diff_valid(report, i)){
			return false;
		}		
	}
	return true;
}

bool decreasing_valid(std::vector<int> report){
	for(size_t i=1; i<report.size(); i++){
		if(report[i] >= report[i-1]){
			return false;
		}
		if (!diff_valid(report, i)){
			return false;
		}		
	}
	return true;
}
bool safeReport(std::vector<int> report){
	increasing_valid(report) || decreasing_valid(report);
} 

int main() {
    // Öppna indatafilen
    std::ifstream file("input2.txt");
    std::string line;
    std::vector<int> report;
    int safeCount = 0;

    // Läs in data från filen
    while (getline(file, line)) {
        stringstream ss(line);
        int level;
        while (ss >> level){
        	report.push_back(level);
		}
		if (safeReport(report)){
			safeCount++;
		}
		report.clear();
	}
    // Stäng filen
    cout << safeCount;
    file.close();
}

