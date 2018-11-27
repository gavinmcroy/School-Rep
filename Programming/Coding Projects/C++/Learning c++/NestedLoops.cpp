#include<iostream>
using namespace std;

int main(){
    //---Displays multiplication table for 10 seperated by space 
    for(int i {1}; i<=10;i++){
        for(int j{1}; j<=10;j++){
            cout<<i<<" * "<<j<<" = "<<i*j<<endl;
        }
        cout<<"-----------------------------------------"<<endl;
    }
    return 0;
}