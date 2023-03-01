//
// Created by Gavin Taylor Mcroy on 3/11/2020 AD.
//

#ifndef ASSIGNMENT_1_REFACTOR_H
#define ASSIGNMENT_1_REFACTOR_H


class Refactor {
private:
    static Refactor* instance;
    Refactor();
public:
    static Refactor* getInstance();
};


#endif //ASSIGNMENT_1_REFACTOR_H
