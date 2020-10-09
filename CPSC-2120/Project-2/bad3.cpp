

#include <iostream>
#include <cstdlib>

using namespace std;

int get_rand(int N) {
    return 123456789 % N;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: bad1 <input size>\n";
        return 0;
    }

    int N = atoi(argv[1]);  // get first command-line argument
    if (N < 1 || N > 100000) {
        cout << "Invalid input size!\n";
        return 0;
    }

    /* p = 123456789 % (len - p - 1)*/
    cout << N << "\n";
    for (int i = 0; i < N; i++) {
//        if(get_rand(i)){
//
//        }
        cout << 5 << endl;
    }
    return 0;
}
