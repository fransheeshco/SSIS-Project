#include <iostream>
#include "controllers/StudentController.hpp"
#include "controllers/CollegeController.hpp"
#include "models/Student.hpp"
#include "models/College.hpp"

int main() {
    // Use a test CSV file for this example
    CollegeController collegeController("data/college.csv");
    
    // update college 
    College updatedCollege("SCS", "School of Computer Studies");

    collegeController.UpdateCollegeByCollegeCode("CCS", updatedCollege); 

    return 0;
}
