//
// Created by pchmelo on 25-12-2023.
//
#include "string"
#include "set"

#ifndef PROJECT_2_AIRPORTS_H
#define PROJECT_2_AIRPORTS_H

using namespace std;

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

    bool operator<(Airports airports) const{
        return this->code < airports.code;
    }
};

class setAirports{
    public:
        set<Airports> setAirports;
        void  readLines();
};

#endif //PROJECT_2_AIRPORTS_H
