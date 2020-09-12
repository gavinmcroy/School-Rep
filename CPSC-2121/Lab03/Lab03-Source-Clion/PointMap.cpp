//
// Created by Gavin McRoy on 9/12/2020.
//
#include<fstream>
#include "PointMap.h"

PointMap::PointMap() {
    file.open("points.txt", std::ios::in);
    int x, y;

    /* Allocate points to table */

    if (file.is_open()) {
        std::cout << "File opened" << std::endl;
        while (file >> x >> y) {

        }
    }


}

int PointMap::hashValue(int val){
    
}