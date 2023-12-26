//
// Created by pchmelo on 25-12-2023.
//


#ifndef PROJECT_2_AIRPORTS_H
#define PROJECT_2_AIRPORTS_H

#include "string"
#include "set"
#include "unordered_set"
#include "Flights.h"

using namespace std;

class Flights;

class Airports {
    private:
        string code;
        string name;
        string city;
        string country;
        string lat;
        string lon;
    public:
        Airports();
        Airports(string code);
        Airports(string code, string name, string city, string country, string lat,string lon);
        string getCode() const;
        string getName() const;
        string getCity() const;
        string getCountry() const;
        string getLat() const;
        string getLon() const;

    bool operator==(Airports airports) const{
        return this->code == airports.code;
    }
};

struct airportHash{

    int operator() (const Airports& b) const {
        int res = 0;
        int i = 1;

        for(char c: b.getCode()){
            res += c*i;
            i++;
        }

        return res % 6000;

    }

    bool operator() (const Airports& b1, const Airports& b2) const {
        return b1.getCode() == b2.getCode();
    }
};

typedef unordered_set<Airports, airportHash, airportHash> AirportTable;

class HashAirports{
    public:
        AirportTable airportTable;
        void  readLines(Flights &flights);

        //1
        int _1numAirports();
};

#endif
