//
// Created by Gavin McRoy on 3/30/2020.
//
#include<iostream>
#include "Object.h"

//---Operator Overloading
Object& Object::operator=(const Object& object) {
    std::cout<<"Assignment Operator For OBJ Called"<<std::endl;
}

std::ostream& operator<<(std::ostream &out,const Object &obj ){
    out<<"This is a test"<<std::endl;
    out<<"And as a test may progress"<<std::endl;
    out<<"So will we"<<std::endl;
    out<<"Stream Insertion Operator Override Called"<<std::endl;
    return out;
}
//---Copy Constructor
Object::Object(const Object &obj){
    std::cout<<"Whatever it got copied"<<std::endl;
}

Object::Object(){

}
