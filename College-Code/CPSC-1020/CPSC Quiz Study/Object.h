//
// Created by Gavin Taylor Mcroy on 3/1/2020 AD.
//

#ifndef CPSC_QUIZ_STUDY_OBJECT_H
#define CPSC_QUIZ_STUDY_OBJECT_H


class Object {

private:
    int x;
    int y;
    static int val;
public:
    Object(int,int);
    Object();
    Object(const Object& object);
    int operator + (const Object&);
    int getX();
    static int getVal();
};


#endif //CPSC_QUIZ_STUDY_OBJECT_H
