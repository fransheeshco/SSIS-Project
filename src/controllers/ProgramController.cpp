#include <iostream>
#include "models/Program.hpp"
#include "controllers/ProgramController.hpp"
#include <sstream>

ProgramController::ProgramController(const std::string& programFilePath) :  programFile(programFilePath) {};

void ProgramController::addProgram(const Program& program) {
    auto data = csvManager.read_csv(programFile);

    std::vector<std::string> newProgram = {
        program.getProgram(),
        program.getProgramCode(),
        program.getCollegeCode()
    }; 

    for (size_t i = 0; i < data[1].second.size(); i++) {
        if (data[1].second[i] == program.getProgramCode()) {
            std::cout << "Program already exists\n";
            return;
        }
    }

    data[0].second.push_back(program.getProgram());
    data[1].second.push_back(program.getProgramCode());
    data[2].second.push_back(program.getCollegeCode());

    csvManager.write_csv(programFile, data);
    std::cout << "Program added successfully.\n";
}

bool ProgramController::updateByProgramCode(const std::string &programcode, const Program& updatedProgram) {
    auto data = csvManager.read_csv(programFile);
    bool updated = false;

    for (size_t i = 0; i < data[0].second.size(); i++) {
        if(data[1].second[i] == updatedProgram.getProgramCode()) {
            std::cout << "Program already exists.\n";
        }
    }

    for (size_t i = 0; i < data.size(); i++) {
        if (data[1].second[i] == programcode) {
            data[0].second[i] = updatedProgram.getProgram();
            data[2].second[i] = updatedProgram.getProgramCode();
            updated = true;
            break;
        }
    }

    if(updated) {
        csvManager.write_csv(programFile, data);
        std::cout << "Program updated successfully.\n";
    } else {
        std::cerr << "Error: Program code not found.\n";
    }

    return updated;
}

bool ProgramController::deleteByProgramCode(const std::string &programcode) {
    auto data = csvManager.read_csv(programFile);
    bool deleted = false;

    for (size_t i = 0; i < data.size(); i++) {
        if (data[1].second[i] == programcode) {
            for (size_t j = 0; j < data.size(); j++) {
                data[j].second.erase(data[j].second.begin() + 1);
            }
            deleted = true;
            break;
        }
    }

    if(deleted) {
        csvManager.write_csv(programFile, data); 
        std::cout << "Program deleted successfully.\n";
    } else {
        std::cerr << "Error: Program code not found.\n";
    }

    return deleted;
}