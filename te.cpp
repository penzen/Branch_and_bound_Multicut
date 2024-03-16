#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
std::vector<std::vector<int>> readGraphData(const string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<int>> graphData; 
    if (file.is_open()) {
        std::string line;

        // Get the total number of vertices (nodes)
        std::getline(file, line);  
        // Ignore this for now, unless needed for other processing

        // Read and store each line of numbers
        while (std::getline(file, line)) {
            std::vector<int> lineData; 
            std::istringstream iss(line);
            int number;

            while (iss >> number) {
                lineData.push_back(number);
            }

            graphData.push_back(lineData); 
        }

    } else {
        std::cout << "Error opening file." << std::endl;
    }

    return graphData;
}


int main() {
    
    // Accessing the data:

    // ... and so on 
}