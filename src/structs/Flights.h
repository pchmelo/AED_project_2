//
// Created by pchmelo on 25-12-2023.
//

#include "string"
#include "Graph.h"
#include "Airports.h"
#include "Airlines.h"

#ifndef PROJECT_2_FLIGHTS_H
#define PROJECT_2_FLIGHTS_H


class Flights {
    public:
        Graph<string> flights;
        void ReadLines();

        int getFlightsPerCountry(setAirports setAirports, string country);
        int getFlightsPerCity(setAirports setAirports, string city);
        int getFlightsPerCompany(setAirlines setAirlines, string airline);
};


#endif //PROJECT_2_FLIGHTS_H
