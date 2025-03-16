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
    
    // delete program 
    programController.deleteByProgramCode("BSCS");
    return 0;
}
