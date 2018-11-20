#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;



int main(){
    vector <double> temps {87.2,77.9,80.0,72.5}; 
    double averageTemp {0}; 
    double runningSum {0};
    int scores[] {10,20,30}; 

    for(int score : scores)
        cout<<score<<endl;

    for (auto temp : temps)
       runningSum += temp; 
    
    for (auto c : "Gavin")
        cout<<c<<endl;
    
    averageTemp = runningSum / temps.size();
    //---IO MANIP Rounds it to 1 decimal 
    cout<<fixed<<setprecision(1); 
    cout<<averageTemp<<endl;
    
    int number = 1'000'000;
    cout<<number<<endl;

    cout<<__cplusplus<<endl;

    return 0 ;

}