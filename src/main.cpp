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

    auto src = flights.flights.findVertex(Airports("PDL"));
    auto dest = flights.flights.findVertex(Airports("THU"));

    int num = 0;

    auto res = flights._11AllBestPathEntreDoisAeroportos(src, dest);
    auto teste = flights._11FilterMinimizer(res, num);

    //Menu::Terminal(flights, hashAirports, hashAirlines);
    return 0;
}
