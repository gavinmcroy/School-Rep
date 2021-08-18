#include <iostream>
#include <vector>


void duplicateZeros(std::vector<int> &arr);

int main() {
    std::vector<int> testInput = {1, 0, 2, 3, 3, 4, 5, 1};
    //[1,0,0,2,3,0,0,4]
    duplicateZeros(testInput);
    return 0;
}

void duplicateZeros(std::vector<int> &arr) {
    //insert,push all elements forward, remove excessive.
    for (int i = 0; i < arr.size(); i++) {
        //---We found our 0
        if (arr[i] == 0) {
//            if (j + 1 == arr.size()) {
//                break;
//            }
            int temp = 0;
            int temp2 = 0;
            for (int j = 0; j < arr.size() - i; j++) {
                //---current
                //---Variable one ahead
                temp = arr[i+j+1];
                temp2 = arr[i+j+2];

                arr[i+j+1] = arr[i+j];
                arr[i+j+2] = temp;
            }

            //---Special case for when we exceed array bounds
//            if (j + 1 == arr.size()) {
//                break;
//            }
            //---take every element at j+1 and copy
        }

    }
    for(int i = 0; i < arr.size(); i++){
        std::cout<<arr[i]<<" ";
    }
}


//---Out of place operation
//void duplicateZeros(std::vector<int> &arr) {
//    std::vector<int> newVec;
//    for (int i = 0; i < arr.size(); i++) {
//        if (newVec.size() == arr.size()) {
//            break;
//        }
//        if (arr[i] == 0) {
//            newVec.push_back(arr[i]);
//            newVec.push_back(arr[i]);
//        } else {
//            newVec.push_back(arr[i]);
//        }
//    }
//    std::cout << "[";
//    for (int i = 0; i < newVec.size(); i++) {
//        if (i == newVec.size() - 1) {
//            std::cout << newVec[i];
//        } else {
//            std::cout << newVec[i] << ",";
//        }
//
//    }
//    std::cout << "]";
//}