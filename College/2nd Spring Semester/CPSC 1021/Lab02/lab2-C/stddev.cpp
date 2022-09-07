#include "stddev.h"
#include<cmath>
#include<iostream>

using namespace std;

void stats(float *data, int n) {
    /*
     * Find mean average by dividing sum of all elements
     * of the array by the number of elements
     *
     * then for each of the N number in the array substract
     * the mean from the number and square the result
     *
     * calculate the mean of the squared differences
     *
     * calculate the square root of the previous computation
     *
     */
    float sum = 0;

    //---Work out mean
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }

    float mean = sum / (float) n;



    //---For each number substract mean square result
    for (int i = 0; i < n; i++) {
        data[i] = pow(data[i] - mean, 2);
    }

    cout<<data[1]<<endl;

    sum = 0;
    //---Work out mean of squared differences
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }


    mean = sum / n;
    //---Take the square root of that
    float final = sqrt(mean);
    cout << "Your Standard Deviation is : " << final << endl;
}