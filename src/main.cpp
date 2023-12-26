#include <iostream>
#include "structs/Airlines.h"
#include "structs/Airports.h"
#include "structs/Flights.h"

int main() {
    Flights flights;

    HashAirlines hashAirlines;
    hashAirlines.readLines();
    auto it_1 = hashAirlines.airlinesTable.find(Airlines("KLM"));

    HashAirports hashAirports;
    hashAirports.readLines(flights);
    auto it_2 = hashAirports.airportTable.find(Airports("CDG"));

    flights.ReadLines();

    int res = flights._3getFlightsPerCountry(hashAirports, "Afghanistan");
    std::cout << res << "\n";

    res = flights._2numViajensDeAirlines("OPO");
    std::cout << res << "\n";

    res = hashAirports._1numAirports();
    std::cout << res << "\n";

    return 0;
}
