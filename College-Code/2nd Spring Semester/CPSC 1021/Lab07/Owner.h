//
// Created by Gavin Taylor Mcroy on 2/18/2020 AD.
//
#include<string>

#ifndef LAB06_OWNER_H
#define LAB06_OWNER_H


class Owner {
private:
    std::string name;
    int age;
public:
    Owner(std::string,int);

    std::string getName();

    int getAge();
};


#endif //LAB06_OWNER_H
