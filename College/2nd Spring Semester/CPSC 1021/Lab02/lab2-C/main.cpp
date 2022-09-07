#include <iostream>
#include "stddev.h"

using namespace std;

int main() {

    int size = 4;

    cout << "Please enter your given number: "<< endl;
    cin >> size;

    float* array = new float(size);
    float add = 4;

    for(int i = 0; i<size; i++){
        //cout<<"Enter nums"<<endl;
        //cin>>array[i];
        array[i] = add;
        add+=4;

    }

    stats(array,size);


    delete(array);

    return 0;
}