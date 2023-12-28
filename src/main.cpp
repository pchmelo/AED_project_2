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


    int res = flights._1numViajens();
    cout << res << "\n";

    res = hashAirports._1numAirports();
    cout << res << "\n";

    res = flights._2numViajensDeAirlines("CDG");
    cout << res << "\n";

    res = flights._2numViajensDeAirport("CDG");
    cout << res << "\n";

    res = flights._3getFlightsPerCompany( "CDG");
    cout << res << "\n";

    //pode estar mal
    res = flights._3getFlightsPerCity( "Kabul", "Afghanistan");
    cout << res << "\n";
//here fica lento
    res = flights._3getFlightsPerCountry( "Portugal");
    cout << res << "\n";

    res = flights._4getNumCountriesAirport("CDG");
    cout << res << "\n";

    res = flights._4getNumCountriesCity("Paris", "France");
    cout << res << "\n";

    res = flights._4getNumCountriesCountry("Portugal");
    cout << res << "\n";

    res = flights._6getIntStopsAirports("CDG", 3);
    cout << res << "\n";

    res = flights._6getIntStopsCities("CDG",3, "France");
    cout << res << "\n";

    res = flights._6getIntStopsCountries("CDG", 3);
    cout << res << "\n";

   // auto l = flights._8getTopVecDescAirports();


   std::cout << "------------------------" << "\n";
    res = flights.air_per_air_aux("CDG");
    std::cout << res << "\n";
    res = flights.cit_per_air_aux("CDG");
    std::cout << res << "\n";
    res = flights.count_per_air_aux("CDG");
    std::cout << res << "\n";


    cout << "-------------------------" << "\n";
    res = flights._9numArticulations();
    cout << res << "\n";



    auto foda = flights._10AirportsCity("London", "United Kingdom");

    Menu::Terminal(flights, hashAirports, hashAirlines);
    return 0;
}
