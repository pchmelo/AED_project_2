//
// Created by pchmelo on 25-12-2023.
//

#include "Flights.h"
#include "sstream"
#include "fstream"
#include "iostream"
#include "map"


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

vector<string> Flights::_6getVecStopsAirports(string code, int x, HashAirports hashAirports) {
    vector<string> res;
    set<string> set_t;

    auto s = this->flights.findVertex(code);

    if (s == NULL)
        return res;

    queue<pair<Vertex<string>*, int>> q;

    for (auto v : this->flights.getVertexSet())
        v->setVisited(false);

    q.push(pair(s, 0));
    s->setVisited(true);

    while (q.front().second <= x) {
        auto v = q.front();
        q.pop();

        if(v.second != 0){
            auto airport = hashAirports.airportTable.find(v.first->getInfo());
            auto it = set_t.find(airport->getCode());
            if(it == set_t.end()){
                set_t.insert(airport->getCode());
                res.push_back(airport->getName());
            }
        }

        for (auto & e : v.first->getAdj()) {
            auto w = e.getDest();
            if ( ! w->isVisited() ) {
                q.push(pair(w, v.second + 1));
                w->setVisited(true);
            }
        }
    }
    return res;
}

int Flights::_6getIntStopsAirports(std::string code, int x, HashAirports hashAirports) {
    vector<string> res = this->_6getVecStopsAirports(code, x, hashAirports);
    return res.size();
}

vector<string> Flights::_6getVecStopsCities(std::string code, int x, HashAirports hashAirports) {
    vector<string> res;
    set<string> set_t;

    auto s = this->flights.findVertex(code);

    if (s == NULL)
        return res;

    queue<pair<Vertex<string>*, int>> q;

    for (auto v : this->flights.getVertexSet())
        v->setVisited(false);

    q.push(pair(s, 0));
    s->setVisited(true);

    while (q.front().second <= x) {
        auto v = q.front();
        q.pop();

        if(v.second != 0){
            auto airport = hashAirports.airportTable.find(v.first->getInfo());
            auto it = set_t.find(airport->getCity());
            if(it == set_t.end()){
                set_t.insert(airport->getCity());
                res.push_back(airport->getCity());
            }
        }

        for (auto & e : v.first->getAdj()) {
            auto w = e.getDest();
            if ( ! w->isVisited() ) {
                q.push(pair(w, v.second + 1));
                w->setVisited(true);
            }
        }
    }
    return res;
}

int Flights::_6getIntStopsCities(std::string code, int x, HashAirports hashAirports) {
    vector<string> res = this->_6getVecStopsCities(code, x, hashAirports);
    return res.size();
}

vector<string> Flights::_6getVecStopsCountries(std::string code, int x, HashAirports hashAirports) {
    vector<string> res;
    set<string> set_t;

    auto s = this->flights.findVertex(code);

    if (s == NULL)
        return res;

    queue<pair<Vertex<string>*, int>> q;

    for (auto v : this->flights.getVertexSet())
        v->setVisited(false);

    q.push(pair(s, 0));
    s->setVisited(true);

    while (q.front().second <= x) {
        auto v = q.front();
        q.pop();

        if(v.second != 0){
            auto airport = hashAirports.airportTable.find(v.first->getInfo());
            auto it = set_t.find(airport->getCountry());
            if(it == set_t.end()){
                set_t.insert(airport->getCountry());
                res.push_back(airport->getCountry());
            }
        }

        for (auto & e : v.first->getAdj()) {
            auto w = e.getDest();
            if ( ! w->isVisited() ) {
                q.push(pair(w, v.second + 1));
                w->setVisited(true);
            }
        }
    }
    return res;
}

int Flights::_6getIntStopsCountries(std::string code, int x, HashAirports hashAirports) {
    vector<string> res = this->_6getVecStopsCountries(code, x, hashAirports);
    return res.size();
}

AirportsGreatDistance Flights::_7getAirportsGreat(HashAirports hashAirports) {
    int diameter = 0;
    AirportsGreatDistance res;
    list<AirportsGreatDistance> dist;

    for(auto vertex : this->flights.getVertexSet()){
        map<Vertex<string>*, int> dist;
        queue<Vertex<string>*> q;
        bool flag = true;

        for(auto v : this->flights.getVertexSet()){
            if(flag){
                dist[v] = 0;
                q.push(v);
                flag = false;

                continue;
            }
            else{
                dist[v] = -1;
            }
        }

        while(!q.empty()){
            auto current = q.front();
            q.pop();

            for(auto edge : current->getAdj()){
                auto w = edge.getDest();
                if(dist[w] == -1){
                    dist[w] = dist[current] + 1;
                    q.push(w);
                }
            }
        }

        for(auto& pair : dist){
            if(pair.second > diameter){
                diameter = pair.second;

            }
        }

    }

    return res;

}



vector<AirportsTrafic> Flights::_8getTopVecAirports(HashAirports hashAirports) {
    vector<AirportsTrafic> res;

    for(auto vertex : flights.getVertexSet()){
        auto airport_1 = hashAirports.airportTable.find(vertex->getInfo());
        auto it_1 = std::find(res.begin(), res.end(), *airport_1);

        if(it_1 == res.end()){
            AirportsTrafic airportsTrafic_1 = AirportsTrafic(*airport_1, 0);
            res.push_back(airportsTrafic_1);
        }
        for(auto edge : vertex->getAdj()){
            auto airport_2 = hashAirports.airportTable.find(edge.getDest()->getInfo());
            auto it_2 = std::find(res.begin(), res.end(), *airport_2);

            if(it_2 == res.end()){
                AirportsTrafic airportsTrafic_2 = AirportsTrafic(*airport_2, 0);
                res.push_back(airportsTrafic_2);
            }

            it_1 = std::find(res.begin(), res.end(), *airport_1);
            it_2 = std::find(res.begin(), res.end(), *airport_2);

            it_1->trafic.second = it_1->trafic.second + 1;
            it_2->trafic.second = it_2->trafic.second + 1;
        }
    }
    return res;
}

vector<AirportsTrafic> Flights::_8getTopVecDescAirports(HashAirports hashAirports) {
    vector<AirportsTrafic> res = _8getTopVecAirports(hashAirports);
    sort(res.rbegin(), res.rend());
    return res;
}

vector<AirportsTrafic> Flights::_8getTopVecAscAirports(HashAirports hashAirports) {
    vector<AirportsTrafic> res = _8getTopVecAirports(hashAirports);
    sort(res.begin(), res.end());
    return res;
}
