#include <iostream>
#include <vector>
using namespace std;
vector <int> vec1;
vector <int> vec2;
vector <vector<int> > vec2d;
int a = 0;
int main(){
        cout<<"Vector 1"<<endl;
        vec1.push_back(10);
        vec1.push_back(20);
        cout<<vec1.at(0)<<endl;
        cout<<vec1.at(1)<<endl;
        cout<<"Vector 1 Size "<<vec1.size()<<endl;

        cout<<"Vector 2"<<endl;
        vec2.push_back(100);
        vec2.push_back(200);
        cout<<vec2.at(0)<<endl;
        cout<<vec2.at(1)<<endl;
        cout<<"Vector 2 Size "<<vec2.size()<<endl;

        cout<<"2D Vector"<<endl;
        vec2d.push_back(vec1);
        vec2d.push_back(vec2);
        cout<<vec2d.at(0).at(0)<<" "<<vec2d.at(0).at(1)<<endl;
        cout<<vec2d.at(1).at(0)<<" "<<vec2d.at(1).at(1)<<endl;

        cout<<"2D Vector Change "<<endl;
        vec1.at(0)=1000;
        cout<<vec2d.at(0).at(0)<<" "<<vec2d.at(0).at(1)<<endl;
        cout<<vec2d.at(1).at(0)<<" "<<vec2d.at(1).at(1)<<endl;

        cout<<"Vec 1 Change"<<endl;
        cout<<vec1.at(0)<<endl;
        cout<<vec1.at(1)<<endl;

        return 0;
}
