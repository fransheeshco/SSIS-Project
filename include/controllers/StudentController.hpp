#pragma once

#include "CSVManager.hpp"
#include "models/Student.hpp"
#include <vector>
#include <string>

class StudentController {
private:
    std::string studentFile = "data/students.csv";
    CSVManager csvManager;

public:
    // Constructor declaration only
    StudentController(const std::string& studentFilePath);

    void addStudent(const Student& student);
    std::vector<Student> getAllStudents() const;
    bool updateStudentById(const std::string& idnumber, const Student& updatedStudent);
    bool deleteStudent(const std::string &idnumber);
};
