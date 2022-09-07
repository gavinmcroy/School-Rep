//
// Created by Gavin Taylor Mcroy on 2/18/2020 AD.
//
#include "Dog.h"
#include<iostream>
#include<iomanip>
#include <utility>

int Dog::dogCount = 0;

Dog::Dog() : breed("Default"), age(0), owner("Default", 10) {
    dogCount++;
}

Dog::Dog(std::string name, int age) : breed("Default"), age(0), owner(std::move(name), age) {
    dogCount++;
}

std::string Dog::getBreed() {
    return breed;
}

int Dog::getAge() {
    return age;
}


void Dog::setBreed(std::string dogBreed) {
    this->breed = std::move(dogBreed);
}

void Dog::setAge(int dogAge) {
    this->age = dogAge;
}

void Dog::printDogInfo() {
    std::cout << std::left << std::setw(9) << "Dog " << dogCount << std::endl;
    std::cout << std::left << std::setw(9) << "breed:   " << breed << std::endl;
    std::cout << std::left << std::setw(9) << "age:   " << age << std::endl;
    std::cout << std::left << std::setw(9) << "owner: " << owner.getName() << ", " << owner.getAge() << " yo"
              << std::endl;
}

int Dog::getDogCount() {
    return dogCount;
}