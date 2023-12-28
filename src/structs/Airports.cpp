//
// Created by pchmelo on 25-12-2023.
//

#include "Airports.h"
#include "fstream"
#include "sstream"
#include "vector"
using namespace std;

Airports::Airports() {
    this->code = "0";
    this->name = "0";
    this->city = "0";
    this->country = "0";
    this->lat = "0";
    this->lon = "0";
}
Airports::Airports(string code) {
    this->code = code;
    this->name = "0";
    this->city = "0";
    this->country = "0";
    this->lat = "0";
    this->lon = "0";
}

Airports::Airports(string code, string name, string city, string country, string lat,string lon)
{
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->lat = lat;
    this->lon = lon;
}

string Airports::getCode() const{
    return this->code;
}
string Airports::getName() const{
    return this->name;
}
string Airports::getCity() const{
    return this->city;
}
string Airports::getCountry() const{
    return this->country;
}
string Airports::getLat() const{
    return this->lat;
}
string Airports::getLon() const{
    return this->lon;
}

void HashAirports::readLines(Flights &flights) {
    string input = "../src/structs/dataset/airports.csv";
    ifstream MyReadFile(input);

    string line;
    Airports airports;

    getline(MyReadFile, line);

    while (getline(MyReadFile, line)) {
        vector<string> values;
        stringstream ss(line);

        while (ss.good()) {
            string subtr;
            getline(ss, subtr, ',');
            values.push_back(subtr);
        }


        airports = Airports(values[0], values[1], values[2], values[3], values[4], values[5]);
        flights.flights.addVertex(airports);
        this->airportTable.insert(airports);
    }


}

int HashAirports::_1numAirports() {
    return this->airportTable.size();
}
