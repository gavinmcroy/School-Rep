//
// Created by Gavin McRoy on 11/10/2020.
//

#ifndef LAB09_FILLINGJUGS_H
#define LAB09_FILLINGJUGS_H


class FillingJugs {

    struct Jug{
        int amount;

        explicit Jug(int amount){
            this->amount = amount;
        }
    };
public:

    FillingJugs();

    void solve();

};


#endif //LAB09_FILLINGJUGS_H
