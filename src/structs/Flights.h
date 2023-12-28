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
        Graph<Airports> flights;   //trocar string para airport
        void ReadLines(HashAirlines hashAirlines, HashAirports hashAirports);  //corrigir readlines

        //3.1
        int _1numViajens();

        //3.2
        int _2numViajensDeAirport(string code);
        int _2numViajensDeAirlines(string code);

        //3.3
        int _3getFlightsPerCountry(string country);
        int _3getFlightsPerCity(string city, string country);
        int _3getFlightsPerCompany(string airline);

        //3.4
        vector<Airports> _4getVecCountriesAirport(string code );
        vector<Airports> _4getVecCountriesCity(string city, string country);
        vector<Airports> _4getVecCountriesCountry(string country);

        int _4getNumCountriesAirport(string code);
        int _4getNumCountriesCity(string city, string country);
        int _4getNumCountriesCountry(string country);

        //3.5
        vector<Airports> Airports_per_airport(string code);
        int air_per_air_aux(string code);

        vector<Airports> Cities_per_airport(string code);
        int cit_per_air_aux(string code);

        vector<Airports> Countries_per_airport(string code);
        int count_per_air_aux(string cide);

        //3.6
        vector<Airports> _6getVecStopsAirports(string code, int x );
        vector<Airports> _6getVecStopsCities(string code, int x, string country);
        vector<Airports> _6getVecStopsCountries(string code, int x );

        int _6getIntStopsAirports(string code, int x );
        int _6getIntStopsCities(string code, int x, string country);
        int _6getIntStopsCountries(string code, int x);

        //3.7
        list<AirportsGreatDistance> _7getAirportsGreat();

        //3.8
        vector<AirportsTrafic> _8getTopVecAirports();
        vector<AirportsTrafic> _8getTopVecDescAirports();
        vector<AirportsTrafic> _8getTopVecAscAirports();

        //3.9
        set<Airports> _9Articulations();
        void _9Auxiliar(Vertex<Airports>* vertex, stack<Vertex<Airports>*> &s, set<Airports> &res, int &i, set<Vertex<Airports>*> &inS, bool first);
        int _9numArticulations( );

        //4.all
        list<AirportStop> _10BestPathEntreDoisAeroportos(Vertex<Airports>* src, Vertex<Airports>* dest);
        vector<list<AirportStop>> _10Commander(vector<Vertex<Airports>*> src, vector<Vertex<Airports>*> dest);

        vector<Vertex<Airports>*> _10AirportsCity(string city, string pais);
        vector<Vertex<Airports>*> _10AirportsPais(string pais);

        vector<Vertex<Airports>*> _10AirportsCoord(string lat, string log);
        vector<Vertex<Airports>*> _10AirportsCoordRaio(string lat, string log,int raio);

        double _10Haversine(double lat_1, double log_1, double lat_2, double log_2);

        pair<vector<Vertex<Airports> *>, vector<Vertex<Airports> *>> _10Montador(vector<Vertex<Airports>*> src, vector<Vertex<Airports>*> dest);
};

#endif //PROJECT_2_FLIGHTS_H
