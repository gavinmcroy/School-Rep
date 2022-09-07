#include "functions.h"

int printReturn(int a, int b, int action) {
    return action == 1 ? a == b : action == 2 ? a < b : action == 3 ? a > b : -50000;
}
