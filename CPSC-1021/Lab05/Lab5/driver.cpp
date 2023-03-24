#include <iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include "car.h"


using namespace std;

int main() {

    ifstream in_file("raw.data");

    string tmp;
    string make;
    string model;
    int year;
    double price;

    Car car[5];
    int i = 0;
    while (getline(in_file, tmp)) {
        istringstream iss(tmp);
        if (!(iss >> year >> make >> model >> price)) {
            break;
        }
        car[i].setYear(year);
        car[i].setMake(make);
        car[i].setModel(model);
        car[i].setPrice(price);
        i++;
    }

    ofstream out_file;
    out_file.open("formatted.data", std::ios_base::app);
    for (int y = 0; y < 5; y++) {
        out_file << setw(10) << "Car " << y + 1 << ":" << endl;
        out_file << left << setw(7) << "Make: " << right << setw(10) << car[y].getMake() << endl;
        out_file << left << setw(7) << "Model: " << right << setw(10) << car[y].getModel() << endl;
        if (car[y].isClassic()) {
            out_file << left << setw(7) << "Year: " << right << setw(10) << car[y].getYear() << "(Classic)" << endl;
        } else {
            out_file << left << setw(7) << "Year: " << right << setw(10) << car[y].getYear() << endl;
        }
        int tmp2 = static_cast<int> (car[y].getPrice());
        string tmp1 = to_string(tmp2);
        tmp1.insert(0, "$");
        if (car[y].getPrice() > 100000) {
            tmp1.insert(4, ",");
            tmp1.append(".00");
            //out_file << left << setw(7) << "Price:" << right << setw(1) << "$" << fixed << car[y].getPrice() << endl;
            out_file << left << setw(6) << "Price:" << right << setw(11) << tmp1 << endl;
        } else {
            //  out_file << left << setw(7) << "Price:" << right << setw(2) << "$" << fixed << setprecision(2) << car[y].getPrice() << endl;
            tmp1.insert(3, ",");
            tmp1.append(".00");
            out_file << left << setw(7) << "Price:" << right << setw(10) << tmp1 << endl;
        }
        out_file << endl;
    }
    //car[3].printCarInfo();

    out_file.close();

    return 0;
}
