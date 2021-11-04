#include <iostream>

typedef struct Data {
    int brightness;
    char color;
} Data;

int main() {
    int iterations = 0;
    int totalData = 0;
    std::cin >> iterations;


    std::cin >> totalData;
    Data data[totalData];

    for (int i = 0; i < totalData; i++) {
        std::cin >> data[i].brightness;
    }
    for (int i = 0; i < totalData; i++) {
        std::cin >> data[i].color;
    }

    for (int i = 0; i < totalData; i++) {
        if(data[i].color=='B'){
            /* Fill */
        }else if(data[i].color=='R'){
            /* Fill   */
        }
        for(int j = 0; j <  totalData; j++){

        }
    }

    //either you can select any blue element and decrease its value by 1;
    // or you can select any red element and increase its value by 1.

    return 0;
}
