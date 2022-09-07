#include "stddev.h"
#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    float *data = new float[n];

    for (int i = 0; i < n; i++) {
        data[i] = (i + 1) * 4;
        //cout << "data: " << data[i] << endl;
    }




    // declare three Stats pointers below named mean, variance, and stdev
    Stats *mean = new Stats();
    Stats *variance = new Stats();
    Stats *stdev = new Stats();
    // and allocate memory for each of the using malloc, calloc or new





    // calling function construct to calculate the mean
    construct(mean, data, n, calMean);


    // print the mean below this comment
    cout << "mean: "<<mean->stat << endl;


    // calling function construct to calculate the variance
    construct(variance, data, n, calVariance);


    // print the variance below this comment
    cout << "variance: "<<variance->stat << endl;

    // calling function construct to calculate the stdev
    construct(stdev, data, n, calStdev);


    // print the variance below this comment
    cout << "stddev: "<<stdev->stat << endl;


    // calling function output with min and max
    outPut(mean, variance, stdev, min);
    outPut(mean, variance, stdev, max);

    // free memory that you have allocated above for the three pointers to Stats here
    delete mean;
    delete variance;
    delete stdev;
}
