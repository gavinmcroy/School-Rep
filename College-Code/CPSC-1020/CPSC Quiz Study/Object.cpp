//
// Created by Gavin Taylor Mcroy on 3/1/2020 AD.
//
#include<iostream>
#include "Object.h"

Object::Object(){
    this->x = 100;
    this->y = 100;
}

Object::Object(int x,int y){
    this->x = x;
    this->y = y;
}

int Object::operator + (const Object& obj){
    std::cout<<"Working"<<std::endl;
    std::cout<<this->x<<" "<<obj.x<<std::endl;
    return this->x + obj.x;
}

Object::Object(const Object &object){
    this->x=object.x;
    this->y=object.y;
}

int Object::getX() {
    return x;
}

int Object::val = 0;

int Object::getVal() {
    return val;
}