//
// Created by Gavin Taylor Mcroy on 3/11/2020 AD.
//

#ifndef ASSIGNMENT_1_SINGLETON_H
#define ASSIGNMENT_1_SINGLETON_H


class Singleton {
private:
    static Singleton* instance;
    Singleton();
public:
    static Singleton* getInstance();
};


#endif //ASSIGNMENT_1_SINGLETON_H
