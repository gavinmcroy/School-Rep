#include <iostream>

int main() {
    int totalInputs = 0;
    long int initialPos = 0;
    long int totalJumps = 0;
    std::cin >> totalInputs;

    for (int i = 0; i < totalInputs; i++) {
        std::cin >> initialPos >> totalJumps;
        for (int j = 0; j < totalJumps; j++) {
            if (initialPos % 2 == 0) {
                /* Goes left*/
                // j+1;
                initialPos -= (j + 1);
            } else {
                /* Goes right */
                initialPos += (j + 1);
            }
        }
        std::cout << initialPos << std::endl;
    }

    //if the point where the grasshopper was before the jump has an even coordinate,
    // the grasshopper jumps to the left, otherwise he jumps to the right

    return 0;
}
