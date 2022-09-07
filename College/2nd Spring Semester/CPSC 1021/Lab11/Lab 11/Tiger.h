//
// Created by Gavin McRoy on 4/9/2020.
//

#include<string>
#include "Animal.h"

#ifndef LAB_11_TIGER_H
#define LAB_11_TIGER_H


class Tiger : public Animal {
private:
    std::string name;
    std::string soundsLike;
public:
    Tiger(int age, double weight, std::string, std::string);

    std::string getVoice();

    std::string getName();

    void setVoice(std::string);

    void setName(std::string);

    void printInfo() override;

};


#endif //LAB_11_TIGER_H
