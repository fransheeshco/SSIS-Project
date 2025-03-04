#pragma once

#include <string>

class College {
private: 
    std::string collegeName;
    std::string collegeCode;

public:
    // Constructor declaration
    College(const std::string& collegeName, const std::string& collegeCode);

    // Getters (marked as const)
    std::string getCollegeName() const {
        return collegeName;
    }
    std::string getCollegeCode() const {
        return collegeCode;
    }

    // Setters
    void setCollegeName(const std::string& name) {
        collegeName = name;
    }
    void setCollegeCode(const std::string& code) {
        collegeCode = code;
    }
};
