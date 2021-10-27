//
// Created by Gavin Taylor Mcroy on 10/26/21.
//

#include "MipsInterpret.h"

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
    std::ifstream file(inputFile);
    if (!file) {
        std::cerr << inputFile << " failed to open. Closing " << std::endl;
        exit(1);
    }

    //add $1, $2, $3
    std::string instruction, arg1, arg2, reg;
    int line = 1;
    while (file >> instruction >> arg1 >> arg2 >> reg) {
        /* Command is invalid */
        if (assemblerMap.find(instruction) == assemblerMap.end()) {
            std::cerr << "Error. Unsupported instruction on line " << line << std::endl;
        }
        line++;
    }

    file.close();
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

    char list[6] = {'1', '2', '3', '4', '5','6'};

    myFile.write(list, 6);

    if (!myFile.good()) {
        std::cerr << "Error occurred at writing time!" << std::endl;
        exit(1);
    }
    myFile.close();
}
