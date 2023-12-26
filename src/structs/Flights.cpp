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

        flights.addEdge(values[1], values[0], values[2]);
        values.clear();
    }
}

int Flights::_1numViajens() {
    int res = 0;
    for(auto vertex : this->flights.getVertexSet()){
        for(auto edge : vertex->getAdj()){
            res++;
        }
    }

    return res;
}

int Flights::_2numViajensDeAirport(string code) {
    auto it = this->flights.findVertex(code);
    return it->getAdj().size();
}

int Flights::_2numViajensDeAirlines(string code) {
    int res = 0;

    auto it_1 = this->flights.findVertex(code);
    set<string> set_t;

    for(auto airline : it_1->getAdj()){
        auto it_2 = set_t.find(airline.getAirline());

        if(it_2 == set_t.end()){
            res++;
            set_t.insert(airline.getAirline());
        }
    }

    return res;
}

int Flights::_3getFlightsPerCountry(HashAirports hashAirports,string country) {
    int res = 0;
    for(auto a: this->flights.getVertexSet()){
        for(auto b :a->getAdj()){
            auto airports = hashAirports.airportTable.find(a->getInfo());
            if(airports->getCountry() == country){
                //cout << a->getInfo() << ", " << b.getDest()->getInfo() << ", " << b.getAirline() << "\n";
                res ++;
            }

            airports = hashAirports.airportTable.find(b.getDest()->getInfo());
            if(airports->getCountry() == country){
                //cout << a->getInfo() << ", " << b.getDest()->getInfo() << ", " << b.getAirline() << "\n";
                res++;
            }
        }

    }

    return res;
}

int Flights::_3getFlightsPerCity(HashAirports hashAirports, std::string city) {
    int res = 0;
    for(auto a: this->flights.getVertexSet()){
        for(auto b :a->getAdj()){

            auto airports = hashAirports.airportTable.find(a->getInfo());
            if(airports->getCity() == city){
                res ++;
            }

            airports = hashAirports.airportTable.find(b.getDest()->getInfo());
            if(airports->getCity() == city){
                res++;
            }
        }

    }

    return res;
}

int Flights::_3getFlightsPerCompany(HashAirlines hashAirlines, string company) {
    int res = 0;

    for(auto code_1 : this->flights.getVertexSet()){
        for(auto code_2 : code_1->getAdj()){

            auto airlines = hashAirlines.airlinesTable.find(code_2.getAirline());

            if(airlines != hashAirlines.airlinesTable.end()){
                if(company == airlines->getCode()){
                    res++;
                }
            }
        }
    }

    return res;
}

vector<string> Flights::_4getVecCountriesAirport(string code, HashAirports hashAirports) {
    vector<string> res;
    set<string> set_country;
    auto airport = this->flights.findVertex(code);

    for(auto edge : airport->getAdj()){
        auto country_t = hashAirports.airportTable.find(edge.getDest()->getInfo());
        auto it_1 = set_country.find(country_t->getCountry());

        if(it_1 == set_country.end()){
            set_country.insert(country_t->getCountry());
            res.push_back(country_t->getCountry());
        }
    }

    return res;
}

int Flights::_4getNumCountriesAirport(std::string code, HashAirports hashAirports) {
    vector<string> res = _4getVecCountriesAirport(code, hashAirports);
    return res.size();
}

vector<string> Flights::_4getVecCountriesCity(std::string city, HashAirports hashAirports) {
    vector<string> res;
    set<string> set_country;
    vector<Vertex<string>*> vertex_v;

    for(auto vertex : this->flights.getVertexSet()){
        auto airports = hashAirports.airportTable.find(vertex->getInfo());
        if(airports->getCity() == city){
            vertex_v.push_back(vertex);
        }
    }
    for(auto vertex : vertex_v){
        for(auto edge : vertex->getAdj()){
            auto country_t = hashAirports.airportTable.find(edge.getDest()->getInfo());
            auto it_1 = set_country.find(country_t->getCountry());

            if(it_1 == set_country.end()){
                set_country.insert(country_t->getCountry());
                res.push_back(country_t->getCountry());
            }
        }
    }
    return res;
}

int Flights::_4getNumCountriesCity(std::string city, HashAirports hashAirports) {
    vector<string> res = _4getVecCountriesCity(city, hashAirports);
    return res.size();
}

vector<string> Flights::_4getVecCountriesCountry(std::string country, HashAirports hashAirports) {
    vector<string> res;
    set<string> set_country;
    vector<Vertex<string>*> vertex_v;

    for(auto vertex : this->flights.getVertexSet()){
        auto airports = hashAirports.airportTable.find(vertex->getInfo());
        if(airports->getCountry() == country){
            vertex_v.push_back(vertex);
        }
    }
    for(auto vertex : vertex_v){
        for(auto edge : vertex->getAdj()){
            auto country_t = hashAirports.airportTable.find(edge.getDest()->getInfo());
            auto it_1 = set_country.find(country_t->getCountry());

            if(it_1 == set_country.end()){
                set_country.insert(country_t->getCountry());
                res.push_back(country_t->getCountry());
            }
        }
    }
    return res;
}

int Flights::_4getNumCountriesCountry(std::string country, HashAirports hashAirports) {
    vector<string> res = _4getVecCountriesCountry(country, hashAirports);
    return res.size();
}