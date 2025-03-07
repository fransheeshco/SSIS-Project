#include <iostream>
#include <sstream>
#include "models/College.hpp"
#include <string>
#include "controllers/CollegeController.hpp"

CollegeController::CollegeController(const std::string& collegeFilePath) : collegeFile(collegeFilePath) {
}

// adding a college 
void CollegeController::addCollege(const College& college) {
    auto data = csvManager.read_csv(collegeFile);

    std::vector<std::string> newCollege = {
        college.getCollegeCode(),
        college.getCollegeName()
    };

    for(size_t i = 0; i < data.size(); i++) {
        data[i].second.push_back(newCollege[i]);
    }

    csvManager.write_csv(collegeFile, data);
    std::cout << "College added successfully.\n";
}

bool CollegeController::UpdateCollegeByCollegeCode(const std::string &collegeCode, const College& updatedCollege) {
    auto data = csvManager.read_csv(collegeFile);
    bool updated = false; 

    for (size_t i = 0; i < data.size(); i++) {
        if (data[0].second[i] == collegeCode) {
            data[0].second[i] = updatedCollege.getCollegeName();
            data[2].second[i] = updatedCollege.getCollegeCode();
            updated = true;
            break;
        }
    }
    
    if (updated) {
        csvManager.write_csv(collegeFile, data);
        std::cout << "College updated successfully.\n";
    } else {
        std::cerr << "Error: CollegeCode not found.\n";
    }
    return updated;
}

bool CollegeController::deleteCollege(const std::string &collegeCode) {
    auto data = csvManager.read_csv(collegeFile);
    bool deleted = false;

    for (size_t i = 0; i < data.size(); ++i) {
        if (data[0].second[i] == collegeCode) {
            for (size_t j = 0; j < data.size(); ++j) {
                data[j].second.erase(data[j].second.begin() + i);
            }
            deleted = true;
            break;
        }
    }

    if (deleted) {
        csvManager.write_csv(collegeFile, data);
        std::cout << "Student deleted successfully.\n";
    } else {
        std::cerr << "Error: Student ID not found.\n"; 
    }

    return deleted;
}