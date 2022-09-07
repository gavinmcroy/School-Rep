//
// Created by Gavin McRoy on 4/9/2020.
//

#ifndef LAB_11_MONKEY_H
#define LAB_11_MONKEY_H

#include<string>
#include "Animal.h"

class Monkey : public Animal {
private:
    std::string name;
    std::string soundsLike;
public:
    Monkey(int , double , std::string, std::string);

    std::string getVoice();

    std::string getName();

    void setVoice(std::string);

    void setName(std::string);

    void printInfo() override;


};


#endif //LAB_11_MONKEY_H
