#include<iostream>
#include<vector>
using namespace std;

int main(){
    char userInput {}; 
    vector <int> userStorage {10,3,4,5,6,7,2,9,9,9}; 
    do{
    cout<<"P - Print Numbers"<<endl;
    cout<<"A - Add a Number"<<endl;
    cout<<"M - Display Mean of Numbers"<<endl;
    cout<<"S - Display Smallest Number"<<endl;
    cout<<"L - Print Largest Number"<<endl;
    cout<<"C - Clear Vector"<<endl;
    cout<<"F - Find Number "<<endl;
    cout<<"Q - Quit"<<endl;
    cin>>userInput;
    //---system("cls");  
    //---Print Numbers
    if(userInput=='P'|| userInput=='p'){
        if(userStorage.size()==0){
            cout<<"The list is empty"<<endl;
        }else{
            for(auto i: userStorage)
            cout<<i<<endl;
        }
    //---Add a number
    } else if(userInput=='A'|| userInput=='a'){
        bool dataIsNonDuplicate = true;
        int tempInput{0};
        cout<<"Enter the number you would like to add "<<endl;
        cin>>tempInput;
        for(int i {}; i<userStorage.size();i++){
            if(tempInput==userStorage.at(i)){
                cout<<"Error Duplicated Data Type"<<endl;
                dataIsNonDuplicate = false; 
            }
        }
        if(dataIsNonDuplicate){
            userStorage.push_back(tempInput); 
            cout<<tempInput<<" Has been added! "<<endl;
        }
    //---Display Mean of Numbers
    }else if(userInput=='M'|| userInput=='m'){
        int mean {0};
        if(userStorage.size()==0){
            cout<<"Error cannot Calculate Mean. No data "<<endl;
        }else {
            for(auto m : userStorage){
                mean+=m; 
            }
            mean = mean/userStorage.size();
            cout<<"The mean of the data is "<<mean<<endl;
        }
    //---Display Smallest Number  
    }else if(userInput=='S'|| userInput=='s'){
        int smallestData=userStorage.at(0); 
        if(userStorage.size()==0){
            cout<<"Error cannot Calculate Smallest Number. No data "<<endl;
        }else{
            for(int i {0};i<userStorage.size();i++){
                if(smallestData>userStorage.at(i)){
                    smallestData=userStorage.at(i);
                }
            }
            cout<<smallestData<<endl;
        }
    }else if(userInput=='L'|| userInput=='l'){
        int largestData=userStorage.at(0); 
        if(userStorage.size()==0){
            cout<<"Error Cannot Calculate Largest Number. No data "<<endl;
        }else{
            for(int i {0};i<userStorage.size();i++){
                if(largestData<userStorage.at(i)){
                    largestData=userStorage.at(i);
                }
            }
            cout<<largestData<<endl;
        }
    }
    else if(userInput=='C'|| userInput=='c'){
        userStorage.clear();
    }
    else if(userInput=='F'|| userInput=='f'){
        int userSearch {};
        int duplicate {};
        cout<<"Enter the number you want to search for "<<endl;
        cin>>userSearch; 
        for(int i {} ; i<userStorage.size();i++){
            if(userSearch==userStorage.at(i)){
                duplicate++; 
            }
        }
        cout<<"Found a total of "<<duplicate<<" instances"<<endl;
    }
    else if(userInput=='Q'|| userInput=='q'){
        return 0;
    }else{
        cout<<"Enter a valid input "<<endl;
    }
}while(userInput!='Q'||userInput!='q'); 
}