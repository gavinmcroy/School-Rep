#include <iostream>
#include <vector>


/* The XOR of the lengths of the longest increasing subsequences of corresponding sub arrays equals 0*/
int main() {
    std::vector<int> myArray;
    int numInput;
    int nums = 0;
    int accumDif = 0;
    std::cin >> numInput;
    while (std::cin >> nums) {
        myArray.push_back(nums);
    }

    int i = 0;
    int previous = myArray[0];
    while (i < myArray.size()) {
        /* Found subsequence */
        if (myArray[i] <= myArray[i + 1]) {
            if(previous == myArray[i]){
                continue;
            }
            std::cout << myArray[i] << " " << myArray[i + 1];
            previous = myArray[i+1];
            i++;
        } else {
            std::cout << " | " << std::endl;
            i++;
        }
    }

    return 0;
}
