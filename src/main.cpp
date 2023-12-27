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

    int res = flights._1numViajens();
    cout << res << "\n";

    res = hashAirports._1numAirports();
    cout << res << "\n";

    res = flights._2numViajensDeAirlines("CDG");
    cout << res << "\n";

    res = flights._2numViajensDeAirport("CDG");
    cout << res << "\n";

    res = flights._3getFlightsPerCompany(hashAirlines, "CDG");
    cout << res << "\n";

    res = flights._3getFlightsPerCity(hashAirports, "Kabul");
    cout << res << "\n";

    res = flights._3getFlightsPerCountry(hashAirports, "Portugal");
    cout << res << "\n";

    res = flights._4getNumCountriesAirport("CDG", hashAirports);
    cout << res << "\n";

    res = flights._4getNumCountriesCity("Paris", hashAirports);
    cout << res << "\n";

    res = flights._4getNumCountriesCountry("Portugal", hashAirports);
    cout << res << "\n";

    res = flights._6getIntStopsAirports("THU", 4, hashAirports);
    cout << res << "\n";

    res = flights._6getIntStopsCities("THU", 4, hashAirports);
    cout << res << "\n";

    res = flights._6getIntStopsCountries("CGD", 3, hashAirports);
    cout << res << "\n";

 //   auto l = flights._8getTopVecDescAirports(hashAirports);

    cout << "-------------------------" << "\n";
    res = flights._9numArticulations(hashAirports);
    cout << res << "\n";

    /*
    set<string> s = flights._9Articulations(hashAirports);

    for(auto air : s){
        cout << air << "\n";
    }
     */

    return 0;
}
