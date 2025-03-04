#include <iostream>
#include "controllers/StudentController.hpp"
#include "models/Student.hpp"

int main() {
    // Use a test CSV file for this example
    StudentController controller("data/students.csv");

    // Create a couple of Student objects
    Student student1("S001", "Smith", "John", "Computer Science", "ENG", "2", "Male");
    Student student2("S002", "Doe", "Jane", "Information Technology", "BUS", "3", "Female");

    // Add students to the CSV file
    std::cout << "Adding students...\n";
    controller.addStudent(student1);
    controller.addStudent(student2);

    // Retrieve all students and display them
    std::cout << "\nCurrent students:\n";
    auto students = controller.getAllStudents();
    for (const auto& student : students) {
        std::cout << "ID: " << student.getStudentId() << ", Name: " 
                  << student.getFirstName() << " " << student.getLastName() << "\n";
    }

    // Update student S001
    std::cout << "\nUpdating student S001...\n";
    Student updatedStudent("S001", "Smith", "Johnny", "Computer Science", "ENG", "3", "Male");
    if (controller.updateStudentById("S001", updatedStudent)) {
        std::cout << "Student S001 updated successfully.\n";
    } else {
        std::cout << "Update failed: Student S001 not found.\n";
    }

    // Delete student S002
    std::cout << "\nDeleting student S002...\n";
    if (controller.deleteStudent("S002")) {
        std::cout << "Student S002 deleted successfully.\n";
    } else {
        std::cout << "Deletion failed: Student S002 not found.\n";
    }

    // Retrieve all students after modifications
    std::cout << "\nStudents after update and deletion:\n";
    students = controller.getAllStudents();
    for (const auto& student : students) {
        std::cout << "ID: " << student.getStudentId() << ", Name: " 
                  << student.getFirstName() << " " << student.getLastName() << "\n";
    }

    return 0;
}
