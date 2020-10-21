//
// Created by Gavin McRoy on 10/21/2020.
//

#ifndef LAB07_CLION_NQUEENSOLVER_H
#define LAB07_CLION_NQUEENSOLVER_H


class NQueenSolver {

private:
    int size;
    int count;
    char **board;
public:
    explicit NQueenSolver(int size);

    int check_row(int row);

    bool isValid(int r, int c);

};


#endif //LAB07_CLION_NQUEENSOLVER_H
