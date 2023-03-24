
#include <iostream>
#include <cstdlib>

using namespace std;

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


    cout << N << "\n";
    for (int i = 0; i < N; i++) {
        cout<<3327+(i)*10000<< "   ";
    }
    return 0;
}
