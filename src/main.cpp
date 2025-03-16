#include <iostream>
#include "controllers/StudentController.hpp"
#include "controllers/CollegeController.hpp"
#include "controllers/ProgramController.hpp"
#include "models/Program.hpp"
#include "models/Student.hpp"
#include "models/College.hpp"

int main() {
    // Use a test CSV file for this example
    ProgramController programController("data/program.csv");
    
    // create program 
    Program newProgram("Bachelors of Science in Computer Science", "BSCS", "CCS");

    programController.addProgram(newProgram);

    
    return 0;
}
