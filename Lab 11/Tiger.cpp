//
// Created by Gavin McRoy on 4/9/2020.
//
#include<iostream>
#include <utility>
#include "Tiger.h"

Tiger::Tiger(int unnamed, double unnamed1, std::string name, std::string soundsLike) : Animal(unnamed, unnamed1) {
    this->name = std::move(name);
    this->soundsLike = std::move(soundsLike);
}

std::string Tiger::getVoice() {
    return soundsLike;
}

std::string Tiger::getName() {
    return name;
}

void Tiger::setVoice(std::string soundsLike) {
    this->soundsLike = std::move(soundsLike);
}

void Tiger::setName(std::string name) {
    this->name = std::move(name);
}

void Tiger::printInfo() {
    std::cout << "Tiger Info" << std::endl;
}
