#include <iostream>
#include "structs/Airlines.h"
#include "structs/Airports.h"
#include "structs/Flights.h"

int main() {
    std::cout << "Start reading files \n";

    setAirlines setAirlines;
    setAirlines.readLines();
    auto it_1 = setAirlines.setAirlines.find(Airlines("KLM"));

    setAirports setAirports;
    setAirports.readLines();
    auto it_2 = setAirports.setAirports.find(Airports("CDG"));

    Flights flights;
    flights.ReadLines();

    std::cout << "Finished the task of reading files \n";

    int res = flights.getFlightsPerCity(setAirports, "Paris");
    std::cout << res << "\n";

    return 0;
}
