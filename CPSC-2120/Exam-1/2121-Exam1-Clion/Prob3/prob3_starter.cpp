// Guaranteed to output a hash value in the range 0 ... 999,999
#include<iostream>

using namespace std;

unsigned int myhash(int x) {
    return ((unsigned) x * 123147 + 293871) % 100 + 900000;
}

bool find(const int *table, int val) {
    if (table[myhash(val)] != -1) {
        return true;
    }
    return false;
}


int main() {
    int size = 10000000;
    int *table = new int[size];

    int maximum = -1;
    int median = 0;
    int counter = 0;
    for (int i = 0; i < size; i++) {
        table[i] = -1;
    }
    int i = 0;


    while (i < size) {
        if (find(table, i)) {
            int searchIndex = myhash(i);
            /* Search for empty location */
            while (table[searchIndex] != -1) {
                searchIndex++;
                counter++;
                median++;
                /* Reset our counter to the front*/
                if (searchIndex == size) {
                    searchIndex = 0;
                }
                if (counter > maximum) {
                    maximum = counter;
                    counter = 0;
                }
            }
            table[searchIndex] = i;
            //cout<<"infinte "<<i<<endl;
            i++;
        } else {
            table[myhash(i)] = i;
            i++;
        }
    }
//    for(int i = 0; i<size; i++){
//        if(find(table,i)){
//
//        }else{
//            table[myhash(i)] = i;
//        }
//    }

    std::cout << "AVERAGE COLLISIONS: " << median / size << endl;
    std::cout << "HIGHEST COLLISION COUNT " << counter << std::endl;
    return 0;
}
