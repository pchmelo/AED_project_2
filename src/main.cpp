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

    res = flights._1numViajens();
    std::cout << res << "\n";

    std::cout << "------------------------" << "\n";
/*
    vector<string> vector1 = flights._4getVecCountriesAirport("OPO", hashAirports);
    for(auto s : vector1){
        cout << s << "\n";
    }

    std::cout << "------------------------" << "\n";
*/
    res = flights._4getNumCountriesAirport("ORY", hashAirports);
    std::cout << res << "\n";

    std::cout << "------------------------" << "\n";

    res = flights._4getNumCountriesAirport("CDG", hashAirports);
    std::cout << res << "\n";

    std::cout << "------------------------" << "\n";
/*
    vector1 = flights._4getVecCountriesCity("Paris", hashAirports);
    for(auto s : vector1){
        cout << s << "\n";
    }
    std::cout << "------------------------" << "\n";
*/

    res = flights._4getNumCountriesCity("Paris", hashAirports);
    std::cout << res << "\n";

    std::cout << "------------------------" << "\n";

    res = flights._4getNumCountriesCountry("Portugal", hashAirports);
    std::cout << res << "\n";

/*
    std::cout << "------------------------" << "\n";
    vector<string> vector1 = flights._6getVecStopsAirports("CDG", 3, hashAirports);
    for(auto s : vector1){
        cout << s << "\n";
    }
*/
    std::cout << "------------------------" << "\n";
    res = flights._6getIntStopsAirports("CDG", 3, hashAirports);
    std::cout << res << "\n";

    std::cout << "------------------------" << "\n";
    res = flights._6getIntStopsCities("CDG", 3, hashAirports);
    std::cout << res << "\n";

    std::cout << "------------------------" << "\n";
    res = flights._6getIntStopsCountries("CDG", 3, hashAirports);
    std::cout << res << "\n";

    //vector<AirportsTrafic> t = flights._8getTopVecDescAirports(hashAirports);

    auto res_1 = flights._7getAirportsGreat(hashAirports);

    return 0;
}
