#include <iostream>
#include <OpenImageIO/imageio.h>
#include "Color.h"
#include "Geometry.h"
#include "Scene.h"

int main() {
    Scene scene;
    scene.mainRenderLoop();
    scene.outputRender();

    return 0;
}
