#include<iostream>
#include<cmath>

using std::pow;


// create a struct Stats below this comment
typedef struct Stats {
    float stat;

    float (*funPtr)(float *, int);
} Stats;
// struct members are a float variable and a pointer that can point to  
// calMean, calVariance, or calStdev finctions below





float calMean(float *data, int n);

float calVariance(float *data, int n);

float calStdev(float *data, int n);

void max(Stats *s1, Stats *s2, Stats *s3);

void min(Stats *s1, Stats *s2, Stats *s3);


// add the prototype for function "construct" under this comment
// return type: float
// incoming parameters: a Struct pointer, a float, an int, and a pointer
// that can point to calMean, calVariance, or calStdev functions above
float construct(Stats *stats, float *data, int n, float(*funPtr)(float *, int));


// add the prototype for function "output" under this comment
// return type: void
// incoming parameters: three Stats pointers, and a pointer that can point 
// to either min or max functions declared above
void outPut(Stats *stat1, Stats *stat2, Stats *stat3, void (*funPtr)(Stats *, Stats *, Stats *));






