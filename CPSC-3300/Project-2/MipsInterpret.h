//
// Created by Gavin Taylor Mcroy on 10/26/21.
//

#ifndef PROJECT_2_MIPSINTERPRET_H
#define PROJECT_2_MIPSINTERPRET_H

#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

class MipsInterpret {
private:
    std::string inputFile;
    std::string outputFile;
    const int MAX_ARGS = 3;
    const int MAX_REGISTERS = 32;
    std::unordered_map<std::string,int> assemblerMap;

    bool isValidRegister(const std::string &reg);

public:
    MipsInterpret(int argc, char * argv[]);

    void buildTable();

    void readFile();



    void outFile();
};


#endif //PROJECT_2_MIPSINTERPRET_H
