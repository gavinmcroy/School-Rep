#include<vector>
#include<memory>
#include "Animal.h"
#include "Monkey.h"
#include "Tiger.h"

int main() {
    std::vector<std::unique_ptr<Animal>> animals;

    animals.push_back(std::make_unique<Monkey>(10, 20, "Monkey", "Screech"));
    animals.push_back(std::make_unique<Animal>(100, 150));
    animals.push_back(std::make_unique<Tiger>(20, 40, "Tiger", "Roar"));

    for (int i = 0; i < animals.size(); i++) {
        animals.at(i)->printInfo();
    }
    return 0;
}
