#include "TaxiServices.h"
#include <string>

int main() {
    std::string places = "places.txt";
    std::string transit = "transit.txt";


    TaxiServices taxiServices(places,transit);
    taxiServices.determineShortestPath();
}
