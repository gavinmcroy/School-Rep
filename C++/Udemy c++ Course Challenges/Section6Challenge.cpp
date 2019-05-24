#include <iostream>
using  namespace std;

int main (){
        const double salesTax = {0.06};
        const int smallRoomPrice {25};
        const int bigRoomPrice {35};
        int smallRoom {0};
        int bigRoom {0};
        cout<<"Welcome to Gavins Carpet Service! "<<endl;
        cout<<"The price  is $"<<smallRoomPrice<<" for small and $"<<bigRoomPrice<< " for big rooms"<<endl;
        cout<<"How many small rooms would you like? "<<endl;
        cin>>smallRoom;
        cout<<"How many Big rooms would you like? "<<endl;
        cin>>bigRoom;
        cout<<"Total Tax: $"<<((smallRoomPrice*smallRoom)+(bigRoomPrice*bigRoom)) *salesTax<<endl;
        cout<<"Total Price: $"<<(((smallRoomPrice*smallRoom)+(bigRoomPrice*bigRoom)) *salesTax+(smallRoomPrice*smallRoom)+(bigRoomPrice*bigRoom));
        return 0;
}
