#include <iostream>
#include <vector>

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n);

int main() {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    return 0;
}

//[1,2,3,0,0,0], m = 3, nums2 = [2,5,6]
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    /* We are merging nums2 into nums1 */
    for (int i = 0; i < m; i++) {
        bool noneGreater = false;
        /* if the first element is the smallest none can come in front*/
        for (int j = 0; j < n; j++) {
            if (nums1[i] > nums2[j]) {
                int temp = nums1[i];
                nums1[i] = nums2[j];
                nums1[i + 1] = temp;
                noneGreater = true;
            }else{
                if(!noneGreater){
                    
                }
            }
        }
    }
    for (int x : nums1) {
        std::cout << x << " ";
    }
}