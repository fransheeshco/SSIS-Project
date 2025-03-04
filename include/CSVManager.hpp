#pragma once

#include <vector>
#include <string>
#include <utility> 

class CSVManager {
public: 
    // Writes data to a CSV file
    void write_csv(const std::string &filename, const std::vector<std::pair<std::string, std::vector<std::string> > > &dataset);

    // Reads data from a CSV file and returns it
    std::vector<std::pair<std::string, std::vector<std::string> > > read_csv(const std::string &filename) const;
};
