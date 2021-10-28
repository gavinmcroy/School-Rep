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

    /* R type */
    assemblerMap["add"] = 32;
    assemblerMap["and"] = 36;
    assemblerMap["or"] = 37;
    assemblerMap["sub"] = 34;
    assemblerMap["slt"] = 42;

    /* I type */
    assemblerMap["lw"] = 34;
    assemblerMap["sw"] = 43;
    assemblerMap["beq"] = 4;

    /* J type */
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

    //add $1, $2, $3
    std::string instruction, arg1, arg2, arg3;
    std::cout<<arg1.empty()<<std::endl;
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
            if (!isValidRegister(arg1, 0, 0)) {
                std::cerr << "Error register value is out of range " << line << std::endl;
                errors = true;
            }
        }
        if (arg2[0] == '$') {
            if (!isValidRegister(arg2, 0, 0)) {
                std::cerr << "Error register value is out of range " << line << std::endl;
                errors = true;
            }
        }
        if (arg3[0] == '$') {
            if (!isValidRegister(arg3, 0, 0)) {
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
    std::vector<unsigned int> instructionsTranslated;

}

void MipsInterpret::outFile() {
    std::cout << "Writing file" << std::endl;
    std::ofstream myFile;
    myFile.open(outputFile, std::ios::binary);
    if (!myFile) {
        std::cerr << outputFile << " failed to open. Closing " << std::endl;
        exit(1);
    }


    //char data[4] = {(char)assemblerMap["add"], 1, 2, 3};
    unsigned int x = 0;


    if (!myFile.good()) {
        std::cerr << "Error occurred at writing time!" << std::endl;
        exit(1);
    }
    myFile.close();
}

bool MipsInterpret::isValidRegister(const std::string &reg1, const std::string &reg2, const std::string &reg3) const {
    std::string local;
    /* Is it a double digit number? 2 since $10 is 3 characters */
    if (reg1.length() > 2) {
        local = reg1.substr(1, 2);
    } else {
        local = reg1[1];
    }
    if (stoi(local) > MAX_REGISTERS) {
        return false;
    }
    return true;
}
