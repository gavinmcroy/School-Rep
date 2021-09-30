#include <iostream>
#include "Color.h"
#include "Geometry.h"
#include "Scene.h"

int main() {
    Scene scene;
    scene.mainRenderLoop();
    scene.outputRender();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
