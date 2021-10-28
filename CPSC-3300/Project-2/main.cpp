#include "MipsInterpret.h"

/* ./out assembly.s out.file */
int main(int argc, char *argv[]) {
    MipsInterpret mipsInterpret(argc,argv);
    mipsInterpret.buildTable();
    mipsInterpret.readFile();
    mipsInterpret.compile();
    mipsInterpret.outFile();
    return 0;
}
