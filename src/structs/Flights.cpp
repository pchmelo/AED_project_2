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

        flights.addEdge(values[0], values[1], values[2]);
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

    for (auto code_1: this->flights.getVertexSet()) {
        for (auto code_2: code_1->getAdj()) {

            auto airlines = hashAirlines.airlinesTable.find(code_2.getAirline());

            if (airlines != hashAirlines.airlinesTable.end()) {
                if (company == airlines->getCode()) {
                    res++;
                }
            }
        }
    }

    return res;

}
    int Flights::Airports_per_airport(string code)
    {
        int res = 0;
        for (auto vertex : this->flights.getVertexSet()) {
            vertex->setVisited(false);
        }

        for(auto a: this->flights.getVertexSet())
        {
            if(a->getInfo()==code)
            {
                res+= air_per_air_aux(a);
                return res;
            }
        }
        return res;
    }

    int Flights:: air_per_air_aux(Vertex<string>*v)
    {
        int res = 1;
        v->setVisited(true);
        for (Edge<string> edge : v->getAdj()) {
            if (!edge.getDest()->isVisited())
                res += air_per_air_aux(edge.getDest());
        }
        return res;
    }



    int Flights:: Cities_per_airport(string code, HashAirports hashAirports)
    {
        int res = 0;
        for (auto vertex : this->flights.getVertexSet()) {
            vertex->setVisited(false);
        }
        list<string> cities;

        for(auto a: this->flights.getVertexSet())
        {
            if(a->getInfo()==code)
            {
                res+= cit_per_air_aux(a, cities, hashAirports);
                return res;
            }
        }
        return res;
    }
    int Flights::cit_per_air_aux(Vertex<string> *v, list<string> &cities, HashAirports hashAirports) {
        int res = 0;
        v->setVisited(true);
        for (Edge<string> edge : v->getAdj()) {
            if (!edge.getDest()->isVisited())
            {

                auto airport = hashAirports.airportTable.find(edge.getDest()->getInfo());

                if(find(cities.begin(), cities.end(),airport->getCity())->empty())
                {

                    res++;
                    cities.push_back(airport->  getCity());
                }
                res+= cit_per_air_aux(edge.getDest(), cities, hashAirports);
            }
        }
        return res;
}



    int Flights::Countries_per_airport(string code, HashAirports hashAirports)
    {
        int res = 0;
        for (auto vertex : this->flights.getVertexSet()) {
            vertex->setVisited(false);
        }
        list<string> countries;

        for(auto a: this->flights.getVertexSet())
        {
            if(a->getInfo()==code)
            {
                res+= count_per_air_aux(a, countries, hashAirports);
                return res;
            }
        }
        return res;
    }

    int Flights:: count_per_air_aux(Vertex<string> *v, list<string> countries, HashAirports hashAirports)
    {
        int res = 0;
        v->setVisited(true);
        for (Edge<string> edge : v->getAdj()) {
            if (!edge.getDest()->isVisited())
            {

                auto airport = hashAirports.airportTable.find(edge.getDest()->getInfo());

                if(find(countries.begin(), countries.end(),airport->getCountry())->empty())
                {

                    res++;
                    countries.push_back(airport->  getCity());
                }
                res+= cit_per_air_aux(edge.getDest(), countries, hashAirports);
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

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        if(v.second > x){
            break;
        }

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
            if(!w->isVisited()){
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

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        if(v.second > x){
            break;
        }

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
            if(!w->isVisited()){
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

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        if(v.second > x){
            break;
        }

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
            if(!w->isVisited()){
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

list<AirportsGreatDistance> Flights::_7getAirportsGreat(HashAirports hashAirports) {
    int diameter = 0;
    AirportsGreatDistance t;
    list<AirportsGreatDistance> res;

    for(auto vertex : this->flights.getVertexSet()){
        map<Vertex<string>*, int> dist;
        queue<Vertex<string>*> q;

        for(auto v : flights.getVertexSet()){
            dist[v] = -1;
        }

        dist[vertex] = 0;
        q.push(vertex);

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
                res.clear();
                diameter = pair.second;

                auto air_1 = hashAirports.airportTable.find(vertex->getInfo());
                auto air_2 = hashAirports.airportTable.find(pair.first->getInfo());

                t = AirportsGreatDistance(*air_2, *air_1, diameter);
                res.push_back(t);
            }
            else if(pair.second == diameter){
                auto air_1 = hashAirports.airportTable.find(vertex->getInfo());
                auto air_2 = hashAirports.airportTable.find(pair.first->getInfo());

                t = AirportsGreatDistance(*air_1, *air_2, diameter);
                res.push_back(t);
            }
        }

        dist.clear();

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

set<string > Flights::_9Articulations(HashAirports hashAirports) {
    set<string> res;
    stack<Vertex<string>*> s;
    set<Vertex<string>*> inStack;
    bool first = true;
    int i = 1;

    for (auto &vertex : flights.getVertexSet()) {
        vertex->setVisited(false);
        vertex->setLow(0);
        vertex->setNum(0);
    }

    for (auto vertex : flights.getVertexSet()) {
        if(!vertex->isVisited()) {
            _9Auxiliar(vertex, s, res, i, hashAirports, inStack, first);
            first = false;
        }
    }

    return res;
}

void Flights::_9Auxiliar(Vertex<string> *vertex, stack<Vertex<string>*> &s, set<string> &res, int &i, HashAirports hashAirports, set<Vertex<string>*> &inStack, bool first) {
    vertex->setVisited(true);
    vertex->setNum(i);
    vertex->setLow(i);

    i++;

    int children = 0;
    bool art = false;

    s.push(vertex);
    inStack.insert(vertex);



    for(auto &edge : vertex->getAdj()) {
        auto w = edge.getDest();

        if(!w->isVisited()){
            children++;
            _9Auxiliar(w, s, res, i, hashAirports, inStack, first);
            vertex->setLow(min(vertex->getLow(), w->getLow()));

            if(w->getLow() >= vertex->getNum()){
                art = true;
            }
        }
        else{
            vertex->setLow(min(vertex->getLow(), w->getNum()));
        }
    }

    if((vertex->getLow() == 1 && children > 1) || (vertex->getNum() > 1 && art)){
        res.insert(vertex->getInfo());
    }

}

int Flights::_9numArticulations(HashAirports hashAirports) {
    set<string> res = _9Articulations(hashAirports);
    return res.size();
}

list<AirportStop> Flights::_10BestPathEntreDoisAeroportos(Vertex<string>* src, Vertex<string>* dest, HashAirports hashAirports,HashAirlines hashAirlines) {
    list<AirportStop> res;
    AirportStop t;

    unordered_map<Vertex<string>* , int> paragens;
    unordered_map<Vertex<string>*, Vertex<string>*> previo;

    queue<Vertex<string>*> fila;

    for(auto& vertex : this->flights.getVertexSet()){
        paragens[vertex] = -1;
        previo[vertex] = nullptr;
    }

    paragens[src] = 0;
    fila.push(src);

    while(!fila.empty()){
        auto vertex = fila.front();
        fila.pop();

        if(vertex->getInfo() == dest->getInfo()){
            break;
        }

        for(auto &edge : vertex->getAdj()){
            auto w = edge.getDest();
            auto airline = edge.getAirline();

            if(paragens[w] == -1){
                paragens[w] = paragens[vertex] + 1;
                previo[w] = vertex;

                fila.push(w);
            }
        }
    }

    bool flag = true;
    string airport_1;
    string airport_2;
    string airline = "";

    for(auto vertex = dest; vertex != nullptr; vertex = previo[vertex]){
        if(flag){
            airport_2 = vertex->getInfo();
            flag = false;
        }
        else{
            airport_1 = vertex->getInfo();

            auto air_1 = hashAirports.airportTable.find(airport_1);
            auto air_2 = hashAirports.airportTable.find(airport_2);

            for(auto edge : vertex->getAdj()){
                if(edge.getDest()->getInfo() == airport_2){
                    airline = edge.getAirline();
                }
            }

            auto ail = hashAirlines.airlinesTable.find(airline);
            t = AirportStop(*air_1, *air_2, *ail);
            res.push_back(t);

            if(airport_1 == src->getInfo()){
                break;
            }

            airport_2 = airport_1;
        }
    }

    reverse(res.begin(), res.end());

    return res;
}