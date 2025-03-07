#pragma once

#include "CSVManager.hpp"
#include "models/College.hpp"
#include <vector>
#include <string>

class CollegeController {
    private: 
        std::string collegeFile = "data/college.csv";
        CSVManager csvManager;
    
    public: 
        // College Controller Constructor
        CollegeController(const std::string& collegeFilePath);

        void addCollege(const College& college);
        bool UpdateCollegeByCollegeCode(const std::string &collegeCode, const College& updatedCollege);
        bool deleteCollege(const std::string &collegeCode);
};