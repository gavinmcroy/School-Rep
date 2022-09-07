#include <iostream>
#include <cstdlib>

using namespace std;

int get_rand(int N) {
    // I forgot to attend the lecture where Prof Dean. explained how to generate
    // random numbers well, so hopefully this will work ok...
    // It looks like get_rand(N) always returns the same number if you call
    // it multiple times with the same value of N, but how could someone
    // possibly exploit that to make quicksort run slowly...
    return 123456789 % N;
}

// Partition A about a randomly chosen pivot and return the index
// of the pivot in the resulting array
int partition(int *A, int len) {
    int pivot = get_rand(len);

    // Forgot how to partition in-place, so I'm going to just allocate
    // a temporary buffer for now...
    int *temp = new int[len];
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (A[i] < A[pivot]) {
            temp[j++] = A[i]; // copy elements smaller than pivot
        }
    }

    int where_pivot_first = j; // remember where the pivot is going...
    for (int i = 0; i < len; i++) {
        if (A[i] == A[pivot]) {
            temp[j++] = A[i]; // copy elements equal to pivot
        }
    }

    int where_pivot_last = j - 1;
    for (int i = 0; i < len; i++) {
        if (A[i] > A[pivot]) {
            temp[j++] = A[i]; // copy elements larger than pivot
        }

    }
    // Now put copy temp back into A
    for (int i = 0; i < len; i++) {
        A[i] = temp[i];
    }
    delete[] temp;

    // return average position of elements equal to pivot, so that
    // cases with many equal elements don't give unbalanced partitions
    return (where_pivot_first + where_pivot_last) / 2;
}
int i = 0;
void quicksort(int *A, int len) {
    if (len <= 1) {
        return;
    }
    int p = partition(A, len); // partition

    quicksort(A, p); // sort left side
    quicksort(A + p + 1, len - p - 1); // sort right side
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
    int * A = new int[N];
    cout << N << "\n";
//    for (int i = 0; i < N; i++) {
//        //cout<<i<<endl;
//        A[i] = i;
//        //cout<<i<<endl;
//    }
    int i = 1;
    long long val = 1;
    while(true){
        if(get_rand(val)==i){
            cout<<val<<endl;
            i++;
        }
        if(val==100-000-000-000){
            break;
        }
        val++;
    }
    quicksort(A,N);

    
    return 0;
}
