//
// Created by Gavin McRoy on 4/9/2020.
//
#include<iostream>
#include "Animal.h"

Animal::Animal(int age, double weight) {
    this->age = age;
    this->weight = weight;
}

int Animal::getAge() {
    return age;
}

double Animal::getWeight() {
    return weight;
}

void Animal::setAge(int age) {
    this->age = age;
}

void Animal::setWeight(double weight) {
    this->weight = weight;
}

void Animal::printInfo() {
    std::cout << "Print Info Default" << std::endl;
}