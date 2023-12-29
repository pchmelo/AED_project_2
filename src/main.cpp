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

    /*
    auto scr = flights.flights.findVertex(Airports("THU"));
    auto dest = flights.flights.findVertex(Airports("CDG"));

    int num = 0;
    auto res = flights._11AllBestPathEntreDoisAeroportos(scr, dest);
    auto t = flights._11Separator(res);
    auto fim = flights._11FilterMinimizer(res, num);
    */

    Menu::Terminal(flights, hashAirports, hashAirlines);
    return 0;
}
