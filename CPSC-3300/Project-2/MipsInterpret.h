//
// Created by Gavin Taylor Mcroy on 10/26/21.
//

#ifndef PROJECT_2_MIPSINTERPRET_H
#define PROJECT_2_MIPSINTERPRET_H

#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

class MipsInterpret {
private:
    std::string inputFile;
    std::string outputFile;
    const int MAX_ARGS = 3;
    const int MAX_REGISTERS = 32;
    std::unordered_map<std::string, int> assemblerMap;

    typedef struct commandLine {
        commandLine(std::string instr, std::string r1, std::string r2, std::string r3);

        std::string instruction;
        std::string register1;
        std::string register2;
        std::string register3;
    } CommandLine;

    std::vector<CommandLine> commands;

    [[nodiscard]] bool isValidRegister(const std::string &reg1, const std::string &reg2, const std::string &reg3) const;

public:
    MipsInterpret(int argc, char *argv[]);

    void buildTable();

    void readFile();

    void compile();

    void outFile();
};


#endif //PROJECT_2_MIPSINTERPRET_H
