//
// Created by Gavin McRoy on 11/25/2020.
//

#include <cstdio>
#include "Blur.h"

Blur::Blur() {
    this->width = 0;
    this->height = 0;
    this->image = nullptr;
    allNodes.reserve((width * height) / 2);
    allWhitePixels.reserve(75000);
}

Blur::Pixel::Pixel() {
    r = 0;
    g = 0;
    b = 0;
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

void Blur::breadthFirstSearch(const Node &source) {
    buildGraph();
    for (Node &a: allNodes) {
        distance[a] = height * width;
    }
    distance[source] = 0;
    std::queue<Node> toVisit;
    toVisit.push(source);

    while (!toVisit.empty()) {
        Node x = toVisit.front();
        toVisit.pop();
        for (const Node &n : neighbors[x]) {
            if (distance[n] == (height * width)) {
                distance[n] = 1 + distance[x];
                predecessor[n] = x;
                toVisit.push(n);
            }
        }
    }

}

void Blur::buildGraph() {
    std::vector<Node> tempNeighbors;
    tempNeighbors.reserve(4);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            /* Index of every pixel in the image */
            allNodes.emplace_back(x, y);
        }
    }
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (x - 1 >= 0) {
                tempNeighbors.emplace_back(x - 1, y);
            }
            if (x + 1 < width) {
                tempNeighbors.emplace_back(x + 1, y);
            }
            if (y - 1 >= 0) {
                tempNeighbors.emplace_back(x, y - 1);
            }
            if (y + 1 < height) {
                tempNeighbors.emplace_back(x, y + 1);
            }
            /* Insert the node and then its neighbors */
            neighbors.insert(std::make_pair(std::make_pair(x, y), tempNeighbors));
            tempNeighbors.clear();
        }
    }
}

bool Blur::Pixel::operator<(const Pixel &pixel) const {
    return (r + g + b) > (pixel.r + pixel.g + pixel.b);
}

bool Blur::Pixel::operator!=(const Blur::Pixel &pixel) const {
    return !(r == pixel.r && g == pixel.g && b == pixel.b);
}

bool Blur::Pixel::operator==(const Blur::Pixel &pixel) const {
    return (r == pixel.r && g == pixel.g && b == pixel.b);
}

/* Call print path from every pixel until it finds the nearest white pixel ? */
void Blur::calculateBlur() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if(getPixel(i,j)==Blur::white){
                modified(std::make_pair(i,j),std::make_pair(0,0));
            }
        }
    }
}


void Blur::findEveryWhitePixel() {
    int tempCount = 0;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (getPixel(i, j) == Blur::white) {
                allWhitePixels.emplace_back(i, j);
                tempCount++;
            }
        }
    }
    std::cout << allWhitePixels.at(0).first << " " << allWhitePixels.at(0).second;
}


//void Blur::printPath(Node x, Node y) {
//    if (x != y) printPath(x, predecessor[y]);
//    // int val = 255; // (int) 255 * std::pow(.9,steps);
//    image[y.second * width + y.first] = Pixel(0, 0, 255);
//    steps++;
//    /* y * width + x */
//}

int Blur::modified(Node x, Node y) {
    int steps = 0;
    while (predecessor[y] != x) {
        int operation = y.second * width + y.first;
        int calculated = (int) 255 * std::pow(.9,steps);
        Node val = predecessor[y];
        image[operation].r = calculated;
        image[operation].g = calculated;
        image[operation].b = calculated;
        y = val;
        steps++;
    }
    return steps;
}
