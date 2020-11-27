//
// Created by Gavin McRoy on 11/25/2020.
//

#include <cstdio>
#include "Blur.h"

Blur::Blur() {
    this->width = 0;
    this->height = 0;
    this->image = nullptr;
}

Blur::Pixel &Blur::getPixel(int x, int y) {
    return image[y * width + x];
}

void Blur::readImage(const char *filename) {
    FILE *fp = fopen(filename, "r");
    fscanf(fp, "P6\n%d %d\n255%*c", &width, &height);
    image = new Pixel[width * height];
    fread(image, width * height, sizeof(Pixel), fp);
    fclose(fp);
}

void Blur::writeImage(const char *filename) {
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(image, width * height, sizeof(Pixel), fp);
    fclose(fp);
}

Blur::Node Blur::breadthFirstSearch(const Node &source) {
    buildGraph();
    for (int i = 0; i < height * width; i++) {
        distance[image[i]] = height * width;
    }
    Node lastVisited;
    distance[source] = 0;
    std::queue<Node> toVisit;
    toVisit.push(source);

    while (!toVisit.empty()) {
        Node x = toVisit.front();
        lastVisited = x;
        toVisit.pop();

        for (const Node &n : neighbors[x]) {
            if (distance[n] == (height * width)) {
                distance[n] = 1 + distance[x];
                predecessor[n] = x;
                toVisit.push(n);
            }
        }

    }
    return lastVisited;
}

void Blur::buildGraph() {
    std::vector<Node> tempNeighbors;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (i - 1 >= 0) {
                tempNeighbors.push_back(getPixel(i - 1, j));
            }
            if (i + 1 < width) {
                tempNeighbors.push_back(getPixel(i + 1, j));
            }
            if (j - 1 >= height) {
                tempNeighbors.push_back(getPixel(i, j - 1));
            }
            if (j + 1 < height) {
                tempNeighbors.push_back(getPixel(i, j + 1));
            }
            neighbors.insert(std::make_pair(getPixel(i, j), tempNeighbors));
            tempNeighbors.clear();
        }
    }
}

bool Blur::Pixel::operator<(const Pixel &pixel) const {
    return (r + g + b) > (pixel.r + pixel.g + pixel.b);
}

void Blur::calculateBlur() {
    for (int i = 0; i < width * height; i++) {
        breadthFirstSearch(image[i]);
    }
}