//
// Created by Gavin McRoy on 4/9/2020.
//

#ifndef LAB_11_ANIMAL_H
#define LAB_11_ANIMAL_H


class Animal {
private:
    int age;
    double weight;
public:
    Animal(int, double);

    int getAge();

    double getWeight();

    void setAge(int);

    void setWeight(double);

    virtual void printInfo();
};


#endif //LAB_11_ANIMAL_H
