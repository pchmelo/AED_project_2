//
// Created by pchmelo on 25-12-2023.
//

#include "Flights.h"
#include "sstream"
#include "fstream"
#include "iostream"
#include "map"
#include "math.h"


void Flights::ReadLines(HashAirlines hashAirlines, HashAirports hashAirports) {
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
        auto airport_1 = hashAirports.airportTable.find(values[0]) ;
        auto airport_2 = hashAirports.airportTable.find(values[1]);
        auto airline_1 = hashAirlines.airlinesTable.find(values[2]);
        flights.addEdge(*airport_1, *airport_2, *airline_1);
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
        auto it_2 = set_t.find(airline.getAirline().getCode());
        if(it_2 == set_t.end()){
            res++;
            set_t.insert(airline.getAirline().getCode());
        }
    }

    return res;
}

int Flights::_3getFlightsPerCountry(string country) {
    int res = 0;
    for(auto a: this->flights.getVertexSet()){
        for(auto b :a->getAdj()){
            if(a->getInfo().getCountry() == country){
                //cout << a->getInfo() << ", " << b.getDest()->getInfo() << ", " << b.getAirline() << "\n";
                res ++;
            }

            if(b.getDest()->getInfo().getCountry() == country){
                //cout << a->getInfo() << ", " << b.getDest()->getInfo() << ", " << b.getAirline() << "\n";
                res++;
            }
        }

    }

    return res;
}

int Flights::_3getFlightsPerCity(string city, string country) {
    int res = 0;
    for(auto a: this->flights.getVertexSet()){
        for(auto b :a->getAdj()){
            if(country == "k"){
                if(a->getInfo().getCity() == city){
                    res ++;
                }
                if(b.getDest()->getInfo().getCity() == city){
                    res++;
                }
            }
            else{
                if(a->getInfo().getCity() == city || a->getInfo().getCountry() == country){
                    res ++;
                }
                if(b.getDest()->getInfo().getCity() == city || a->getInfo().getCountry() == country){
                    res++;
                }
            }

        }

    }

    return res;
}

int Flights::_3getFlightsPerCompany(string company) {
    int res = 0;

    for (auto code_1: this->flights.getVertexSet()) {
        for (auto code_2: code_1->getAdj()) {


                if (company == code_2.getAirline().getCode()) {
                    res++;

            }
        }
    }

    return res;

}
vector<Airports> Flights::_5Airports_per_airport(string code ){

    vector<Airports> res;
    set<string> set_t;

    auto s = this->flights.findVertex(code);

    if (s == NULL)
    return res;

    queue<Vertex<Airports>*> q;

    for (auto v : this->flights.getVertexSet())
    v->setVisited(false);

    q.push(s);
    s->setVisited(true);

    while (!q.empty()) {
    auto v = q.front();
    q.pop();

        auto airport = v->getInfo();
        auto it = set_t.find(airport.getCode());
        if(it == set_t.end()){
            set_t.insert(airport.getCode());
            res.push_back(airport);
        }


    for (auto & e : v->getAdj()) {
        auto w = e.getDest();
        if ( ! w->isVisited() ) {
            q.push(w);
            w->setVisited(true);
            }
        }
    }
    return res;
}

    int Flights:: _5air_per_air_aux(string code){
        return _5Airports_per_airport(code).size();
    }



