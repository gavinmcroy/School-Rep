#include <iostream>

using namespace std;

int main() {
    printf("%4s", "x");
    for (int i = 1; i < 10; i++) {
        printf("%4d", i);
    }
    for (int i = 1; i < 10; i++) {
        printf("\n");
        printf("%4d", i);
        for (int j = 1; j < 10; j++) {
            printf("%4d", i * j);
        }
    }
    return 0;
}
