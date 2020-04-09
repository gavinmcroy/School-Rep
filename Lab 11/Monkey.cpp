//
// Created by Gavin McRoy on 4/9/2020.
//

#include "Monkey.h"
#include<iostream>
#include <utility>

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
    std::cout << "Monkey Info" << std::endl;
}