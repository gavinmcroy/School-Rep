//
// Created by Gavin Taylor Mcroy on 10/26/21.
//

#include "MipsInterpret.h"

#include <utility>

MipsInterpret::commandLine::commandLine(std::string instr, std::string r1, std::string r2, std::string r3) {
    this->instruction = std::move(instr);
    this->register1 = std::move(r1);
    this->register2 = std::move(r2);
    this->register3 = std::move(r3);
}

MipsInterpret::MipsInterpret(int argc, char **argv) {
    if (argc < MAX_ARGS) {
        std::cerr << "Not enough command line arguments. Closing" << std::endl;
        exit(1);
    }

    inputFile = argv[1];
    outputFile = argv[2];
}

/* Build hash table of possible keys */
void MipsInterpret::buildTable() {
    /* Valid instruction table
     * load word (lw) and store word (sw)
     * add, sub, AND, OR, and slt
     * the instructions branch equal (beq) and jump (j) */
    assemblerMap["lw"] = 1;
    assemblerMap["sw"] = 2;
    assemblerMap["add"] = 3;
    assemblerMap["sub"] = 4;
    assemblerMap["and"] = 5;
    assemblerMap["or"] = 6;
    assemblerMap["slt"] = 7;
    assemblerMap["beq"] = 8;
    assemblerMap["j"] = 9;
}

void MipsInterpret::readFile() {
    std::cout << "Reading file" << std::endl;
    bool errors = false;
    std::ifstream file(inputFile);
    if (!file) {
        std::cerr << inputFile << " failed to open. Closing " << std::endl;
        exit(1);
    }
    isValidRegister("123");
    //add $1, $2, $3
    std::string instruction, arg1, arg2, arg3;
    int line = 1;

    while (file >> instruction >> arg1 >> arg2 >> arg3) {
        /* Command is invalid */
        if (assemblerMap.find(instruction) == assemblerMap.end()) {
            std::cerr << "Error. Unsupported instruction on line " << line << std::endl;
            errors = true;
        }
        /* Ensures third argument is indeed a register */
        if (arg1[0] == '$') {
            /* Is the register within bounds */
            if (!isValidRegister(arg1)) {
                std::cerr << "Error register value is out of range " << line << std::endl;
                errors = true;
            }
        }
        if (arg2[0] == '$') {
            if (!isValidRegister(arg2)) {
                std::cerr << "Error register value is out of range " << line << std::endl;
                errors = true;
            }
        }
        if (arg3[0] == '$') {
            if (!isValidRegister(arg3)) {
                std::cerr << "Error register value is out of range " << line << std::endl;
                errors = true;
            }
        }
        commands.emplace_back(instruction, arg1, arg2, arg3);
        line++;
    }
    file.close();
    if (errors) {
        std::cerr << "Program cannot proceed due to uncorrectable errors. Closing " << std::endl;
        exit(1);
    }

}

void MipsInterpret::compile() {
    /* Essentially we are converting instructions into binary digits */
    char x1,x2,x3,x4;
}

void MipsInterpret::outFile() {
    std::cout << "Writing file" << std::endl;
    std::ofstream myFile;
    myFile.open(outputFile, std::ios::binary);
    if (!myFile) {
        std::cerr << outputFile << " failed to open. Closing " << std::endl;
        exit(1);
    }
    std::string test = "add $1, $2, $3";

    int list[6] = {1, 2, 3, 4, 5, 6};
    myFile.write((char *) list, sizeof(int) * 6);

    if (!myFile.good()) {
        std::cerr << "Error occurred at writing time!" << std::endl;
        exit(1);
    }
    myFile.close();
}

bool MipsInterpret::isValidRegister(const std::string &reg) const {
    std::string local;
    /* Is it a double digit number? 2 since $10 is 3 characters */
    if (reg.length() > 2) {
        local = reg.substr(1, 2);
    } else {
        local = reg[1];
    }
    if (stoi(local) > MAX_REGISTERS) {
        return false;
    }
    return true;
}
