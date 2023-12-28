#include <iostream>
#include <list>
#include "Menu.h"
/*#include "Flights.h"
#include "Airports.h"*/


using namespace std;

int Menu::Terminal(Flights flights, HashAirports hashAirports, HashAirlines hashAirlines) {

    int cap;

    cout << endl;
    cout << "\033[1;34m ______    __        __    ______    __   __   ________         _______           _______    ______    _____     __       ___\033[0m";
    cout << endl;
    cout << "\033[1;34m|  ____|  |  |      |  |  |  ____|  |  | |  | |___  ___|       |  ___  |         |  ___  |  |  ____|  |  ___ |  |  |     /   |\033[0m";
    cout << endl;
    cout << "\033[1;34m|  |___   |  |      |  |  |  | __   |  |_|  |    |  |    ___   |  | |  |   ___   |  |_|  |  |  |___   |  | | |  |  |    / _  |\033[0m";
    cout << endl;
    cout << "\033[1;34m|  ____|  |  |      |  |  |  ||_ |  |   _   |    |  |   |___|  |  | |  |  |___|  |  _____|  |  ____|  |  | | |  |  |   / /_| |\033[0m";
    cout << endl;
    cout << "\033[1;34m|  |      |  |___   |  |  |  |__||  |  | |  |    |  |          |  |_|  |         |  |       |  |___   |  |_/ /  |  |  / ___  |\033[0m";
    cout << endl;
    cout << "\033[1;34m|__|      |______|  |__|  |______|  |__| |__|    |__|          |_______|         |__|       |______|  |_____/   |__| /_/  |__|\033[0m";
    cout << endl;
    cout << endl;

    cout << "\033[1;34mPlease choose your desired functionality:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Statistics" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Best flight options" << endl;
    cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    int decision;
    cin >> decision;
    cout << endl;

    string code;
    int code_aux;
    /*list<AirportsGreatDistance> aux;
    vector<AirportsTrafic> frango;
    set<Airports>*/

    while (true) {

        switch (decision) {
            case 1:

                cout << "\033[1;36m[ 1 ]\033[0m" << " Global number of airports and number of available flights" << endl;
                cout << "\033[1;36m[ 2 ]\033[0m" << " Number of flights out of an airport and from how many different airlines" << endl;
                cout << "\033[1;36m[ 3 ]\033[0m" << " Number of flights per city, airline or country" << endl;
                cout << "\033[1;36m[ 4 ]\033[0m" << " Number of different countries that a given airport, city  or country flies to" << endl;
                cout << "\033[1;36m[ 5 ]\033[0m" << " Number of destinations (airports, cities or countries) available for a given airport" << endl;
                cout << "\033[1;36m[ 6 ]\033[0m" << " Number of reachable destinations (airports, cities or countries) from a given airport in a maximum number of X stops (lay-overs)" << endl;
                cout << "\033[1;36m[ 7 ]\033[0m" << " Flight trip(s) with the greatest number of stops in between them" << endl;
                cout << "\033[1;36m[ 8 ]\033[0m" << " Identify the top-k airport with the greatest number of flights" << endl;
                cout << "\033[1;36m[ 9 ]\033[0m" << " Identify the airports that are essential to the network’s circulation capability" << endl;
                cout << "\033[1;31m[ 0 ]\033[0m" << " Go back" << endl;
                cout << endl;

                cout << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                switch (decision) {
                    case 1:

                        cout<<"Numero de airports da rede "<< hashAirports._1numAirports()<<endl;
                        cout<<"Numero de viagens da rede "<< flights._1numViajens()<<endl;

                        break;

                    case 2:

                        cout << "\033[1;34mWhich airport? \033[0m";
                        cin >> code;
                        cout << endl;

                        cout << flights._2numViajensDeAirlines(code) << endl;
                        cout << flights._2numViajensDeAirport(code) << endl;

                        /*cout << "\033[1;32mThere are a total of \033[0m" << Flights::_2numViajensDeAirport(code) << "\033[1;32m flights from \033[0m" << Flights::_2numViajensDeAirlines(code) << "\033[1;32m different airlines in \033[0m" << code << endl;*/

                        break;

                    case 3:
                        cout << "\033[1;33m[ 1 ]\033[0m" << " City" << endl;
                        cout << "\033[1;33m[ 2 ]\033[0m" << " Airline" << endl;
                        cout << "\033[1;33m[ 3 ]\033[0m" << " Country" << endl;
                        cout << "\033[1;31m[ 0 ]\033[0m" << " Go back" << endl;
                        cout << endl;

                        cout << "\033[1;34mDecision: \033[0m";
                        cin >> decision;
                        cout << endl;

                        switch (decision) {
                            case 1:

                                cout << "\033[1;34mWhich city? \033[0m";
                                cin >> code;
                                cout << endl;

                                cout << flights._3getFlightsPerCompany(code);
                                /*cout << "\033[1;32mThere are a total of \033[0m" << Flights::_3getFlightsPerCity(code) << "\033[1;32m flights in \033[0m" << code << endl;*/

                                break;

                            case 2:

                                //especificar o pais

                                cout << "\033[1;34mWhich airline? \033[0m";
                                cin >> code;
                                cout << endl;
                                string country = "Portugal";

                                cout << flights._3getFlightsPerCity(code, "k");
                                cout << flights._3getFlightsPerCity(code, country);

                                /*cout << "\033[1;32mThere are a total of \033[0m" << Flights::_3getFlightsPerCompany(code) << "\033[1;32m flights from the airline \033[0m" << code << endl;*/

                                break;

                            case 3:

                                cout << "\033[1;34mWhich country? \033[0m";
                                cin >> code;
                                cout << endl;

                                cout << flights._3getFlightsPerCountry(code);

                                /*cout << "\033[1;32mThere are a total of \033[0m" << Flights::_3getFlightsPerCountry(code) << "\033[1;32m flights in \033[0m" << code << endl;*/

                                break;

                            case 0:

                                break;

                            default:

                                cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                break;
                        }

                        break;

                    case 4:

                        cout << "\033[1;33m[ 1 ]\033[0m" << " City" << endl;
                        cout << "\033[1;33m[ 2 ]\033[0m" << " Airport" << endl;
                        cout << "\033[1;33m[ 3 ]\033[0m" << " Country" << endl;
                        cout << "\033[1;31m[ 0 ]\033[0m" << " Go back" << endl;
                        cout << endl;

                        cout << "\033[1;34mDecision: \033[0m";
                        cin >> decision;
                        cout << endl;

                        switch (decision) {
                            case 1:
                                //aparecer se ele quer que imprima a lista ou não

                                cout << "\033[1;34mWhich city? \033[0m";
                                cin >> code;
                                cout << endl;

                                auto res = flights._4getVecCountriesAirport(code);
                                for(auto air : res){
                                    cout << air.getCode() << ", " << air.getName() << ", " << air.getCity() << ", " << air.getCountry() << endl;
                                }

                                cout << "------------------------------\n";
                                cout << "Total: " << res.size() << endl;

                                /*cout << Flights::_4getNumCountriesCity(code) << "\033[1;32m different countries flown to from city \033[0m" << code << endl;*/

                                break;

                            case 2:
                                cout << "\033[1;34mWhich airport? \033[0m";
                                cin >> code;
                                cout << endl;

                                res = flights._4getVecCountriesCity(code, "k");
                                for(auto air : res){
                                    cout << air.getCode() << ", " << air.getName() << ", " << air.getCity() << ", " << air.getCountry() << endl;
                                }

                                /*cout << Flights::_4getNumCountriesAirport(code) << "\033[1;32m different countries flown to from airport \033[0m" << code << endl;*/

                                break;

                            case 3:

                                cout << "\033[1;34mWhich country? \033[0m";
                                cin >> code;
                                cout << endl;

                                res = flights._4getVecCountriesCountry(code);
                                for(auto air : res){
                                    cout << air.getCode() << ", " << air.getName() << ", " << air.getCity() << ", " << air.getCountry() << endl;
                                }

                                /*cout << Flights::_4getNumCountriesCountry(code) << "\033[1;32m different countries flown to from country \033[0m" << code << endl;*/

                                break;

                            case 0:

                                break;

                            default:

                                cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                break;
                        }

                        break;

                    case 5:
                        //separar como no 4
                        cout << "\033[1;34mWhich airport? \033[0m";
                        cin >> code;
                        cout << endl;

                        auto res = flights._5Airports_per_airport(code);
                        for(auto air : res){
                            cout << air.getCode() << ", " << air.getName() << ", " << air.getCity() << ", " << air.getCountry() << endl;
                        }

                        res = flights._5Cities_per_airport(code, "k");
                        for(auto air : res){
                            cout << air.getCode() << ", " << air.getName() << ", " << air.getCity() << ", " << air.getCountry() << endl;
                        }

                        res = flights._5Countries_per_airport(code);
                        for(auto air : res){
                            cout << air.getCode() << ", " << air.getName() << ", " << air.getCity() << ", " << air.getCountry() << endl;
                        }

                        /*cout << "\033[1;32mThere are \033[0m" << Flights::Airports_per_airport(code) << "\033[1;32m airports, \033[0m" << Flights::Cities_per_airport(code) << "\033[1;32m cities and \033[0m" << Flights::Countries_per_airport(code) << "\033[1;32m countries available as destinations from airport \033[0m" << code << endl;*/

                        break;

                    case 6:
                        //separar como no 4 e 5
                        cout << "\033[1;34mWhich airport? \033[0m";
                        cin >> code;
                        cout << endl;
                        cout << "\033[1;34mHow many lay-overs? \033[0m";
                        cin >> code_aux;
                        cout << endl;

                        res = flights._6getVecStopsAirports(code, code_aux);
                        for(auto air : res){
                            cout << air.getCode() << ", " << air.getName() << ", " << air.getCity() << ", " << air.getCountry() << endl;
                        }

                        res = flights._6getVecStopsCities(code, code_aux, "k");
                        for(auto air : res){
                            cout << air.getCode() << ", " << air.getName() << ", " << air.getCity() << ", " << air.getCountry() << endl;
                        }

                        res = flights._6getVecStopsCountries(code, code_aux);
                        for(auto air : res){
                            cout << air.getCode() << ", " << air.getName() << ", " << air.getCity() << ", " << air.getCountry() << endl;
                        }

                        /*cout << "\033[1;32mThere are \033[0m" << Flights::_6getIntStopsAirports(code, code_aux    ) << "\033[1;32m airports, \033[0m" << Flights::_6getIntStopsCities(code, code_aux) << "\033[1;32m cities and \033[0m" << Flights::_6getIntStopsCountries(code, code_aux) << "\033[1;32m countries available as destinations from airport \033[0m" << code << "\033[1;32m in \033[0m" << code_aux << "\033[1;32m lay-overs\033[0m" << endl;*/

                        break;

                    case 7:

                        list<AirportsGreatDistance> test = flights._7getAirportsGreat();
                        for(auto air : test){
                            cout << air.airport_source.getCode() << ", " << air.airport_source.getName() << ", " << air.airport_source.getCity() << ", " << air.airport_source.getCountry() << endl;
                            cout << air.airport_dest.getCode() << ", " << air.airport_dest.getName() << ", " << air.airport_dest.getCity() << ", " << air.airport_dest.getCountry() << endl;
                            cout << "-------------------\n";
                            cout << air.distance;
                        }

                        /*aux = _7getAirportsGreat();
                        while (!aux.empty()) {
                            cout << "\033[1;32mTrip from \033[0m" << aux[0].first << "\033[1;32m to \033[0m" << aux[0].second << endl;
                            aux.remove(aux[0]);
                        }*/

                        break;

                    case 8:

                        //perguntar se quer o top em ordem ascendete ou descendente

                        cout << "\033[1;34mHow many airports do you wish to be presented with? \033[0m";
                        cin >> code_aux;
                        cout << endl;

                        vector<AirportsTrafic> t = flights._8getTopVecDescAirports();

                        for(int i = 0; i < code_aux; i++){
                            cout << t.at(i).trafic.first.getCode() << ", " << t.at(i).trafic.first.getName() << ", " << t.at(i).trafic.first.getCity() << ", " << t.at(i).trafic.first.getCountry() << endl;
                            cout << t.at(i).trafic.second << endl;
                        }

                        t = flights._8getTopVecAscAirports();

                        for(int i = 0; i < code_aux; i++){
                            cout << t.at(i).trafic.first.getCode() << ", " << t.at(i).trafic.first.getName() << ", " << t.at(i).trafic.first.getCity() << ", " << t.at(i).trafic.first.getCountry() << endl;
                            cout << t.at(i).trafic.second << endl;
                        }

                        /*frango = _8getTopVecAirports();

                        for (int i = 0; i < code_aux; i++) {
                            cout << frango[i] << endl;
                        }*/

                        break;

                    case 9:

                        //imprimir o set de aeroportos e perguntar se ele so quer o numero<3

                        auto y = flights._9Articulations();

                        for(auto air: y){
                            cout << air.getCode() << ", " << air.getName() << ", " << air.getCity() << ", " << air.getCountry() << endl;
                        }

                        cout << "--------\n";
                        cout << y.size() << endl;

                        break;

                    case 0:

                        break;

                    default:

                        cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                        break;
                }

                break;

            case 2:

                cout << "\033[1;33m[ 1 ]\033[0m" << " Without filters" << endl;
                cout << "\033[1;33m[ 2 ]\033[0m" << " With filters" << endl;
                cout << endl;

                cout << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                switch (decision) {
                    case 1:
                        vector<Vertex<Airports>*> src;
                        vector<Vertex<Airports>*> dest;

                        //Decedir a forma de começo
                        //1- receber o aeroporto, depois perguntar se quer code ou name
                        src = flights._10AirportsAirport("OPO", true);

                        //2- receber cidade, depois se quer especificar o pais da cidade escolhida
                        src = flights._10AirportsCity("Porto", "k");

                        //3- receber pais
                        src = flights._10AirportsPais("Portugal");

                        //4- receber coordenadas, string lat e string long, de seguida vai perguntar se quer raio ou nao, se quiser perguntar pelo raio
                        src = flights._10AirportsCoord("-13920,2190812093", "281,1291236");
                        src = flights._10AirportsCoordRaio("-13920,2190812093", "281,1291236", 10);

                        //5- back


                        //Decedir a forma de fim
                        //1- receber o aeroporto, depois perguntar se quer code ou name
                        dest = flights._10AirportsAirport("OPO", true);

                        //2- receber cidade, depois se quer especificar o pais da cidade escolhida
                        dest = flights._10AirportsCity("Porto", "k");

                        //3- receber pais
                        dest = flights._10AirportsPais("Portugal");

                        //4- receber coordenadas, string lat e string long, de seguida vai perguntar se quer raio ou nao, se quiser perguntar pelo raio
                        //5- back

                        //depois destes dois passos fazer o q vem asseguir

                        dest = flights._10AirportsCoord("-13920,2190812093", "281,1291236");
                        dest = flights._10AirportsCoordRaio("-13920,2190812093", "281,1291236", 10);

                        pair<vector<Vertex<Airports> *>, vector<Vertex<Airports> *>> p = flights._10Montador(src, dest);
                        auto l = flights._10Commander(p.first, p.second);


                        for(auto k : l){
                            for(auto air : k){
                                cout << air.src.getCode() << ", " << air.src.getName() << ", " << air.src.getCity() << ", " << air.src.getCountry() << endl;

                            }
                        }


                        break;

                    case 2:


                        break;

                }

                break;

            case 0:

                cerr << "Program closed" << endl;
                return 0;

            default:

                cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                break;
        }

        cout << "\033[1;34mWish to do anything else?\033[0m\n";
        cout << "\033[1;36m[ 1 ]\033[0m" << " Statistics" << endl;
        cout << "\033[1;36m[ 2 ]\033[0m" << " Best flight options" << endl;
        cout << "\033[0;31m[ 0 ]\033[0m" << "\033[0;31m Quit\033[0m" << endl;
        cout << endl;

        cout << "\033[1;34mDecision: \033[0m";
        cin >> decision;
        cout << endl;
    }
}
