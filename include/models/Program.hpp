#pragma once

#include <string>

class Program
{
private:
    std::string program;
    std::string programcode;
    std::string collegecode;

public:
    // constructor
    Program(const std::string& program, const std::string& programcode, const std::string& collegecode) : program(program), programcode(programcode), collegecode(collegecode) {};

    std::string getProgram() const { return program; }

    std::string getProgramCode() const { return programcode; }

    std::string getCollegeCode() const { return collegecode; }

    void setProgram(const std::string &newprogram) {
        program = newprogram;
    }

    void setProgramCode(const std::string &newprogramcode) {
        programcode = newprogramcode;
    }

    void setCollegeCode(const std::string &newcollegecode) {
        collegecode = newcollegecode;
    }
};