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

    bool operator<(Airports airports) const{
        return this->code < airports.code;
    }

};

struct airportHash{

    int operator() (const Airports& b) const {
            const string& code = b.getCode();
            unsigned  int hash = 5381;

            for(char c: b.getCode()){
                hash = 33*hash + static_cast<unsigned int>(c);
            }

            return hash % 3019;
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

struct AirportsGreatDistance{
    Airports airport_source;
    Airports airport_dest;
    int distance;

    AirportsGreatDistance(){
        this->distance = 0;
    }

    AirportsGreatDistance(Airports a, Airports b, int distance){
        this->airport_source = a;
        this->airport_dest = b;
        this->distance = distance;
    }

};

struct AirportsTrafic{
    pair<Airports, int> trafic;
    AirportsTrafic(Airports airports, int n){
        pair<Airports, int> res = pair(airports, n);
        this->trafic = res;
    }

    bool operator==(Airports airports) const{
        return this->trafic.first.getCode() == airports.getCode();
    }

    bool operator<(AirportsTrafic a) const{
        return this->trafic.second < a.trafic.second;
    }
};

struct AirportStop{
    Vertex<Airports>* src;
    Vertex<Airports>* dest;
    Airlines airlines;

    AirportStop(){}

    AirportStop(Vertex<Airports>* scr, Vertex<Airports>* dest, Airlines airlines){
        this->src = scr;
        this->dest = dest;
        this->airlines = airlines;
    }

    void setA(Vertex<Airports>* a){
        this->src = a;
    }

    void setB(Vertex<Airports>* b){
        this->dest = b;
    }

    void Airline(Airlines airlines1){
        this->airlines = airlines1;
    }

};

struct AirportStop2{
    Vertex<Airports>* src;
    Vertex<Airports>* dest;
    vector<Airlines> airlines;

    AirportStop2(){}

    AirportStop2(Vertex<Airports>* scr, Vertex<Airports>* dest, vector<Airlines> airlines){
        this->src = scr;
        this->dest = dest;
        this->airlines = airlines;
    }

    void setA(Vertex<Airports>* a){
        this->src = a;
    }

    void setB(Vertex<Airports>* b){
        this->dest = b;
    }

    void Airline(vector<Airlines> airlines1){
        this->airlines = airlines1;
    }

};


#endif
