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
            auto airports = flights.findVertex(a->getInfo());
            if(airports->getInfo().getCountry() == country){
                //cout << a->getInfo() << ", " << b.getDest()->getInfo() << ", " << b.getAirline() << "\n";
                res ++;
            }

            airports = flights.findVertex(b.getDest()->getInfo());
            if(airports->getInfo().getCountry() == country){
                //cout << a->getInfo() << ", " << b.getDest()->getInfo() << ", " << b.getAirline() << "\n";
                res++;
            }
        }

    }

    return res;
}

int Flights::_3getFlightsPerCity(string city) {
    int res = 0;
    for(auto a: this->flights.getVertexSet()){
        for(auto b :a->getAdj()){

            if(a->getInfo().getCity() == city){
                res ++;
            }

            if(b.getDest()->getInfo().getCity() == city){
                res++;
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
vector<Airports> Flights::Airports_per_airport(string code ){

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

        auto airport = flights.findVertex(v->getInfo());
        auto it = set_t.find(airport->getInfo().getCode());
        if(it == set_t.end()){
            set_t.insert(airport->getInfo().getCode());
            res.push_back(airport->getInfo().getName());
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

    int Flights:: air_per_air_aux(string code)
    {

        return Airports_per_airport(code).size();
    }



vector<Airports> Flights:: Cities_per_airport(string code )
    {
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
                auto airport = flights.findVertex(v.first->getInfo());
                auto it = set_t.find(airport->getInfo().getCity());
                if(it == set_t.end()){
                    set_t.insert(airport->getInfo().getCity());
                    res.push_back(airport->getInfo().getCity());
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
int Flights::cit_per_air_aux(string code) {
    return Cities_per_airport(code).size();

}



vector<Airports>Flights::Countries_per_airport(string code )
    {
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
                auto airport = flights.findVertex(v.first->getInfo());
                auto it = set_t.find(airport->getInfo().getCountry());
                if(it == set_t.end()){
                    set_t.insert(airport->getInfo().getCountry());
                    res.push_back(airport->getInfo().getCountry());
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

int Flights:: count_per_air_aux(string code)    {
    return Countries_per_airport(code).size();
    }






vector<Airports> Flights::_4getVecCountriesAirport(string code) {
    vector<Airports> res;
    set<string> set_country;
    auto airport = this->flights.findVertex(code);

    for(auto edge : airport->getAdj()){
        auto country_t = flights.findVertex(edge.getDest()->getInfo());
        auto it_1 = set_country.find(country_t->getInfo().getCountry());

        if(it_1 == set_country.end()){
            set_country.insert(country_t->getInfo().getCountry());
            res.push_back(airport->getInfo());
        }
    }
    return res;
}

int Flights::_4getNumCountriesAirport(string code) {
    vector<Airports> res = _4getVecCountriesAirport(code);
    return res.size();
}

vector<Airports> Flights::_4getVecCountriesCity(string city ) {
    vector<Airports> res;
    set<string> set_country;
    vector<Vertex<Airports>*> vertex_v;

    for(auto vertex : this->flights.getVertexSet()){
        if(vertex->getInfo().getCity() == city){
            vertex_v.push_back(vertex);
        }
    }

    for(auto vertex : vertex_v){
        for(auto edge : vertex->getAdj()){
            auto country_t = flights.findVertex(edge.getDest()->getInfo());
            auto it_1 = set_country.find(country_t->getInfo().getCountry());

            if(it_1 == set_country.end()){
                set_country.insert(country_t->getInfo().getCountry());
                res.push_back(country_t->getInfo());
            }
        }
    }
    return res;
}

int Flights::_4getNumCountriesCity(string city ) {
    vector<Airports> res = _4getVecCountriesCity(city);
    return res.size();
}

vector<Airports> Flights::_4getVecCountriesCountry(std::string country) {
    vector<Airports> res;
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
                res.push_back(country_t->getInfo());
            }
        }
    }
    return res;
}

int Flights::_4getNumCountriesCountry(std::string country ) {
    vector<Airports> res = _4getVecCountriesCountry(country);
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
            auto airport = flights.findVertex(v.first->getInfo());
            auto it = set_t.find(airport->getInfo().getCode());

            if(it == set_t.end()){
                set_t.insert(airport->getInfo().getCode());
                res.push_back(airport->getInfo().getName());
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

vector<Airports> Flights::_6getVecStopsCities(std::string code, int x ) {
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
            auto airport = flights.findVertex(v.first->getInfo());
            auto it = set_t.find(airport->getInfo().getCity());
            if(it == set_t.end()){
                set_t.insert(airport->getInfo().getCity());
                res.push_back(airport->getInfo().getCity());
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

int Flights::_6getIntStopsCities(std::string code, int x ) {
    vector<Airports> res = this->_6getVecStopsCities(code, x);
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
            auto airport = flights.findVertex(v.first->getInfo());
            auto it = set_t.find(airport->getInfo().getCountry());
            if(it == set_t.end()){
                set_t.insert(airport->getInfo().getCountry());
                res.push_back(airport->getInfo().getCountry());
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

                auto air_1 = flights.findVertex(vertex->getInfo());
                auto air_2 = flights.findVertex(pair.first->getInfo());

                t = AirportsGreatDistance(air_2->getInfo(), air_1->getInfo(), diameter);
                res.push_back(t);
            }
            else if(pair.second == diameter){
                auto air_1 =flights.findVertex(vertex->getInfo());
                auto air_2 = flights.findVertex(pair.first->getInfo());

                t = AirportsGreatDistance(air_1->getInfo(), air_2->getInfo(), diameter);
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
        auto airport_1 = flights.findVertex(vertex->getInfo());
        auto it_1 = find(res.begin(), res.end(), airport_1->getInfo());

        if(it_1 == res.end()){
            AirportsTrafic airportsTrafic_1 = AirportsTrafic(airport_1->getInfo(), 0);
            res.push_back(airportsTrafic_1);
        }
        for(auto edge : vertex->getAdj()){
            auto airport_2 = flights.findVertex(edge.getDest()->getInfo());
            auto it_2 = std::find(res.begin(), res.end(), airport_2->getInfo());

            if(it_2 == res.end()){
                AirportsTrafic airportsTrafic_2 = AirportsTrafic(airport_2->getInfo(), 0);
                res.push_back(airportsTrafic_2);
            }

            it_1 = std::find(res.begin(), res.end(), airport_1->getInfo());
            it_2 = std::find(res.begin(), res.end(), airport_2->getInfo());

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
    stack<Vertex<Airports>*> s;
    set<Vertex<Airports>*> inStack;
    bool first = true;
    int i = 1;

    for (auto &vertex : flights.getVertexSet()) {
        vertex->setVisited(false);
        vertex->setLow(0);
        vertex->setNum(0);
    }

    for (auto vertex : flights.getVertexSet()) {
        if(!vertex->isVisited()) {
            _9Auxiliar(vertex, s, res, i, inStack, first);
            first = false;
        }
    }

    return res;
}

void Flights::_9Auxiliar(Vertex<Airports> *vertex, stack<Vertex<Airports>*> &s, set<Airports> &res, int &i, set<Vertex<Airports>*> &inStack, bool first) {
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
            _9Auxiliar(w, s, res, i, inStack, first);
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

int Flights::_9numArticulations() {
    set<Airports> res = _9Articulations();
    return res.size();
}

list<AirportStop> Flights::_10BestPathEntreDoisAeroportos(Vertex<Airports>* src, Vertex<Airports>* dest) {
    list<AirportStop> res;
    AirportStop t;

    unordered_map<Vertex<Airports>* , int> paragens;
    unordered_map<Vertex<Airports>*, Vertex<Airports>*> previo;

    queue<Vertex<Airports>*> fila;

   /* for(auto& vertex : this->flights.getVertexSet()){
        paragens[vertex] = -1;
        previo[vertex] = nullptr;
    }
*/
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
    Airports airport_1;
    Airports airport_2;
    Airlines airlines;

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
                    airlines = edge.getAirline();
                }
            }


            t = AirportStop(air_1->getInfo(), air_2->getInfo(), airlines);
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

vector<list<AirportStop>> Flights::_10Commander(vector<Vertex<Airports> *> src, vector<Vertex<Airports> *> dest) {
    bool flag = true;
    list<AirportStop> t_1;
    list<AirportStop> t_2;
    vector<list<AirportStop>> res;


    for(int i = 0; i < src.size(); i++){
        auto a = src.at(i);
        auto b = src.at(i);

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

vector<Vertex<Airports>*> Flights::_10AirportsCity(string city){
    vector<Vertex<Airports>*> res;

    for(auto vertex : flights.getVertexSet()){
        if(vertex->getInfo().getCity() == city){
            res.push_back(vertex);
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

