//
// Created by Gavin McRoy on 11/25/2020.
//

#include <cstdio>
#include "Blur.h"
#include "graphics.h"

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

void Blur::buildMegaNode() {
    megaNode = std::make_pair(0, 0);
    findEveryWhitePixel();
    neighbors.insert(std::make_pair(megaNode, allWhitePixels));
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
    breadthFirstSearch(megaNode);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int location = j * width + i;
            int x = distance[std::make_pair(i, j)];
            int calculation = 255 * std::pow(.9, x-1);
            image[location].r = calculation;
            image[location].g = calculation;
            image[location].b = calculation;
        }
    }
}

void Blur::mainCalculateBlur(){
    readImage("paw.ppm");
    buildMegaNode();
    calculateBlur();
    writeImage("paw2.ppm");
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

int Blur::printShortedPathOnImage(Node x, Node y) {
    int steps = 0;
    while (predecessor[y] != x) {
        int operation = y.second * width + y.first;
        Node val = predecessor[y];
        image[operation].r = 255;
        image[operation].g = 0;
        image[operation].b = 0;
        y = val;
        steps++;
    }
    return steps;
}


bool Blur::seam_exists(void) {
    for (int x = 0; x < width; x++) if (getPixel(x, 0) == red) return true;
    return false;
}

void Blur::remove_seam(void) {
    std::cout << "Removing seam to decrease width to " << width - 1 << "\n";
    for (int y = 0; y < height; y++) {
        int where_red = -1;
        for (int x = 0; x < height; x++)
            if (getPixel(x, y) == red)
                if (where_red != -1) {
                    std::cout << "Error: row " << y << " hass >1 red pixel set\n";
                    exit(0);
                }
                else where_red = x;
        if (where_red == -1) {
            std::cout << "Error: row " << y << " has 0 red pixels set\n";
            exit(0);
        }
        for (int x = where_red; x < width - 1; x++) getPixel(x, y) = getPixel(x + 1, y);
    }

    // Create a new image with one smaller width
    Blur::Pixel *orig_image = image;
    width--;
    image = new Pixel[height * width];
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            getPixel(x, y) = orig_image[y * (width + 1) + x];
    delete[] orig_image;

    calculateBlur();
}

/* Simple 2D interactive graphics code... */

bool show_blurred_image = false;

// Called on each keypress
void Blur::keyhandler(int key) {
    if (key == 'q') exit(0);

    // Toggle showing blurred image (off-white pixels)
    if (key == 'b') show_blurred_image = !show_blurred_image;

    // Find and remove one seam
    if (key == 's' && !seam_exists()) calculate_seam();

    // Find and remove 2...9 seams
    if ((key >= '2' && key <= '9') && !seam_exists())
        for (int i = 0; i < key - '0'; i++) {
            calculate_seam();
            remove_seam();
        }
}

// Called any time the scene needs to be re-rendered
void Blur::render(void) {
    // Always plot white and red pixels.  Show all other pixels if blur
    // mode is toggled on
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++) {
            Pixel p = getPixel(x, y);
            if (show_blurred_image || p == white || p == red) {
                set_color(p.r, p.g, p.b);
                draw_pixel(x, y);
            }
        }

    // Fill in empty space at right from shrinking the image with blue
    set_color(0, 0, 255);
    for (int x = width; x < 800; x++)
        draw_line(x, 0, x, height - 1);
}

// Called periodically (msec is amount of time since last called)
// Return true if a re-render is needed
// Right now this function waits a second after finding a seam to
// remove it (allowing it to be visualized briefly)
bool Blur::timer(int msec) {
    static int cumulative = 0;
    static bool found_seam = false;
    cumulative += msec;
    if (cumulative > 1000) {
        cumulative -= 1000;
        if (seam_exists()) {
            if (found_seam) {
                remove_seam();
                found_seam = false;
                return true;
            }
            found_seam = true;
        }
    }
    return false;
}

void Blur::commenceApplication(int argc, char* argv[]) {
    readImage("billboard.ppm");
    init_graphics(argc, argv, width, height, render, keyhandler, timer);
}
