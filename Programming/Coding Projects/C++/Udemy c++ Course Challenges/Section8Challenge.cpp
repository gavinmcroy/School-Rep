#include<iostream>
using namespace std;

int main(){
    //---Takes cents - all coin values / current coin value
    int cents = 0;
    cout<<"Enter an amount to convert into coins"<<endl;
    cin>>cents; 
    int dollar = cents / 100; 
    cout<<"Dollar: "<<dollar<<endl;
    int quarter = (cents-(dollar*100))/25;
    cout<<"Quarter: "<<quarter<<endl;
    int dime = (cents - (dollar*100+quarter* 25) )/10;
    cout<<"Dime: "<<dime<<endl;
    int nickle = (cents - (dollar*100+quarter*25+dime*10))/5;
    cout<<"Nickle: "<<nickle<<endl;
    int penny = (cents -(dollar*100+quarter*25+dime*10+nickle*5)) / 1;
    cout<<"Penny: "<<penny<<endl;
    system("PAUSE");
    return 0 ;
}