//
// Created by Gavin Taylor Mcroy on 2/7/2020 AD.
//
#include<string>

#ifndef C___CLASS_PLAYER_H
#define C___CLASS_PLAYER_H


class Player {

private:
    std::string name;
    int health;
    int xp;
public:
    void talk(std::string);
    Player();
    Player(int);
    ~Player();

    int get_health();
    int get_xp();
    bool is_dead();

};


#endif //C___CLASS_PLAYER_H
