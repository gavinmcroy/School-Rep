//
// Created by Gavin Taylor Mcroy on 2/11/2020 AD.
//

#include<string>
#include <utility>
#include<iostream>
#include<iomanip>

#ifndef LAB05_CAR_H
#define LAB05_CAR_H


class Car {

private:
    std::string make;
    std::string model;
    int year;
    double price;
public:
    Car() {

    }

    ~Car() {
        std::cout << "Objected Destroyed" << std::endl;
    }

    void setMake(std::string carMake) {
        make = std::move(carMake);
    }

    void setModel(std::string carModel) {
        model = std::move(carModel);
    }

    void setYear(int carYear) {
        year = carYear;
    }

    void setPrice(double carPrice) {
        price = carPrice;
    }

    std::string getMake() {
        return make;
    }

    std::string getModel() {
        return model;
    }

    int getYear() {
        return year;
    }

    double getPrice() {
        return price;
    }

    void printCarInfo() {
        std::cout << std::setw(7) << "Make: " << std::setw(10) << make << std::endl;
        std::cout << std::setw(7) << "Model: " << std::setw(10) << model << std::endl;
        std::cout << std::setw(7) << "Year: " << std::setw(10) << year << std::endl;
        std::cout << std::setw(7) << "Price: " << std::setw(10) << std::fixed << std::setprecision(2) << price
                  << std::endl;
    }

    bool isClassic() {
        return 2020 - year >= 30;
    }

};


#endif //LAB05_CAR_H
