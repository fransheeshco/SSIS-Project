#pragma once

#include "CSVManager.hpp"
#include "models/Program.hpp"
#include <vector>
#include <string> 

class ProgramController {
    private: 
        std::string programFile = "data/program.csv";
        CSVManager csvManager;
    public: 
        ProgramController(const std::string& programFile);

        void addProgram(const Program& program);
        bool updateByProgramCode(const std::string &programcode, const Program& updatedProgram);
        bool deleteByProgramCode(const std::string &programcode);
};