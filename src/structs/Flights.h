//
// Created by pchmelo on 25-12-2023.
//

#ifndef PROJECT_2_FLIGHTS_H
#define PROJECT_2_FLIGHTS_H

#include "list"
#include "string"
#include "Graph.h"
#include "Airlines.h"
#include "Airports.h"

class Airports;
class HashAirports;
class HashAirlines;
struct AirportsGreatDistance;
struct AirportsTrafic;
struct AirportStop;

class Flights {
    public:
        Graph<string> flights;
        void ReadLines();

        //3.1
        int _1numViajens();

        //3.2
        int _2numViajensDeAirport(string code);
        int _2numViajensDeAirlines(string code);

        //3.3
        int _3getFlightsPerCountry(HashAirports hashAirports, string country);
        int _3getFlightsPerCity(HashAirports hashAirports, string city);
        int _3getFlightsPerCompany(HashAirlines hashAirlines, string airline);

        //3.4
        vector<string> _4getVecCountriesAirport(string code, HashAirports hashAirports);
        vector<string> _4getVecCountriesCity(string city, HashAirports hashAirports);
        vector<string> _4getVecCountriesCountry(string country, HashAirports hashAirports);

        int _4getNumCountriesAirport(string code, HashAirports hashAirports);
        int _4getNumCountriesCity(string city, HashAirports hashAirports);
        int _4getNumCountriesCountry(string country, HashAirports hashAirports);

        //3.5
        int Airports_per_airport(string code);
        int air_per_air_aux(Vertex<string>*v);

        int Cities_per_airport(string code, HashAirports hashAirports);
        int cit_per_air_aux(Vertex<string> *v, list<string> &cities, HashAirports hashAirports);

        int Countries_per_airport(string code, HashAirports hashAirports);
        int count_per_air_aux(Vertex<string> *v, list<string> countries, HashAirports hashAirports);

        //3.6
        vector<string> _6getVecStopsAirports(string code, int x, HashAirports hashAirports);
        vector<string> _6getVecStopsCities(string code, int x, HashAirports hashAirports);
        vector<string> _6getVecStopsCountries(string code, int x, HashAirports hashAirports);

        int _6getIntStopsAirports(string code, int x, HashAirports hashAirports);
        int _6getIntStopsCities(string code, int x, HashAirports hashAirports);
        int _6getIntStopsCountries(string code, int x, HashAirports hashAirports);

        //3.7
        list<AirportsGreatDistance> _7getAirportsGreat(HashAirports hashAirports);

        //3.8
        vector<AirportsTrafic> _8getTopVecAirports(HashAirports hashAirports);
        vector<AirportsTrafic> _8getTopVecDescAirports(HashAirports hashAirports);
        vector<AirportsTrafic> _8getTopVecAscAirports(HashAirports hashAirports);

        //3.9
        set<string> _9Articulations(HashAirports hashAirports);
        void _9Auxiliar(Vertex<string>* vertex, stack<Vertex<string>*> &s, set<string> &res, int &i, HashAirports hashAirports, set<Vertex<string>*> &inS, bool first);
        int _9numArticulations(HashAirports hashAirports);

        //4.1
        list<AirportStop> _10BestPathEntreDoisAeroportos(Vertex<string>* src, Vertex<string>* dest, HashAirports hashAirports, HashAirlines hashAirlines);
};

#endif //PROJECT_2_FLIGHTS_H
