//
// Created by Gavin Taylor Mcroy on 2/18/2020 AD.
//
#include<string>
#include "Owner.h"


#ifndef LAB06_DOG_H
#define LAB06_DOG_H


class Dog {
private:
    std::string breed;
    int age;
    Owner owner;

    static int dogCount;
public:
    Dog();

    Dog(std::string, int);

    std::string getBreed();

    int getAge();

    void setBreed(std::string);

    void setAge(int);

    void printDogInfo();

    static int getDogCount();
};


#endif //LAB06_DOG_H
