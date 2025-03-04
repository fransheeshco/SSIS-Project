#pragma once

#include "CSVManager.hpp"
#include <vector>
#include <string>

class CollegeController {
    private: 
        std::string collegeFile = "data/college.csv";
        CSVManager csvManager;
    
    public: 
        void addCollege(const std::string& collegename, const std::string& collegecode);
        bool UpdateCollege(const std::string &collegname, const std::vector<std::string>& newDetails);
        bool deleteCollege(const std::string &collegename);
};