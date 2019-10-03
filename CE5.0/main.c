#include <stdio.h>
#include<stdbool.h>

int main() {

    bool extra = false;
    int alpha[50];
    int length = sizeof(alpha) / sizeof(int);
    int count = 1;

    for (int i = 0; i < length; i++) {
        alpha[i] = i;
    }
    printf("The first array element: alpha[0] = %d\n", alpha[0]);
    printf("The last array element: alpha[49] = %d\n", alpha[49]);
    alpha[24] = 62;
    printf("The 25th array element: alpha[24] = %d\n", alpha[24]);
    alpha[9] = 3 * alpha[49] + 10;
    printf("The 10th array element: alpha[9] = %d\n", alpha[9]);

    for (int i = 0; i < length; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }
        printf("%d ", alpha[i]);
    }
    printf("\n");

    for (int i = 0; i < length; i++) {
        if (i % 3 == 0 || i % 2 == 0) {
            printf("alpha[%d] = %d\n", i, alpha[i]);
        }
    }
    printf("\n");

    for (int i = 1; i < length; i += 2) {
        printf("%d- ", alpha[i]);
        if (count % 5 == 0) {
            printf("\n");
            //printf("%d ",alpha[i]);
            count =1;
            extra = true;
        }else if(extra){
            
        }
        else {
            printf("%d+ ", alpha[i]);
            count += 2;
        }
    }
    return 0;
}