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

    typedef struct commandLine {
        commandLine(std::string instr, std::string r1, std::string r2, std::string r3);

        std::string instruction;
        std::string rd;
        std::string rs;
        std::string rt;
    } CommandLine;


    std::string inputFile;
    std::string outputFile;
    const int MAX_ARGS = 3;
    const int MAX_REGISTERS = 32;
    std::unordered_map<std::string, int> rTypeInstruction;
    std::unordered_map<std::string, int> jTypeInstruction;
    std::unordered_map<std::string, int> iTypeInstruction;

    std::vector<CommandLine> commands;
    std::vector<unsigned int> instructionsTranslated;

    [[nodiscard]] bool errorChecking(const std::string &instruction, const std::string &arg1, const std::string &arg2,
                                     const std::string &arg3, int line) const;

    [[nodiscard]] bool isIndividualRegisterValid(const std::string &reg1) const;

    char getInstructionType(const std::string &instruction);

    int * decimalToBinary(int n, int &important);

    void toggleSpecificBit(int n, int &valueToChange);

    int convertRegisterToNumber(const std::string& reg);

    int * twosComplementConversion(int n, int&important);

public:
    MipsInterpret(int argc, char *argv[]);

    void buildTable();

    void readFile();

    void compile();

    void outFile();


};


#endif //PROJECT_2_MIPSINTERPRET_H
