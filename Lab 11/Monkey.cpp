//
// Created by Gavin McRoy on 4/9/2020.
//
#include<iostream>
#include <utility>
#include "Monkey.h"

Monkey::Monkey(int age, double weight, std::string name, std::string soundsLike) : Animal(age, weight) {
    this->name = std::move(name);
    this->soundsLike = std::move(soundsLike);
}

std::string Monkey::getVoice() {
    return soundsLike;
}

std::string Monkey::getName() {
    return name;
}

void Monkey::setVoice(std::string voice) {
    this->soundsLike = std::move(voice);
}

void Monkey::setName(std::string name) {
    this->name = std::move(name);
}

void Monkey::printInfo() {
    std::cout << "***************************************" << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Sound Made: " << getVoice() << std::endl;
    std::cout << "Age: " << getAge() << std::endl;
    std::cout << "Weight: " << getWeight() << std::endl;
    std::cout << "***************************************" << std::endl;
}