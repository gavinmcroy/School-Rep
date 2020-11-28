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
}

Blur::Pixel::Pixel() {

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

    //Node lastVisited;
    distance[source] = 0;
    std::queue<Node> toVisit;
    toVisit.push(source);

    while (!toVisit.empty()) {
        Node x = toVisit.front();
        //lastVisited = x;
        toVisit.pop();

        for (const Node &n : neighbors[x]) {
            if (distance[n] == (height * width)) {
                distance[n] = 1 + distance[x];
                predecessor[n] = x;
                toVisit.push(n);
            }
        }

    }
    //return lastVisited;
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
//    int di[] = {+1, -1, 0, 0};
//    int dj[] = {0, 0, +1, -1};
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
//            for (int k = 0; k < 4; k++) {
//                Node temp = std::make_pair(x, y);
//                Node nbr = std::make_pair(x + di[k], y + dj[k]);
//                neighbors[temp].push_back(nbr);
//            }
            if (x - 1 >= 0) {
                tempNeighbors.emplace_back(x - 1, y);
                //tempNeighbors.emplace_back(y, x - 1);
            }
            if (x + 1 < width) {
                tempNeighbors.emplace_back(x + 1, y);
                //tempNeighbors.emplace_back(y, x + 1);
            }
            if (y - 1 >= 0) {
                tempNeighbors.emplace_back(x, y - 1);
                //tempNeighbors.emplace_back(y - 1, x);
            }
            if (y + 1 < height) {
                 tempNeighbors.emplace_back(x, y + 1);
                //tempNeighbors.emplace_back(y + 1, x);
            }
            /* Insert the node and then its neighbors */
            neighbors.insert(std::make_pair(std::make_pair(x, y), tempNeighbors));
            //neighbors.insert(std::make_pair(std::make_pair(j, i), tempNeighbors));
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

/* Call print path from every pixel until it finds the nearest white pixel ? */
void Blur::calculateBlur() {
    for (int i = 0; i < width * height; i++) {
        //printPath()
    }
}
int steps = 0;
void Blur::printPath(Node x, Node y) {
    if (x != y) printPath(x, predecessor[y]);
    image[y.second * width + y.first] = Pixel(255, 0, 0);
    steps++;
    /* y * width + x */
}

int Blur::getSteps() {
    return steps;
}