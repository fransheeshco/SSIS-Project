#include "controllers/StudentController.hpp"
#include "models/Student.hpp"
#include <iostream>
#include <sstream>

// Constructor definition
StudentController::StudentController(const std::string& studentFilePath)
    : studentFile(studentFilePath) {
}

// adding student
void StudentController::addStudent(const Student& student) {
    auto data = csvManager.read_csv(studentFile);

    std::vector<std::string> newStudent = {
        student.getStudentId(),
        student.getLastName(),
        student.getFirstName(),
        student.getProgram(),
        student.getCollegeCode(),
        student.getYearLevel(),
        student.getGender()
    };

    for (size_t i = 0; i < data.size(); ++i) {
        data[i].second.push_back(newStudent[i]);
    }

    csvManager.write_csv(studentFile, data);
    std::cout << "Student added successfully.\n"; 
}

// retrieve all students
std::vector<Student> StudentController::getAllStudents() const {
    auto data = csvManager.read_csv(studentFile);
    std::vector<Student> students;

    // Assuming the CSV columns are: 
    // [0]: studentid, [1]: lastname, [2]: firstname, [3]: program,
    // [4]: collegecode, [5]: yearlevel, [6]: gender.
    // And each column's .second vector holds the field values for all rows.
    if (data.size() < 7) {
        std::cerr << "CSV data format error.\n";
        return students;
    }
    
    // Iterate through rows based on the number of records in the first column.
    size_t numRecords = data[0].second.size();
    for (size_t i = 0; i < numRecords; ++i) {
        std::string studentId   = data[0].second[i];
        std::string lastName    = data[1].second[i];
        std::string firstName   = data[2].second[i];
        std::string program     = data[3].second[i];
        std::string collegeCode = data[4].second[i];
        std::string yearLevel   = data[5].second[i];
        std::string gender      = data[6].second[i];
        
        // Construct a Student object with the extracted data.
        students.push_back(Student(studentId, lastName, firstName, program, collegeCode, yearLevel, gender));
    }
    return students;
}

// update student
bool StudentController::updateStudentById(const std::string& idnumber, const Student& updatedStudent) {
    auto data = csvManager.read_csv(studentFile);
    bool updated = false;

    // Assuming your CSV columns are in this order:
    // 0: studentid, 1: lastname, 2: firstname, 3: program,
    // 4: collegecode, 5: yearlevel, 6: gender.
    for (size_t i = 0; i < data[0].second.size(); ++i) {
        if (data[0].second[i] == idnumber) {
            data[0].second[i] = updatedStudent.getStudentId();
            data[1].second[i] = updatedStudent.getLastName();
            data[2].second[i] = updatedStudent.getFirstName();
            data[3].second[i] = updatedStudent.getProgram();
            data[4].second[i] = updatedStudent.getCollegeCode();
            data[5].second[i] = updatedStudent.getYearLevel();
            data[6].second[i] = updatedStudent.getGender();
            updated = true;
            break;
        }
    }

    if (updated) {
        csvManager.write_csv(studentFile, data);
        std::cout << "Student updated successfully.\n";
    } else {
        std::cerr << "Error: Student ID not found.\n";
    }
    return updated;
}

// delete student
bool StudentController::deleteStudent(const std::string &idnumber) {
    auto data = csvManager.read_csv(studentFile);
    bool deleted = false;

    for (size_t i = 0; i < data[0].second.size(); ++i) {
        if (data[0].second[i] == idnumber) {
            for (size_t j = 0; j < data.size(); ++j) {
                data[j].second.erase(data[j].second.begin() + i);
            }
            deleted = true;
            break;
        }
    }

    if (deleted) {
        csvManager.write_csv(studentFile, data);
        std::cout << "Student deleted successfully.\n";
    } else {
        std::cerr << "Error: Student ID not found.\n"; 
    }

    return deleted;
}
