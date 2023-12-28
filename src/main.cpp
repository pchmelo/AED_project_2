#include <iostream>
#include "structs/Airlines.h"
#include "structs/Airports.h"
#include "structs/Flights.h"
#include "Menu.h"

int main() {
    Flights flights;

    HashAirlines hashAirlines;
    hashAirlines.readLines();

    HashAirports hashAirports;
    hashAirports.readLines(flights);

    flights.ReadLines(hashAirlines, hashAirports);

    auto src = flights.flights.findVertex(Airports("THU"));
    auto dest = flights.flights.findVertex(Airports("CDG"));

    auto res = flights._10AllBestPathEntreDoisAeroportos(src, dest);

    //Menu::Terminal(flights, hashAirports, hashAirlines);
    return 0;
}
