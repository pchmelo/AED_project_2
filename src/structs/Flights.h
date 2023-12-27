//
// Created by pchmelo on 25-12-2023.
//

#ifndef PROJECT_2_FLIGHTS_H
#define PROJECT_2_FLIGHTS_H

#include "string"
#include "Graph.h"
#include "Airlines.h"
#include "Airports.h"

class HashAirports;
class HashAirlines;

class Flights {
    public:
        Graph<string> flights;
        void ReadLines();

        //1
        int _1numViajens();

        //2
        int _2numViajensDeAirport(string code);
        int _2numViajensDeAirlines(string code);

        //3
        int _3getFlightsPerCountry(HashAirports hashAirports, string country);
        int _3getFlightsPerCity(HashAirports hashAirports, string city);
        int _3getFlightsPerCompany(HashAirlines hashAirlines, string airline);

        //4
        vector<string> _4getVecCountriesAirport(string code, HashAirports hashAirports);
        vector<string> _4getVecCountriesCity(string city, HashAirports hashAirports);
        vector<string> _4getVecCountriesCountry(string country, HashAirports hashAirports);

        int _4getNumCountriesAirport(string code, HashAirports hashAirports);
        int _4getNumCountriesCity(string city, HashAirports hashAirports);
        int _4getNumCountriesCountry(string country, HashAirports hashAirports);

        //5
        int Airports_per_airport(string code);
        int air_per_air_aux(Vertex<string>*v);

        int Cities_per_airport(string code, HashAirports hashAirports);
        int cit_per_air_aux(Vertex<string> *v, list<string> &cities, HashAirports hashAirports);

        int Countries_per_airport(string code, HashAirports hashAirports);
        int count_per_air_aux(Vertex<string> *v, list<string> countries, HashAirports hashAirports);
        //6
        //7
        //8
        //9

};

#endif //PROJECT_2_FLIGHTS_H
