#pragma once

#include <string>

class Student {
private:
    std::string studentid;
    std::string lastname;
    std::string firstname;
    std::string program;
    std::string collegecode;
    std::string yearlevel;
    std::string gender;

public:
    // Constructor to initialize the student object
    Student(const std::string& studentId,
            const std::string& lastName,
            const std::string& firstName,
            const std::string& program,
            const std::string& collegeCode,
            const std::string& yearLevel,
            const std::string& gender)
        : studentid(studentId),
          lastname(lastName),
          firstname(firstName),
          program(program),
          collegecode(collegeCode),
          yearlevel(yearLevel),
          gender(gender) {}

    // Getters
    std::string getStudentId() const { return studentid; }
    std::string getLastName() const { return lastname; }
    std::string getFirstName() const { return firstname; }
    std::string getProgram() const { return program; }
    std::string getCollegeCode() const { return collegecode; }
    std::string getYearLevel() const { return yearlevel; }
    std::string getGender() const { return gender; }

    // Setters
    void setFirstName(const std::string& newFirstName) { firstname = newFirstName; }
    void setLastName(const std::string& newLastName) { lastname = newLastName; }
    void setProgram(const std::string& newProgram) { program = newProgram; }
    void setCollegeCode(const std::string& newCollegeCode) { collegecode = newCollegeCode; }
    void setYearLevel(const std::string& newYearLevel) { yearlevel = newYearLevel; }
    void setGender(const std::string& newGender) { gender = newGender; }
};
