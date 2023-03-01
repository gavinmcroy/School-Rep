#include <iostream>
#include <fstream>
#include "CatmullRom.h"

void demoCatmullRom(const std::string &fileName);


void writeFile();

/* TODO Refactoring + New Vector Class */
int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Not enough command line arguments. Expected ./a.out points.txt" << std::endl;
        exit(1);
    }
    std::string fileName = argv[1];
    demoCatmullRom(fileName);
}

void demoCatmullRom(const std::string &fileName) {
    Curve *curve = new CatmullRom();
    /* Generate 100 points*/
    const int MAX_POINTS = 20;
    curve->setSteps(MAX_POINTS);
    std::ifstream file;
    file.open(fileName);

    if (file.fail()) {
        std::cerr << "File open error" << std::endl;
        exit(1);
    }
    double x, y, z, t1, t2, t3;
    while (file >> x >> y >> z >> t1 >> t2 >> t3) {
        curve->addWayPoint(Vector(x, y, z));
    }

    std::cout << "nodes: " << curve->nodeCount() << std::endl;
    std::cout << "total length: " << curve->totalLength() << std::endl;
    for (int i = 0; i < curve->nodeCount(); i++) {
//		std::cout << "node #" << i << ": " << curve->node(i).__str__() << " (length so far: " << curve->lengthFromStartingPoint(
//                i) << ")" << std::endl;
    }

    std::ofstream outFile;
    outFile.open("out.txt");
    if (outFile.fail()) {
        std::cerr << "Error writing file" << std::endl;
        exit(1);
    }

    for (int i = 0; i < curve->nodeCount(); i++) {
       outFile << curve->node(i).__str__() << std::endl;
    }

    delete curve;
}
