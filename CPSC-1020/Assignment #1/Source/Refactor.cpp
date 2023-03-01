//
// Created by Gavin Taylor Mcroy on 3/11/2020 AD.
//
#include "Ppm.h"
#include "Pgm.h"
#include "Refactor.h"

Refactor::Refactor() {
    Pgm pgm("potatochips.pgm");
    Pgm pgm1("chips.pgm");
    Ppm ppm("potatochips.ppm");
    Ppm ppm1("chips.ppm");
}

Refactor *Refactor::getInstance() {
    if (!instance) {
        instance = new Refactor();
        return instance;
    } else {
        return instance;
    }
}

Refactor *Refactor::instance = nullptr;
