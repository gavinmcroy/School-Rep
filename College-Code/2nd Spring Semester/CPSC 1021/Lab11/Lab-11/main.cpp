#include<vector>
#include<memory>
#include "Animal.h"
#include "Monkey.h"
#include "Tiger.h"

int main() {
    std::vector<std::unique_ptr<Animal>> animals;

    animals.push_back(std::make_unique<Monkey>(10, 20, "Monkey", "Screech"));
    animals.push_back(std::make_unique<Monkey>(15, 30, "Monkey", "Screeeeech"));
    animals.push_back(std::make_unique<Tiger>(20, 40, "Tiger", "Roar"));
    animals.push_back(std::make_unique<Tiger>(30, 50, "Tiger", "Roaaaaar"));

    std::vector<std::unique_ptr<Animal>>::iterator iter;
    for (iter = animals.begin(); iter != animals.end(); iter++) {
        iter->get()->printInfo();
    }
    return 0;
}
