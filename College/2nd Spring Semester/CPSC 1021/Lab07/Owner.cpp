//
// Created by Gavin Taylor Mcroy on 2/18/2020 AD.
//

#include "Owner.h"

Owner::Owner(std::string name,int age) {
    this->name = std::move(name);
    this->age = age;
}

std::string Owner::getName() {
    return name;
}

int Owner::getAge() {
    return age;
}
