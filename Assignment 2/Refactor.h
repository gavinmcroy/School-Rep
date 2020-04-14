//
// Created by Gavin Taylor Mcroy on 3/11/2020 AD.
//

#ifndef ASSIGNMENT_1_REFACTOR_H
#define ASSIGNMENT_1_REFACTOR_H


class Refactor {
private:
    static Refactor* instance;
    Refactor(const std::string&,const std::string&);
public:
    static Refactor* getInstance(const std::string&,const std::string&);
};


#endif //ASSIGNMENT_1_REFACTOR_H
