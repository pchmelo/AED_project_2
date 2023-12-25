//
// Created by pchmelo on 25-12-2023.
//

#include "Flights.h"
#include "sstream"
#include "fstream"
#include "iostream"


void Flights::ReadLines() {
    string input = "../src/structs/dataset/flights.csv";
    ifstream MyReadFile(input);

    string line;

    getline(MyReadFile, line);

    while (getline(MyReadFile, line)) {
        vector<string> values;
        stringstream ss(line);

        while (ss.good()) {
            string subtr;
            getline(ss, subtr, ',');
            values.push_back(subtr);
        }

        auto it_1 = flights.findVertex(values[0]);
        auto it_2 = flights.findVertex(values[1]);

        if(it_1 != nullptr){
            if(it_2 != nullptr){
                flights.addEdge(values[0], values[1], values[2]);
            }
            else{
                flights.addVertex(values[1]);
                flights.addEdge(values[0], values[1], values[2]);
            }
        }
        else{
            if(it_2 != nullptr){
                flights.addVertex(values[0]);
                flights.addEdge(values[0], values[1], values[2]);
            }
            else{
                flights.addVertex(values[0]);
                flights.addVertex(values[1]);
                flights.addEdge(values[0], values[1], values[2]);
            }
        }

        values.clear();
    }
}

int Flights::getFlightsPerCountry(setAirports setAirports,string country) {
    int res = 0;
    for(auto a: this->flights.getVertexSet()){
        for(auto b :a->getAdj()){
            auto airports = setAirports.setAirports.find(a->getInfo());
            if(airports->getCountry() == country){
                //cout << a->getInfo() << ", " << b.getDest()->getInfo() << ", " << b.getAirline() << "\n";
                res ++;
            }

            airports = setAirports.setAirports.find(b.getDest()->getInfo());
            if(airports->getCountry() == country){
                //cout << a->getInfo() << ", " << b.getDest()->getInfo() << ", " << b.getAirline() << "\n";
                res++;
            }
        }

    }

    return res;
}

int Flights::getFlightsPerCity(setAirports setAirports, std::string city) {
    int res = 0;
    for(auto a: this->flights.getVertexSet()){
        for(auto b :a->getAdj()){

            auto airports = setAirports.setAirports.find(a->getInfo());
            if(airports->getCity() == city){
                res ++;
            }

            airports = setAirports.setAirports.find(b.getDest()->getInfo());
            if(airports->getCity() == city){
                res++;
            }
        }

    }

    return res;
}

int Flights::getFlightsPerCompany(setAirlines setAirlines, string company) {
    int res = 0;

    for(auto code_1 : this->flights.getVertexSet()){
        for(auto code_2 : code_1->getAdj()){

            auto airlines = setAirlines.setAirlines.find(code_2.getAirline());

            if(airlines != setAirlines.setAirlines.end()){
                if(company == airlines->getCode()){
                    res++;
                }
            }
        }
    }

    return res;
}