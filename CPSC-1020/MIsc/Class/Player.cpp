//
// Created by Gavin Taylor Mcroy on 2/7/2020 AD.
//
#include<iostream>
#include "Player.h"

bool Player::is_dead() {
    std::cout<<"Player has fallen"<<std::endl;
}

void Player::talk(std::string) {
    std::cout<<"Player is taking"<<std::endl;
}

Player::Player(){
    name = "Default name ";
    health = 100;
    xp = 20;
}

Player::Player(int x ){
    std::cout<<x<<std::endl;
}

Player::~Player(){
    std::cout<<"Object Destroyed"<<std::endl;
}

int Player::get_health(){
    return health;
}
int Player::get_xp(){
    return xp;
}