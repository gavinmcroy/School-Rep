#include <iostream>
#include "NQueenSolver.h"
/* X represents position of queen on the board */

int recursion(int x){
    if(x>100){
        return 0;
    }
   // std::cout<<x<<std::endl;
    return x+1;
}


int main() {
    NQueenSolver nQueenSolver(8);
    //std::cout<<nQueenSolver.check_row(0)<<std::endl;
    std::cout<<recursion(0)<<std::endl;



    return 0;
}
