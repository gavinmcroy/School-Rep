#include "Ppm.h"
#include "Pgm.h"
#include "Refactor.h"

/*
 * Gavin McRoy
 */
int main(int argc, char *argv[]) {
    std::string input;
    std::string output;
    input.append(argv[1]);
    output.append(argv[2]);
    Refactor *refactor = Refactor::getInstance(input, output);
    return 0;
}
