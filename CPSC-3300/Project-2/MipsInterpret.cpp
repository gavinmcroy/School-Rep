//
// Created by Gavin Taylor Mcroy on 10/26/21.
//

#include "MipsInterpret.h"

#include <utility>

MipsInterpret::commandLine::commandLine(std::string instr, std::string r1, std::string r2, std::string r3) {
    this->instruction = std::move(instr);
    this->rd = std::move(r1);
    this->rs = std::move(r2);
    this->rt = std::move(r3);
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

    std::string instruction, rd, rs, rt;

    int line = 1;
    while (file >> instruction) {
        char instructType = getInstructionType(instruction);
        /* r has $rd $rs $rt */
        if (instructType == 'r') {
            file >> rd >> rs >> rt;
        } else if (instructType == 'i') {
            /* Special case since beq has $rs $rt and immediate*/
            if (instruction == "beq") {
                file >> rd >> rs >> rt;
            } else {
                file >> rd >> rs;
            }
        } /* j has just address */
        else if (instructType == 'j') {
            file >> rd;
        } else {
            std::cout << "error" << std::endl;
        }

        if (errorChecking(instruction, rd, rs, rt, line)) {
            std::cerr << "Program cannot continue. Closing " << std::endl;
            exit(1);
        }

        commands.emplace_back(instruction, rd, rs, rt);
        line++;
    }
    file.close();
}

void MipsInterpret::compile() {
    /* Essentially we are converting instructions into binary digits */
    std::vector<unsigned int> instructionsTranslated;
    int instructionOutput = 0;

   // for(int i = 0; i < commands.size(); i++){
        char instr = getInstructionType(commands[0].instruction);
        if(instr =='r'){
            /* This determines which bit will be modified */
            int n = 25;
            //31 - 26 [opcode] always remains 0

            //25-21 [%rs register]
            int registerNumber = convertRegisterToNumber(commands[0].rs);
            std::cout << "Register number "<< registerNumber << std::endl;
            /* Important value that must be grabbed by decimal conversion */
            int increment = 0;
            int * binary = decimalToBinary(registerNumber,increment);

            for (int j = increment - 1; j >= 0; j--) {
                std::cout << binary[j];
            }
            for(int i = 0; i < 5; i++){
                if(binary[]){
                    toggleSpecificBit(n,instructionOutput);
                }
                n--;
            }

            /* Now we need to toggle bits */

            //20-16 [$rt register]
            //15-11 [$rd register]
            //[10-6][shamt]
            //[actual ID number]
        }
   // }

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

/* sets all other binary values to 0*/
int * MipsInterpret::decimalToBinary(int n, int &important) {
    int * binaryNum = new int[32];
    for(int i =0 ; i < 32; i++){
        binaryNum[i] = 0;
    }
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    important = i;

    // printing binary array in reverse order
//    for (int j = i - 1; j >= 0; j--)
//        std::cout << binaryNum[j];

    return binaryNum;
}

void MipsInterpret::toggleSpecificBit(int n, int &valueToChange) {
    valueToChange ^= 1UL << n;
    std::cout << valueToChange << std::endl;
}

int MipsInterpret::convertRegisterToNumber(const std::string& reg) {
    /* $20 is 3 digits */
    std::string local;
    int value = 0;
    if(reg.size() > 2){
        local = reg.substr(1, 2);
        value = stoi(local);
    }else{
        value = stoi(local);
    }
    return value;
}