vector<Airports> Flights::_5Cities_per_airport(string code, string country)
    {
        vector<Airports> res;
        set<string> set_cidades;
        set<string> set_paises;

        auto s = this->flights.findVertex(code);

        if (s == NULL)
            return res;

        queue<pair<Vertex<Airports>*, int>> q;

        for (auto v : this->flights.getVertexSet())
            v->setVisited(false);

        q.push(pair(s, 0));
        s->setVisited(true);

        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            if(v.second != 0){
                auto airport = v.first->getInfo();
                auto it_1 = set_cidades.find(airport.getCity());
                if(it_1 == set_cidades.end()){
                    set_cidades.insert(airport.getCity());
                    res.push_back(airport);
                }
                else{
                    auto it_2 = set_paises.find(airport.getCountry());
                    if(it_2 == set_paises.end()){
                        set_paises.insert(airport.getCountry());
                        res.push_back(airport);
                    }
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
int Flights::_5cit_per_air_aux(string code, string country) {
    return _5Cities_per_airport(code, country).size();

}



vector<Airports>Flights::_5Countries_per_airport(string code){
        vector<Airports> res;
        set<string> set_t;

        auto s = this->flights.findVertex(code);

        if (s == NULL)
            return res;

        queue<pair<Vertex<Airports>*, int>> q;

        for (auto v : this->flights.getVertexSet())
            v->setVisited(false);

        q.push(pair(s, 0));
        s->setVisited(true);

        while (!q.empty()) {
            auto v = q.front();
            q.pop();


            if(v.second != 0){
                auto airport = v.first->getInfo();
                auto it = set_t.find(airport.getCountry());
                if(it == set_t.end()){
                    set_t.insert(airport.getCountry());
                    res.push_back(airport);
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

int Flights:: _5count_per_air_aux(string code)    {
    return _5Countries_per_airport(code).size();
    }

set<Airports> Flights::_4getVecCountriesAirport(string code) {
    set<Airports> res;
    set<string> set_country;

    auto airport = this->flights.findVertex(code);

    for(auto edge : airport->getAdj()){
        auto country_t =edge.getDest()->getInfo();
        auto it_1 = set_country.find(country_t.getCountry());

        if(it_1 == set_country.end()){
            set_country.insert(country_t.getCountry());
            res.insert(country_t);
        }
    }
    return res;
}

int Flights::_4getNumCountriesAirport(string code) {
    set<Airports> res = _4getVecCountriesAirport(code);
    return res.size();
}

set<Airports> Flights::_4getVecCountriesCity(string city, string country) {
    set<Airports> res;
    set<string> set_country;
    vector<Vertex<Airports>*> vertex_v;

    for(auto vertex : this->flights.getVertexSet()){
        if(country == "k"){
            if(vertex->getInfo().getCity() == city){
                vertex_v.push_back(vertex);
            }
        }
        else{
            if(vertex->getInfo().getCity() == city && vertex->getInfo().getCountry() == country){
                vertex_v.push_back(vertex);
            }
        }

    }

    for(auto vertex : vertex_v){
        for(auto edge : vertex->getAdj()){
            auto country_t = flights.findVertex(edge.getDest()->getInfo());
            auto it_1 = set_country.find(country_t->getInfo().getCountry());

            if(it_1 == set_country.end()){
                set_country.insert(country_t->getInfo().getCountry());
                res.insert(country_t->getInfo());
            }
        }
    }
    return res;
}

int Flights::_4getNumCountriesCity(string city, string country) {
    set<Airports> res = _4getVecCountriesCity(city, country);
    return res.size();
}

set<Airports> Flights::_4getVecCountriesCountry(std::string country) {
    set<Airports> res;
    set<string> set_country;
    vector<Vertex<Airports>*> vertex_v;

    for(auto vertex : this->flights.getVertexSet()){
        auto airports = flights.findVertex(vertex->getInfo());
        if(airports->getInfo().getCountry() == country){
            vertex_v.push_back(vertex);
        }
    }
    for(auto vertex : vertex_v){
        for(auto edge : vertex->getAdj()){
            auto country_t = flights.findVertex(edge.getDest()->getInfo());
            auto it_1 = set_country.find(country_t->getInfo().getCountry());

            if(it_1 == set_country.end()){
                set_country.insert(country_t->getInfo().getCountry());
                res.insert(country_t->getInfo());
            }
        }
    }
    return res;
}

int Flights::_4getNumCountriesCountry(std::string country ) {
    set<Airports> res = _4getVecCountriesCountry(country);
    return res.size();
}

vector<Airports> Flights::_6getVecStopsAirports(string code, int x) {
    vector<Airports> res;
    set<string> set_t;

    auto s = this->flights.findVertex(code);

    if (s == NULL)
        return res;

    queue<pair<Vertex<Airports>*, int>> q;

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
            auto airport = v.first->getInfo();
            auto it = set_t.find(airport.getCode());

            if(it == set_t.end()){
                set_t.insert(airport.getCode());
                res.push_back(airport);
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

int Flights::_6getIntStopsAirports(std::string code, int x ) {
    vector<Airports> res = this->_6getVecStopsAirports(code, x);
    return res.size();
}

vector<Airports> Flights::_6getVecStopsCities(std::string code, int x, string country) {
    vector<Airports> res;
    set<string> set_cidades;
    set<string> set_paises;

    auto s = this->flights.findVertex(code);

    if (s == NULL)
        return res;

    queue<pair<Vertex<Airports>*, int>> q;

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
            auto airport = v.first->getInfo();
            auto it_1 = set_cidades.find(airport.getCity());
            if(it_1 == set_cidades.end()){
                set_cidades.insert(airport.getCity());
                res.push_back(airport);
            }
            else{
                auto it_2 = set_cidades.find(airport.getCountry());
                if(it_2 == set_cidades.end()){
                    set_cidades.insert(airport.getCountry());
                    res.push_back(airport);
                }
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

int Flights::_6getIntStopsCities(std::string code, int x, string country) {
    vector<Airports> res = this->_6getVecStopsCities(code, x, country);
    return res.size();
}

vector<Airports> Flights::_6getVecStopsCountries(std::string code, int x ) {
    vector<Airports> res;
    set<string> set_t;

    auto s = this->flights.findVertex(code);

    if (s == NULL)
        return res;

    queue<pair<Vertex<Airports>*, int>> q;

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
            auto airport = v.first->getInfo();
            auto it = set_t.find(airport.getCountry());
            if(it == set_t.end()){
                set_t.insert(airport.getCountry());
                res.push_back(airport);
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

int Flights::_6getIntStopsCountries(std::string code, int x ) {
    vector<Airports> res = this->_6getVecStopsCountries(code, x);
    return res.size();
}

list<AirportsGreatDistance> Flights::_7getAirportsGreat() {
    int diameter = 0;
    AirportsGreatDistance t;
    list<AirportsGreatDistance> res;

    for(auto vertex : this->flights.getVertexSet()){
        map<Vertex<Airports>*, int> dist;
        queue<Vertex<Airports>*> q;

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

                auto air_1 = vertex->getInfo();
                auto air_2 = pair.first->getInfo();

                t = AirportsGreatDistance(air_2, air_1, diameter);
                res.push_back(t);
            }
            else if(pair.second == diameter){
                auto air_1 =vertex->getInfo();
                auto air_2 = pair.first->getInfo();

                t = AirportsGreatDistance(air_1, air_2, diameter);
                res.push_back(t);
            }
        }

        dist.clear();

    }

    return res;
}



vector<AirportsTrafic> Flights::_8getTopVecAirports( ) {
    vector<AirportsTrafic> res;

    for(auto vertex : flights.getVertexSet()){
        auto airport_1 = vertex->getInfo();
        auto it_1 = find(res.begin(), res.end(), airport_1);

        if(it_1 == res.end()){
            AirportsTrafic airportsTrafic_1 = AirportsTrafic(airport_1, 0);
            res.push_back(airportsTrafic_1);
        }
        for(auto edge : vertex->getAdj()){
            auto airport_2 = edge.getDest()->getInfo();
            auto it_2 = std::find(res.begin(), res.end(), airport_2);

            if(it_2 == res.end()){
                AirportsTrafic airportsTrafic_2 = AirportsTrafic(airport_2, 0);
                res.push_back(airportsTrafic_2);
            }

            it_1 = std::find(res.begin(), res.end(), airport_1);
            it_2 = std::find(res.begin(), res.end(), airport_2);

            it_1->trafic.second = it_1->trafic.second + 1;
            it_2->trafic.second = it_2->trafic.second + 1;
        }
    }
    return res;
}

vector<AirportsTrafic> Flights::_8getTopVecDescAirports( ) {
    vector<AirportsTrafic> res = _8getTopVecAirports();
    sort(res.rbegin(), res.rend());
    return res;
}

vector<AirportsTrafic> Flights::_8getTopVecAscAirports( ) {
    vector<AirportsTrafic> res = _8getTopVecAirports();
    sort(res.begin(), res.end());
    return res;
}

set<Airports > Flights::_9Articulations() {
    set<Airports> res;
    int i = 1;

    for (auto &vertex : flights.getVertexSet()) {
        vertex->setVisited(false);
        vertex->setLow(0);
        vertex->setNum(0);
        vertex->setProcessing(false);
    }

    for (auto vertex : flights.getVertexSet()) {
        if(!vertex->isVisited()) {
            _9Auxiliar(vertex, res, i);
        }
    }

    return res;
}

void Flights::_9Auxiliar(Vertex<Airports> *vertex, set<Airports> &res, int &i) {
    vertex->setVisited(true);
    vertex->setNum(i);
    vertex->setLow(i);
    vertex->setProcessing(true);
    i++;

    int children = 0;
    bool art = false;

    for (auto &edge : vertex->getAdj()) {
        auto w = edge.getDest();

        if (!w->isVisited()) {
            children++;
            _9Auxiliar(w, res, i);
            vertex->setLow(min(vertex->getLow(), w->getLow()));

            if (w->getLow() >= vertex->getNum()) {
                art = true;
            }
        } else if (w->isProcessing()) {
            vertex->setLow(min(vertex->getLow(), w->getNum()));
        }
    }

        if ((vertex->getNum() == 1 && children > 1) || (vertex->getNum() > 1 && art)) {
        res.insert(vertex->getInfo());
    }
    vertex->setProcessing(false);
}

int Flights::_9numArticulations() {
    set<Airports> res = _9Articulations();
    return res.size();
}

list<AirportStop2> Flights::_10BestPathEntreDoisAeroportos(Vertex<Airports>* src, Vertex<Airports>* dest) {
    list<AirportStop2> res;
    AirportStop2 t;

    unordered_map<Vertex<Airports>* , int> paragens;
    unordered_map<Vertex<Airports>*, Vertex<Airports>*> previo;

    queue<Vertex<Airports>*> fila;

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

            if(paragens[w] == -1){
                paragens[w] = paragens[vertex] + 1;
                previo[w] = vertex;

                fila.push(w);
            }
        }
    }

    bool flag = true;
    Airports airport_1;
    Airports airport_2;
    vector<Airlines> airlines;

    for(auto vertex = dest; vertex != nullptr; vertex = previo[vertex]){
        if(flag){
            airport_2 = vertex->getInfo();
            flag = false;
        }
        else{
            airport_1 = vertex->getInfo();

            auto air_1 = flights.findVertex(airport_1);
            auto air_2 = flights.findVertex(airport_2);

            for(auto edge : vertex->getAdj()){
                if(edge.getDest()->getInfo() == airport_2){
                    airlines.push_back(edge.getAirline());
                }
            }


            t = AirportStop2(air_1, air_2, airlines);
            res.push_back(t);
            airlines.clear();

            if(airport_1 == src->getInfo()){
                break;
            }

            airport_2 = airport_1;
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

vector<list<AirportStop2>> Flights::_10Commander(vector<Vertex<Airports> *> src, vector<Vertex<Airports> *> dest) {
    bool flag = true;
    list<AirportStop2> t_1;
    list<AirportStop2> t_2;
    vector<list<AirportStop2>> res;


    for(int i = 0; i < src.size(); i++){
        auto a = src.at(i);
        auto b = dest.at(i);

        if(flag){
            t_1 = _10BestPathEntreDoisAeroportos(a, b);
            res.push_back(t_1);
            flag = false;
        }
        else{
            t_2 = _10BestPathEntreDoisAeroportos(a, b);
            if(t_2.size() < t_1.size()){
                res.clear();
                t_1 = t_2;
                res.push_back(t_1);
            }
            else if(t_2.size() == t_1.size()){
                res.push_back(t_2);
            }
        }
    }

    return res;
}

vector<Vertex<Airports>*> Flights::_10AirportsAirport(std::string code, bool flag) {
    vector<Vertex<Airports>*> res;

    for(auto vertex : flights.getVertexSet()){
        if(flag){
            if(vertex->getInfo().getCode() == code){
                res.push_back(vertex);
            }
        }
        else{
            if(vertex->getInfo().getName() == code){
                res.push_back(vertex);
            }
        }

    }
    return res;
}

vector<Vertex<Airports>*> Flights::_10AirportsCity(string city, string pais){
    vector<Vertex<Airports>*> res;

    for(auto vertex : flights.getVertexSet()){
        if(pais == "k"){
            if(vertex->getInfo().getCity() == city){
                res.push_back(vertex);
            }
        } else{
            if(vertex->getInfo().getCity() == city && vertex->getInfo().getCountry() == pais){
                res.push_back(vertex);
            }
        }

    }
    return res;
}

vector<Vertex<Airports>*> Flights::_10AirportsPais(std::string country) {
    vector<Vertex<Airports>*> res;

    for(auto vertex : flights.getVertexSet()){
        if(vertex->getInfo().getCountry() == country){
            res.push_back(vertex);
        }
    }

    return res;
}



pair<vector<Vertex<Airports> *>, vector<Vertex<Airports> *>> Flights::_10Montador(vector<Vertex<Airports> *> src,vector<Vertex<Airports> *> dest) {
    vector<Vertex<Airports> *> origem;
    vector<Vertex<Airports> *> destino;

    for(auto v_src : src){
        for(auto v_dest : dest){
            origem.push_back(v_src);
            destino.push_back(v_dest);
        }
    }

    return pair(origem, destino);
}

vector<Vertex<Airports>*> Flights::_10AirportsCoord(std::string lat, std::string log) {
    vector<Vertex<Airports>*> res;

    double latitude_1 = ((stod(lat)) * M_PI) / 180.0;
    double longitude_1 = ((stod(log)) * M_PI) / 180.0;

    double latitude_2;
    double longitude_2;

    double dist = 0;
    double t = 0;
    bool flag = true;

    for(auto vertex : flights.getVertexSet()){
        auto airport = (vertex->getInfo());

        latitude_2 = ((stod(airport.getLat())) * M_PI) / 180.0;
        longitude_2 = ((stod(airport.getLon())) * M_PI) / 180.0;

        if(flag){
            dist = _10Haversine(latitude_1, longitude_1, latitude_2, longitude_2);
            res.push_back(vertex);
            flag = false;
        }
        else{
            t = _10Haversine(latitude_1, longitude_1, latitude_2, longitude_2);
            if(t < dist){
                dist = t;
                res.clear();
                res.push_back(vertex);
            }
            else if(t == dist){
                res.push_back(vertex);
            }
        }
    }

    return res;
}

vector<Vertex<Airports>*> Flights::_10AirportsCoordRaio(std::string lat, std::string log, int raio) {
    vector<Vertex<Airports>*> res;

    double latitude_1 = ((stod(lat)) * M_PI) / 180.0;
    double longitude_1 = ((stod(log)) * M_PI) / 180.0;

    double latitude_2;
    double longitude_2;

    double dist = 0;

    for(auto vertex : flights.getVertexSet()){
        auto airport = (vertex->getInfo());

        latitude_2 = ((stod(airport.getLat())) * M_PI) / 180.0;
        longitude_2 = ((stod(airport.getLon())) * M_PI) / 180.0;

        dist = _10Haversine(latitude_1, longitude_1, latitude_2, longitude_2);

        if(dist <= raio){
            res.push_back(vertex);
        }
    }

    return res;
}

double Flights::_10Haversine(double lat_1, double log_1, double lat_2, double log_2) {
    double raio_da_terra = 6371.0;

    double disLat = lat_2 - lat_1;
    double disLog = log_2 - log_1;

    double a = sin(disLat / 2) * sin(disLat / 2) + cos(lat_1) * cos(lat_2) * sin(disLog / 2) * sin(disLog / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distancia = raio_da_terra * c;

    return distancia;
}


vector<vector<AirportStop2>> Flights::_11AllBestPathEntreDoisAeroportos(Vertex<Airports>* src, Vertex<Airports>* dest, set<string> lista, int set_up) {
    vector<vector<AirportStop2>> res;
    AirportStop2 t;

    unordered_map<Vertex<Airports>* , int> paragens;
    unordered_map<Vertex<Airports>*, set<Vertex<Airports>*>> previo;

    queue<pair<Vertex<Airports>*, int>> fila;

    for(auto& vertex : this->flights.getVertexSet()){
        paragens[vertex] = 100;
        previo[vertex] = set<Vertex<Airports>*>();
    }

    paragens[src] = 0;
    fila.push(pair(src, 0));

    while(!fila.empty()){
        auto vertex = fila.front().first;
        int paragem_atual = fila.front().second;
        fila.pop();

        if(paragens[vertex] < paragem_atual){
            continue;
        }

        for(auto &edge : vertex->getAdj()){
            if(set_up != 0){
                auto f = lista.find(edge.getDest()->getInfo().getCode());

                if(set_up == 1){
                    if(f == lista.end()){
                        continue;
                    }
                }
                else{
                    if(f != lista.end()){
                        continue;
                    }
                }
            }

            auto w = edge.getDest();
            int paragem_nova = paragens[vertex] + 1;

            if(paragens[w] > paragem_nova){
                paragens[w] = paragem_nova;
                previo[w] = {vertex};
                fila.push(pair(w, paragem_nova));

            }
            else if (paragens[w] == paragem_nova){
                previo[w].insert(vertex);
            }
        }
    }
    bool flag = true;

    vector<AirportStop2> caminho_atual;
    _11AuxReconstructor(src, dest, previo, caminho_atual, res, t, flag);

    for(auto& p : res){
        p.erase(p.begin());
    }

    return res;
}

void Flights::_11AuxReconstructor(Vertex<Airports> *src, Vertex<Airports> *dest,unordered_map<Vertex<Airports> *, set<Vertex<Airports> *>> &previo,vector<AirportStop2> &caminhoAtual, vector<vector<AirportStop2>> &res, AirportStop2 &t, bool &flag) {
    if(flag){
        t.setB(dest);
        caminhoAtual.push_back(t);
        flag = false;
    }
    else{
        t.airlines.clear();
        for(auto edge : dest->getAdj()){
            if(edge.getDest()->getInfo().getCode() == caminhoAtual.back().dest->getInfo().getCode()){
                t.airlines.push_back(edge.getAirline());
            }
        }

        caminhoAtual.back().airlines = t.airlines;
        caminhoAtual.back().src = dest;
        t.setB(dest);
        caminhoAtual.push_back(t);
    }

    if(dest->getInfo().getCode() == src->getInfo().getCode()){
        res.push_back(caminhoAtual);
        reverse(res.back().begin(), res.back().end());
    }
    else{
        set<Vertex<Airports>*> &prevs = previo.at(dest);
        for(Vertex<Airports>* prev : prevs){
            _11AuxReconstructor(src, prev, previo, caminhoAtual, res, t, flag);
        }
    }

    caminhoAtual.pop_back();
}

vector<vector<AirportStop2>> Flights::_11AllCommander(vector<Vertex<Airports> *> src, vector<Vertex<Airports> *> dest, set<string> lista, int set) {
    bool flag = true;
    vector<vector<AirportStop2>> t;
    vector<vector<AirportStop2>> res;

    for(int i = 0; i < src.size(); i++){
        auto a = src.at(i);
        auto b = dest.at(i);

        if(flag){
            res = _11AllBestPathEntreDoisAeroportos(a, b, lista, set);
            flag = false;
        }
        else{
            t = _11AllBestPathEntreDoisAeroportos(a, b, lista, set);

            if(t.size() != 0){
                 if(res.size() != 0){
                     if(t.at(0).size() < res.at(0).size()){
                         t = res;
                     }
                     else if(t.at(0).size() == res.at(0).size()){
                         for(auto a : t){
                             res.push_back(a);
                         }
                     }
                 }
                 else{
                     t = res;
                 }
            }
        }
    }

    return res;
}

void  _11CombinationsOfAirlines(vector<vector<Airlines>> &lists, vector<Airlines> &atual, int index, vector<vector<Airlines>> &res){
    if(index == lists.size()){
        res.push_back(atual);
        return;
    }

    for(int i = 0; i < lists[index].size(); i++){
        atual.push_back(lists[index][i]);
        _11CombinationsOfAirlines(lists, atual, index + 1, res);
        atual.pop_back();
    }
}

vector<vector<AirportStop>> Flights::_11Separator(vector<vector<AirportStop2>> input) {
    vector<vector<AirportStop>> res;

    vector<vector<Airlines>> in;
    vector<vector<Airlines>> out;

    vector<Airlines> atual;

    vector<AirportStop> t;
    AirportStop airportStop;

    for(auto ten : input){
        for(auto ele : ten){
            airportStop.src = ele.src;
            airportStop.dest = ele.dest;

            t.push_back(airportStop);
            in.push_back(ele.airlines);
        }

        _11CombinationsOfAirlines(in, atual, 0, out);

        for(int i = 0; i < out.size(); i++){
            for(int j = 0; j < t.size(); j++){
                t.at(j).airlines = out.at(i).at(j);
            }
            res.push_back(t);
        }

        t.clear();
        in.clear();
        atual.clear();
        out.clear();
    }

    return res;
}

vector<vector<AirportStop>> Flights::_11FilterMinimizer(vector<vector<AirportStop2>> input, int &num) {
    vector<vector<AirportStop>> new_input = _11Separator(input);
    vector<vector<AirportStop>> res;

    int int_airlines = 0;
    int t = 0;
    bool flag = true;
    set<string> dif_air;

    for(auto ele : new_input){
        for(auto air : ele){
            auto it = dif_air.find(air.airlines.getCode());
            if(it == dif_air.end()){
                t++;
                dif_air.insert(air.airlines.getCode());
            }
        }

        if(flag){
            int_airlines = t;
            res.push_back(ele);
            flag = false;
        }
        else{
            if(t < int_airlines){
                int_airlines = t;
                res.clear();
                res.push_back(ele);
            }
            else if(t == int_airlines){
                res.push_back(ele);
            }
        }
        t = 0;
        dif_air.clear();
    }

    num = int_airlines;
    return res;
}

