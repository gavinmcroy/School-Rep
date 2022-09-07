#include <iostream>
#include "stddev.h"

using namespace std;

int main() {

    int size = 0;

    cout << "Please enter your given number: "<< endl;
    cin >> size;

    float* array = new float(size);
    float add = 0.0;

    //Add four to array 4 , 8 , 12...
    for(int i = 0; i<size; i++){
        array[i] = add;
        add+=4;

    }

    stats(array,size);


    delete(array);

    return 0;
}
