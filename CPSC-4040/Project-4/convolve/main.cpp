#include <iostream>
#include <fstream>

int *readFilterFile(const std::string &fileName, int &kernelSize);

// ./out filter.filt in.png [out.png]
int main(int argc, char * argv[]) {
    const int OUTPUT_PASSED = 4;
    if(argc < 3){
        std::cerr<<"Not enough command line arguments"<<std::endl;
    }
    std::string filterFileName = argv[1];
    std::string imageFileName = argv[2];
    std::string outputFileName = "out.png";

    if(argc == OUTPUT_PASSED){
        outputFileName = argv[3];
    }



    int kernelSize = 0;
    int *x = readFilterFile(filterFileName, kernelSize);
    std::cout << kernelSize << std::endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int *readFilterFile(const std::string &fileName, int &kernelSize) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "File read error" << std::endl;
        exit(1);
    }
    file >> (kernelSize);
    int * weights = new int[kernelSize*kernelSize];

    for (int i = 0; i < kernelSize*kernelSize; i++) {
            int temp = 0;
            if (file.eof()) {
                std::cerr << "File issue in loop" << std::endl;
            }
            file >> temp;
            weights[i] = temp;
            std::cout << weights[i] << " ";
            if(!(i % kernelSize)){
                std::cout << std::endl;
            }
        }


    return nullptr;
}