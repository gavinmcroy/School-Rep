//
// Created by Gavin McRoy on 11/25/2020.
//
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <queue>

#ifndef PROJECT_4_BLUR_1_BLUR_H
#define PROJECT_4_BLUR_1_BLUR_H


class Blur {
private:

    struct Pixel {
        unsigned char r, g, b;

        bool  operator < (const Pixel &pixel) const;
    };

    typedef Pixel Node;

    Pixel *image;
    int width;
    int height;
    Pixel white = {255, 255, 255};
    Pixel black = {0, 0, 0};

    std::map<Node, int> distance;
    std::map<Node, Node> predecessor;
    std::map<Node, std::vector<Node>> neighbors;



public:

    Blur();

    Pixel &getPixel(int x, int y);

    void readImage(const char *filename);

    void writeImage(const char *filename);

    Node breadthFirstSearch(const Node &source);

    void calculateBlur();

    void buildGraph();

};


#endif //PROJECT_4_BLUR_1_BLUR_H
