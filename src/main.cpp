#include <iostream>
#include "controllers/StudentController.hpp"
#include "controllers/CollegeController.hpp"
#include "models/Student.hpp"
#include "models/College.hpp"

int main() {
    // Use a test CSV file for this example
    CollegeController collegeController("data/college.csv");
    
    // create some colleges 
    College college1("CCS", "College of Computer Studies");
    College college2("CCS", "College of Computer Studies");

    // Add students to the CSV file
    std::cout << "Adding students...\n";
    collegeController.addCollege(college1);
    collegeController.addCollege(college2);

    return 0;
}
