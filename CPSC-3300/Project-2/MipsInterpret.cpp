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
    rTypeInstruction["add"] = 32;
    rTypeInstruction["and"] = 36;
    rTypeInstruction["or"] = 37;
    rTypeInstruction["sub"] = 34;
    rTypeInstruction["slt"] = 42;

    /* I type */
    iTypeInstruction["lw"] = 34;
    iTypeInstruction["sw"] = 43;
    iTypeInstruction["beq"] = 4;

    /* J type */
    jTypeInstruction["j"] = 9;
}

void MipsInterpret::readFile() {
    std::cout << "Reading file" << std::endl;
    bool errors = false;
    std::ifstream file(inputFile);
    if (!file) {
        std::cerr << inputFile << " failed to open. Closing " << std::endl;
        exit(1);
    }

    std::string instruction, arg1, arg2, arg3;

    int line = 1;
    while (file >> instruction) {
        char instructType = getInstructionType(instruction);
        /* r has $rd $rs $rt */
        if (instructType == 'r') {
            file >> arg1 >> arg2 >> arg3;
        } else if (instructType == 'i') {
            /* Special case since beq has $rs $rt and immediate*/
            if (instruction == "beq") {
                file >> arg1 >> arg2 >> arg3;
            } else {
                file >> arg1 >> arg2;
            }
        } /* j has just address */
        else if (instructType == 'j') {
            file >> arg1;
        } else {
            std::cout << "error" << std::endl;
        }

        if (errorChecking(instruction, arg1, arg2, arg3, line)) {
            std::cerr << "Program cannot continue. Closing " << std::endl;
            exit(1);
        }

        commands.emplace_back(instruction, arg1, arg2, arg3);
        line++;
    }
    file.close();
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

    unsigned int x = 0;


    if (!myFile.good()) {
        std::cerr << "Error occurred at writing time!" << std::endl;
        exit(1);
    }
    myFile.close();
}

bool MipsInterpret::errorChecking(const std::string &instruction, const std::string &arg1, const std::string &arg2,
                                  const std::string &arg3, int line) const {
    /* Ensures third argument is indeed a register */
    bool errors = false;
    if (rTypeInstruction.find(instruction) == rTypeInstruction.end() &&
        iTypeInstruction.find(instruction) == iTypeInstruction.end() &&
        jTypeInstruction.find(instruction) == jTypeInstruction.end()) {
        std::cerr << "Error. Unsupported instruction on line " << line << std::endl;
        errors = true;
    }
    if (arg1.empty()) {
        if (arg1[0] == '$') {
            /* Is the register within bounds */
            if (!isIndividualRegisterValid(arg1)) {
                std::cerr << "Error register value is out of range " << line << std::endl;
                errors = true;
            }
        }
    }
    if (!arg2.empty()) {
        if (arg2[0] == '$') {
            if (!isIndividualRegisterValid(arg2)) {
                std::cerr << "Error register value is out of range " << line << std::endl;
                errors = true;
            }
        }
    }
    if (!arg3.empty()) {
        if (arg3[0] == '$') {
            if (!isIndividualRegisterValid(arg3)) {
                std::cerr << "Error register value is out of range " << line << std::endl;
                errors = true;
            }
        }
    }
    if (errors) {
        return true;
    }
    return false;
}

bool MipsInterpret::isIndividualRegisterValid(const std::string &reg1) const {
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

char MipsInterpret::getInstructionType(const std::string &instruction) {
    if (rTypeInstruction.find(instruction) != rTypeInstruction.end()) {
        return 'r';
    } else if (iTypeInstruction.find(instruction) != iTypeInstruction.end()) {
        return 'i';
    } else if (jTypeInstruction.find(instruction) != jTypeInstruction.end()) {
        return 'j';
    }
    /* This case denotes an error */
    return ' ';
}

