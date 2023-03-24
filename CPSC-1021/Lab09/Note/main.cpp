#include<iostream>
#include<string>
#include<sstream>

using namespace std;


int main(){
    string t = "#a #b #c";
    stringstream s(t);
    string token;
    while(getline(s,token,'#')){
                  cout<<token<<endl;
    }
    t = "a b c";
    cout<<"--------------"<<endl;
    size_t pos = t.find(" ");
    cout<<t.substr(0,pos);
    cout<<endl;
    cout<<t.substr(pos,t.length()-1)<<endl;
                  
    return 0;
}
