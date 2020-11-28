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

        bool operator<(const Pixel &pixel) const;

        bool operator!=(const Pixel &pixel) const;

        Pixel(unsigned char r, unsigned char g, unsigned char b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }

        Pixel();
    };

    typedef std::pair<int, int> Node;

    Pixel *image;
    int width;
    int height;
    Pixel white = {255, 255, 255};
    Pixel black = {0, 0, 0};

    std::vector<Node> allNodes;
    std::map<Node, int> distance;
    std::map<Node, Node> predecessor;
    std::map<Node, std::vector<Node>> neighbors;


public:

    Blur();

    Pixel &getPixel(int x, int y);

    void readImage(const char *filename);

    void writeImage(const char *filename);

    void breadthFirstSearch(const Node &source);

    void calculateBlur();

    void buildGraph();

    void printPath(Node x, Node y);

    int getSteps();

};


#endif //PROJECT_4_BLUR_1_BLUR_H
