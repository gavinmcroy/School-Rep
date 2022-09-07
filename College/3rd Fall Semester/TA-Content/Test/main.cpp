#include <iostream>
#include <string.h>

bool isNumber(char *s){
    for(int i =0; strlen(s);i++){
        if(!isdigit(char[i])){
            return false;
        }
    }
    return true;
}

int main() {
     char myString[20] = "Hello";
     int x = strlen(myString);
    int myVal;
    
    scanf("%s",myString);
    while(!isNumber(myString))){
        //---continue
        printf("Enter a number");
        scanf("%s",myString);
        //myVal = atoi(myString);
    }
    myVal = atoi(myString);
    
//    for(int i= 10; i>2; i--){
//        std::cout<<i<<std::endl;
//    }
    
    std::cout << "Hello, World!" << std::endl;
    //isdigit()
    int num;
    scanf("%d",&num);
    x = num;
    for(int i = 10; i>=2; i++){
        while(num>0){
            int remainder = num%i;
            num = num/i;
            sum+=remainder;
        }
        printf("Sum of digits");
        sumArray[i] = sum;
        num = x;
        sum = 0;
    }
    return 0;
}
