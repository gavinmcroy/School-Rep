#include<fstream>
#include<iostream>
#include"pixelArt.h"

void pixelArt::readArts(string fileName)
{
    std::ifstream inFile(fileName,std::ios::in);
    if(inFile){
        std::cout<<"File opened"<<std::endl;
    }else{
        std::cout<<"File open error"<<std::endl;
    }
    int row = 70;
    //int column = 16;
    char tmp;
    int i = 1;
    vector<int> v1;
    while(inFile>>tmp){
        //int test;
        if(tmp=='0'){
            //---char to int conversion
            v1.push_back(tmp-'0');
           // std::cout<<test;
        } else{
            int q = ' ';
            v1.push_back(' ');
            //std::cout<<(char)q;
           // std::cout<<" ";
        }
        if(i%row==0){
            v1.push_back('\n');
            pixels.push_back(v1);
            v1.clear();
        }
        i++;
    }
}

pixelArt::pixelArt(int iw, int ih):w(iw),h(ih)
{

}

int pixelArt::getPixel(int i, int j)
{

}

int pixelArt::getW()
{
    return w;
}

int pixelArt::getH()
{
    return h;
}


pixelArt pixelArt::operator + (int num)
{

}

pixelArt pixelArt::operator - (int num)
{

}

pixelArt pixelArt::operator + (const pixelArt& pa)
{

}

ostream& operator<<(ostream& os, const pixelArt& pa)
{

}
