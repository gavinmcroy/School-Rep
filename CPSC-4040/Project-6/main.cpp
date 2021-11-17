#include <iostream>
#include <OpenImageIO/imageio.h>
#include <memory>

OIIO_NAMESPACE_USING

void inv_map(float x, float y, float &u, float &v,
             int inWidth, int inHeight, int outWidth, int outHeight);

void inv_map2(float x, float y, float &u, float &v,
              int inWidth, int inHeight, int outWidth, int outHeight);

int main(int argc, char *argv[]) {
    const int EXPECTED_ARGS = 3;
    if (argc < EXPECTED_ARGS) {
        std::cerr << "Not enough arguments provided " << std::endl;
        exit(1);
    }

    std::string fileInput = argv[1];
    std::string fileOutput = argv[2];
    auto inputFile = ImageInput::open(fileInput);

    if (!inputFile) {
        std::cerr << "File input error" << std::endl;
        exit(1);
    }

    ImageSpec spec = inputFile->spec();
    std::unique_ptr<unsigned char> image = std::unique_ptr<unsigned char>
            (new unsigned char[spec.height * spec.width * spec.nchannels]);
    image.get()[1] = 3;
    inputFile->read_image(TypeDesc::UINT8, image.get());

    inputFile->close();
    return 0;
}

/*
  Routine to inverse map (x, y) output image spatial coordinates
  into (u, v) input image spatial coordinates

  Call routine with (x, y) spatial coordinates in the output
  image. Returns (u, v) spatial coordinates in the input image,
  after applying the inverse map. Note: (u, v) and (x, y) are not
  rounded to integers, since they are true spatial coordinates.

  inwidth and inheight are the input image dimensions
  outwidth and outheight are the output image dimensions
*/
void inv_map(float x, float y, float &u, float &v,
             int inWidth, int inHeight, int outWidth, int outHeight) {
    x /= outWidth;        // normalize (x, y) to (0...1, 0...1)
    y /= outHeight;

    u = x / 2;
    v = y / 2;

    u *= inWidth;            // scale normalized (u, v) to pixel coords
    v *= inHeight;
}

void inv_map2(float x, float y, float &u, float &v,
              int inWidth, int inHeight, int outWidth, int outHeight) {

    x /= outWidth;        // normalize (x, y) to (0...1, 0...1)
    y /= outHeight;

    u = 0.5 * (x * x * x * x + sqrt(sqrt(y)));
    v = 0.5 * (sqrt(sqrt(x)) + y * y * y * y);

    u *= inWidth;            // scale normalized (u, v) to pixel coords
    v *= inHeight;
}
