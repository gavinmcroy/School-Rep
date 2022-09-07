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

public:
    struct Pixel {
        unsigned char r, g, b;

        bool operator<(const Pixel &pixel) const;

        bool operator!=(const Pixel &pixel) const;

        bool operator==(const Pixel &pixel) const;

        Pixel(unsigned char r, unsigned char g, unsigned char b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }

        Pixel();
    };

    typedef std::pair<int, int> Node;

    Node megaNode;
    Pixel *image;
    int width;
    int height;

    Pixel white = {255, 255, 255};
    Pixel black = {0, 0, 0};
    Pixel red = {255, 0, 0};

    std::vector<Node> allWhitePixels;
    std::vector<Node> allNodes;
    std::map<Node, int> distance;
    std::map<Node, Node> predecessor;
    std::map<Node, std::vector<Node>> neighbors;

    Pixel &getPixel(int x, int y);

    void readImage(const char *filename);

    void writeImage(const char *filename);

    void breadthFirstSearch(const Node &source);

    void calculateBlur();

    void buildGraph();

    void buildMegaNode();

    void findEveryWhitePixel();

    int printShortedPathOnImage(Node x, Node y);

public:
    Blur();

    void mainCalculateBlur();

    void calculate_seam();

    bool seam_exists();

    void remove_seam();

    static void keyhandler(int key);

    static void render();

    static bool timer(int msec);

    void commenceApplication(int argc, char* argv[]);
};


#endif //PROJECT_4_BLUR_1_BLUR_H
