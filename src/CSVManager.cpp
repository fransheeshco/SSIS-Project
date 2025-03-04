#include "CSVManager.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <stdexcept> 
#include <sstream> 
#include <iostream>

void CSVManager::write_csv(const std::string &filename, const std::vector<std::pair<std::string, std::vector<std::string> > > &dataset) {
    std::ofstream myFile(filename, std::ios::trunc);
    if (!myFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
        return;
    }

    // Always write headers
    for (size_t j = 0; j < dataset.size(); ++j) {
        myFile << dataset[j].first;
        if (j != dataset.size() - 1)
            myFile << ",";
    }
    myFile << "\n";

    // Write data rows
    for (size_t i = 0; i < dataset[0].second.size(); ++i) {
        for (size_t j = 0; j < dataset.size(); ++j) {
            myFile << dataset[j].second[i];
            if (j != dataset.size() - 1)
                myFile << ",";
        }
        myFile << "\n";
    }

    myFile.close();
}


std::vector<std::pair<std::string, std::vector<std::string> > > CSVManager::read_csv(const std::string &filename) const {
    std::ifstream file(filename);
    std::vector<std::pair<std::string, std::vector<std::string> > > dataset;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for reading.\n";
        return dataset;
    }

    std::string line;

    // Read the header row
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string columnName;
        while (std::getline(ss, columnName, ',')) {
            dataset.push_back({columnName, {}}); // Initialize each column with an empty vector
        }
    }

    // Read the data rows
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        size_t colIndex = 0;

        while (std::getline(ss, cell, ',')) {
            if (colIndex < dataset.size()) {
                dataset[colIndex].second.push_back(cell); // Store cell as a string
            }
            colIndex++;
        }
    }

    file.close();
    return dataset;
}
