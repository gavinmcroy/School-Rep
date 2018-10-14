//Local And Global Variables
#include <iostream>

using namespace std;
int globalVariable;

int main(){
        int nr,result =0;
        int i = 0;

        for(; i<3; i++) {

                cout<< "Enter " << (i + 1) << " Number"<<endl;
                cin>>nr;
                result +=nr;
        }

        cout<<result<<endl;
        cout<<"We Added "<<i<<" Numbers! "<<endl;
        return 0;
}
