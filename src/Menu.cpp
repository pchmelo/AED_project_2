#include <iostream>
#include <list>
#include "Menu.h"
/*#include "Flights.h"
#include "Airports.h"*/


using namespace std;

int Menu::Terminal(Flights flights, HashAirports hashAirports, HashAirlines hashAirlines) {

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
    int sec_code_aux;
    int tr_code_aux;
    string lat;
    string lon;
    string country;
    string answer;
    vector<Airports> vec;
    list<AirportsGreatDistance> grt;
    vector<AirportsTrafic> top;
    set<Airports> port;
    bool check = false;
    int ddd = 0;

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
                cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                cout << endl;

                cout << "\033[1;34mDecision: \033[0m";
                cin >> decision;
                cout << endl;

                switch (decision) {
                    case 1:

                        code_aux = hashAirports._1numAirports();
                        sec_code_aux = flights._1numViajens();

                        cout << "\033[1;32mThere are a total of \033[0m" << code_aux << "\033[1;32m airports on the network\033[0m" << endl;
                        cout << "\033[1;32mThere are a total of \033[0m" << sec_code_aux << "\033[1;32m available flights on the network\033[0m" << endl;
                        cout << endl;

                        if (code_aux == 0 || sec_code_aux == 0) {
                            cout << "\033[1;33mThere is a possibility that the input given was misspelled and thus giving a wrong output\033[0m" << endl;
                            cout << endl;
                        }

                        break;

                    case 2:

                        cout << "\033[1;34mWhich airport? \033[0m";
                        getline(cin >> ws, code);
                        cout << endl;

                        code_aux = flights._2numViajensDeAirport(code);
                        sec_code_aux = flights._2numViajensDeAirlines(code);

                        cout << "\033[1;32mThere are a total of \033[0m" << code_aux << "\033[1;32m flights from \033[0m" << sec_code_aux << "\033[1;32m different airlines in airport \033[0m" << code << endl;
                        cout << endl;

                        if (code_aux == 0 || sec_code_aux == 0) {
                            cout << "\033[1;33mThere is a possibility that the input given was misspelled and thus giving a wrong output\033[0m" << endl;
                            cout << endl;
                        }

                        break;

                    case 3:
                        cout << "\033[1;33m[ 1 ]\033[0m" << " Airline" << endl;
                        cout << "\033[1;33m[ 2 ]\033[0m" << " City" << endl;
                        cout << "\033[1;33m[ 3 ]\033[0m" << " Country" << endl;
                        cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                        cout << endl;

                        cout << "\033[1;34mDecision: \033[0m";
                        cin >> decision;
                        cout << endl;

                        switch (decision) {
                            case 1:

                                cout << "\033[1;34mWhich airline? \033[0m";
                                getline(cin >> ws, code);
                                cout << endl;

                                code_aux = flights._3getFlightsPerCompany(code);

                                cout << "\033[1;32mThere are a total of \033[0m" << code_aux << "\033[1;32m flights from the airline \033[0m" << code << endl;
                                cout << endl;

                                if (code_aux == 0) {
                                    cout << "\033[1;33mThere is a possibility that the input given was misspelled and thus giving a wrong output\033[0m" << endl;
                                    cout << endl;
                                }

                                break;

                            case 2:

                                cout << "\033[1;34mWhich city? \033[0m";
                                getline(cin >> ws, code);
                                cout << endl;

                                cout << "\033[1;34mWould you like to specify a country? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                                cin >> answer;
                                cout << endl;

                                if (answer == "y" || answer == "Y") {

                                    cout << "\033[1;34mWhich country? \033[0m";
                                    cin >> country;
                                    cout << endl;

                                } else if (answer == "n" || answer == "N") {

                                    country = "k";

                                } else {

                                    cout << "\033[1;31mUnrecognised option - Continuing with no country specification\033[0m";
                                    cout << endl;
                                    cout <<endl;

                                }

                                code_aux = flights._3getFlightsPerCity(code, country);

                                cout << "\033[1;32mThere are a total of \033[0m" << code_aux << "\033[1;32m flights in \033[0m" << code << endl;
                                cout << endl;

                                if (code_aux == 0) {
                                    cout << "\033[1;33mThere is a possibility that the input given was misspelled and thus giving a wrong output\033[0m" << endl;
                                    cout << endl;
                                }

                                break;

                            case 3:

                                cout << "\033[1;34mWhich country? \033[0m";
                                getline(cin >> ws, code);
                                cout << endl;

                                code_aux = flights._3getFlightsPerCountry(code);

                                cout << "\033[1;32mThere are a total of \033[0m" << code_aux << "\033[1;32m flights in \033[0m" << code << endl;
                                cout << endl;

                                if (code_aux == 0) {
                                    cout << "\033[1;33mThere is a possibility that the input given was misspelled and thus giving a wrong output\033[0m" << endl;
                                    cout << endl;
                                }

                                break;

                            case 0:

                                break;

                            default:

                                cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                cout <<endl;
                                country = "k";
                                break;
                        }

                        break;

                    case 4:

                        cout << "\033[1;33m[ 1 ]\033[0m" << " Airport" << endl;
                        cout << "\033[1;33m[ 2 ]\033[0m" << " City" << endl;
                        cout << "\033[1;33m[ 3 ]\033[0m" << " Country" << endl;
                        cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                        cout << endl;

                        cout << "\033[1;34mDecision: \033[0m";
                        cin >> decision;
                        cout << endl;

                        switch (decision) {
                            case 1:

                                cout << "\033[1;34mWhich airport? \033[0m";
                                getline(cin >> ws, code);
                                cout << endl;

                                cout << "\033[1;34mWould you like to be presented with a list of the possible countries of destination? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                                cin >> answer;
                                cout << endl;

                                port = flights._4getVecCountriesAirport(code);

                                if (answer == "y" || answer == "Y") {

                                    for(auto air : port){
                                        cout << air.getCountry() << endl; //Pode haver países repetidos, a 4 na descrição do projeto é mostrar países não aeroportos
                                    }
                                    cout <<endl;

                                } else if (answer == "n" || answer == "N") {

                                } else {

                                    cout << "\033[1;31mUnrecognised option - Continuing with no list\033[0m";
                                    cout <<endl;
                                    cout << endl;

                                }

                                cout << "\033[1;32mTotal number of possible countries of destination is \033[0m" << port.size() << endl;
                                cout << endl;
                                break;

                            case 2:

                                cout << "\033[1;34mWhich city? \033[0m";
                                getline(cin >> ws, code);
                                cout << endl;

                                cout << "\033[1;34mWould you like to specify a country? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                                cin >> answer;
                                cout << endl;

                                if (answer == "y" || answer == "Y") {

                                    cout << "\033[1;34mWhich country? \033[0m";
                                    cin >> country;
                                    cout << endl;

                                } else if (answer == "n" || answer == "N") {

                                    country = "k";

                                } else {

                                    cout << "\033[1;31mUnrecognised option - Continuing with no country specification\033[0m";
                                    cout <<endl;
                                    country = "k";
                                    cout << endl;

                                }

                                port = flights._4getVecCountriesCity(code, country);

                                cout << "\033[1;34mWould you like to be presented with a list of the possible countries of destination? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                                cin >> answer;
                                cout << endl;

                                if (answer == "y" || answer == "Y") {

                                    for(auto air : port){
                                        cout << air.getCountry() << endl; //Pode haver países repetidos, a 4 na descrição do projeto é mostrar países não aeroportos
                                    }
                                    cout <<endl;

                                } else if (answer == "n" || answer == "N") {


                                } else {

                                    cout << "\033[1;31mUnrecognised option - Continuing with no list\033[0m";
                                    cout <<endl;
                                    cout << endl;

                                }

                                cout << "\033[1;32mTotal number of possible countries of destination is \033[0m" << port.size() << endl;

                                break;

                            case 3:

                                cout << "\033[1;34mWhich country? \033[0m";
                                getline(cin >> ws, code);
                                cout << endl;

                                port = flights._4getVecCountriesCountry(code);

                                cout << "\033[1;34mWould you like to be presented with a list of the possible countries of destination? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                                cin >> answer;
                                cout << endl;

                                if (answer == "y" || answer == "Y") {

                                    for(auto air : port){
                                        cout << air.getCountry() << endl; //Pode haver países repetidos, a 4 na descrição do projeto é mostrar países não aeroportos
                                    }
                                    cout <<endl;

                                } else if (answer == "n" || answer == "N") {


                                } else {

                                    cout << "\033[1;31mUnrecognised option - Continuing with no list\033[0m";
                                    cout <<endl;
                                    cout << endl;

                                }

                                cout << "\033[1;32mTotal number of possible countries of destination is \033[0m" << port.size() << endl;
                                cout << endl;
                                break;

                            case 0:

                                break;

                            default:

                                cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                cout <<endl;
                                break;
                        }

                        break;

                    case 5:

                        cout << "\033[1;34mWhich airport as origin? \033[0m";
                        getline(cin >> ws, code);
                        cout << endl;

                        cout << "\033[1;34mWhich elements would you like to see as available destinations? \033[0m" << endl;
                        cout << "\033[1;33m[ 1 ]\033[0m" << " Airports" << endl;
                        cout << "\033[1;33m[ 2 ]\033[0m" << " Cities" << endl;
                        cout << "\033[1;33m[ 3 ]\033[0m" << " Countries" << endl;
                        cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                        cout << endl;

                        cout << "\033[1;34mDecision: \033[0m";
                        cin >> decision;
                        cout << endl;

                        switch (decision) {
                            case 1:

                                cout << "\033[1;34mWould you like to be presented with a list of the available airports of destination? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                                cin >> answer;
                                cout << endl;

                                vec = flights._5Airports_per_airport(code);

                                if (answer == "y" || answer == "Y") {

                                    for(auto air : vec){
                                        cout << air.getName() << "\033[1;32m airport of code \033[0m" << air.getCode() << endl;
                                    }
                                    cout << endl;

                                } else if (answer == "n" || answer == "N") {

                                } else {

                                    cout << "\033[1;31mUnrecognised option - Continuing with no list\033[0m";
                                    cout <<endl;
                                    cout << endl;

                                }

                                cout << "\033[1;32mTotal number of available airports of destination is \033[0m" << vec.size() << endl << endl;

                                break;

                            case 2:

                                vec = flights._5Cities_per_airport(code, country);

                                cout << "\033[1;34mWould you like to be presented with a list of the available cities of destination? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                                cin >> answer;
                                cout << endl;

                                if (answer == "y" || answer == "Y") {

                                    for(auto air : vec){
                                        cout << air.getCity() << endl;
                                    }
                                    cout << endl;

                                } else if (answer == "n" || answer == "N") {


                                } else {

                                    cout << "\033[1;31mUnrecognised option - Continuing with no list\033[0m";
                                    cout <<endl;
                                    cout << endl;

                                }

                                cout << "\033[1;32mTotal number of available cities of destination is \033[0m" << vec.size() << endl << endl;

                                break;

                            case 3:

                                vec = flights._5Countries_per_airport(code);

                                cout << "\033[1;34mWould you like to be presented with a list of the available countries of destination? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                                cin >> answer;
                                cout << endl;

                                if (answer == "y" || answer == "Y") {

                                    for(auto air : vec){
                                        cout << air.getCountry() << endl;
                                    }
                                    cout << endl;

                                } else if (answer == "n" || answer == "N") {


                                } else {

                                    cout << "\033[1;31mUnrecognised option - Continuing with no list\033[0m";
                                    cout <<endl;
                                    cout << endl;

                                }

                                cout << "\033[1;32mTotal number of available countries of destination is \033[0m" << vec.size() << endl << endl;

                                break;

                            case 0:

                                break;

                            default:

                                cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                cout <<endl;
                                break;
                        }

                        break;

                    case 6:

                        cout << "\033[1;34mWhich airport as origin? \033[0m";
                        getline(cin >> ws, code);
                        cout << endl;

                        cout << "\033[1;34mHow many lay-overs? \033[0m";
                        cin >> code_aux;
                        cout << endl;

                        cout << "\033[1;34mWhich elements would you like to see as available destinations? \033[0m" << endl;
                        cout << "\033[1;33m[ 1 ]\033[0m" << " Airports" << endl;
                        cout << "\033[1;33m[ 2 ]\033[0m" << " Cities" << endl;
                        cout << "\033[1;33m[ 3 ]\033[0m" << " Countries" << endl;
                        cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                        cout << endl;

                        cout << "\033[1;34mDecision: \033[0m";
                        cin >> decision;
                        cout << endl;

                        switch (decision) {
                            case 1:

                                cout << "\033[1;34mWould you like to be presented with a list of the available airports of destination? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                                cin >> answer;
                                cout << endl;

                                vec = flights._6getVecStopsAirports(code, code_aux);

                                if (answer == "y" || answer == "Y") {

                                    for(auto air : vec){
                                        cout << air.getName() << "\033[1;32m airport of code \033[0m" << air.getCode() << endl;
                                    }
                                    cout << endl;

                                } else if (answer == "n" || answer == "N") {


                                } else {

                                    cout << "\033[1;31mUnrecognised option - Continuing with no list\033[0m";
                                    cout <<endl;
                                    cout << endl;

                                }

                                cout << "\033[1;32mTotal number of available airports of destination is \033[0m" << vec.size() << endl;
                                cout << endl;

                                break;

                            case 2:

                                vec = flights._6getVecStopsCities(code, code_aux, country);

                                cout << "\033[1;34mWould you like to be presented with a list of the available cities of destination? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                                cin >> answer;
                                cout << endl;

                                if (answer == "y" || answer == "Y") {

                                    for(auto air : vec){
                                        cout << air.getCity() << endl;
                                    }
                                    cout << endl;

                                } else if (answer == "n" || answer == "N") {


                                } else {

                                    cout << "\033[1;31mUnrecognised option - Continuing with no list\033[0m";
                                    cout <<endl;
                                    cout << endl;

                                }

                                cout << "\033[1;32mTotal number of available cities of destination is \033[0m" << vec.size() << endl;
                                cout << endl;

                                break;

                            case 3:

                                vec = flights._6getVecStopsCountries(code, code_aux);

                                cout << "\033[1;34mWould you like to be presented with a list of the available countries of destination? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                                cin >> answer;
                                cout << endl;

                                if (answer == "y" || answer == "Y") {

                                    for(auto air : vec){
                                        cout << air.getCountry() << endl;
                                    }
                                    cout << endl;

                                } else if (answer == "n" || answer == "N") {


                                } else {

                                    cout << "\033[1;31mUnrecognised option - Continuing with no list\033[0m";
                                    cout <<endl;
                                    cout << endl;

                                }

                                cout << "\033[1;32mTotal number of available countries of destination is \033[0m" << vec.size() << endl;
                                cout << endl;

                                break;

                            case 0:

                                break;

                            default:

                                cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                cout <<endl;
                                break;
                        }

                        break;

                    case 7:

                        grt = flights._7getAirportsGreat();

                        code_aux = grt.size();
                        for(auto air : grt){

                            cout << "\033[1;32mFrom airport \033[0m" << air.airport_source.getName() << "\033[1;32m of code \033[0m" << air.airport_source.getCode() << "\033[1;32m in \033[0m" << air.airport_source.getCity() << "\033[1;32m, \033[0m" << air.airport_source.getCountry() << endl;
                            cout << "\033[1;32mTo airport \033[0m" << air.airport_dest.getName() << "\033[1;32m of code \033[0m" << air.airport_dest.getCode() << "\033[1;32m in \033[0m" << air.airport_dest.getCity() << "\033[1;32m, \033[0m" << air.airport_dest.getCountry() << endl;
                            ddd = air.distance;
                            cout << endl;
                            }

                        cout << "\033[1;32mWith a total of \033[0m" << code_aux  << "\033[1;32m airports\033[0m" << endl;
                        cout << "\033[1;32mWith a diameter of \033[0m" << ddd << endl;
                        cout << endl;


                        break;

                    case 8:

                        cout << "\033[1;34mHow many airports do you wish to be presented with? \033[0m";
                        cin >> code_aux;
                        cout << endl;

                        cout << "\033[1;34mWould you like the top to be organized in ascending or descending order? \033[0m" <<  endl;
                        cout << "\033[1;33m[ 1 ]\033[0m" << " Ascending" << endl;
                        cout << "\033[1;33m[ 2 ]\033[0m" << " Descending" << endl;
                        cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                        cout << endl;

                        cout << "\033[1;34mDecision: \033[0m";
                        cin >> decision;
                        cout << endl;

                        if (decision == 1) {
                            top = flights._8getTopVecAscAirports();
                        } else if (decision == 2) {
                            top = flights._8getTopVecDescAirports();
                        } else if (decision == 0) {
                            break;
                        } else {
                            cout << "\033[1;31mUnrecognised option - Continuing with ascending order\033[0m";
                            cout <<endl;
                            top = flights._8getTopVecAscAirports();
                            cout << endl;
                        }

                        for (int i = 0; i < code_aux; i++) {


                            cout << i+1 << "º" << "\033[1;33m- \033[0m";
                            cout << top.at(i).trafic.first.getName() << "\033[1;32m airport of code \033[0m" << top.at(i).trafic.first.getCode();
                            cout << "\033[1;32m with \033[0m" << top.at(i).trafic.second << "\033[1;32m flights\033[0m" << endl << endl;
                            cout << endl;
                        }

                        break;

                    case 9:

                        cout << "\033[1;34mWould you like to have the total number of airports as well? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                        cin >> answer;
                        cout << endl;

                        port = flights._9Articulations();

                        for (auto air: port) {
                            cout << "\033[1;32mAirport \033[0m" << air.getName() << "\033[1;32m of code \033[0m" << air.getCode() << "\033[1;32m in \033[0m" << air.getCity() << "\033[1;32m, \033[0m" << air.getCountry() << endl;
                        }
                        cout << endl;

                        if (answer == "y" || answer == "Y") {

                            cout << "\033[1;32mTotal number of airports is \033[0m" << port.size() << endl;
                            cout << endl;

                        } else if (answer == "n" || answer == "N") {


                        } else {

                            cout << "\033[1;31mUnrecognised option - No number presented\033[0m";
                            cout <<endl;
                            cout << endl;

                        }

                        break;

                    case 0:

                        break;

                    default:

                        cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                        cout <<endl;
                        break;
                }

                break;

            case 2:

                cout << "\033[1;34mWould you like to use filters for the search? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                cin >> answer;
                cout << endl;

                if (answer == "n" || answer == "N") {

                    vector<Vertex<Airports> *> src;
                    vector<Vertex<Airports> *> dest;

                    cout << "\033[1;34mWhat information would you like to give as origin? \033[0m" << endl;
                    cout << "\033[1;33m[ 1 ]\033[0m" << " Airport" << endl;
                    cout << "\033[1;33m[ 2 ]\033[0m" << " City" << endl;
                    cout << "\033[1;33m[ 3 ]\033[0m" << " Country" << endl;
                    cout << "\033[1;33m[ 4 ]\033[0m" << " Coordinates" << endl;
                    cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                    cout << endl;

                    cout << "\033[1;34mDecision: \033[0m";
                    cin >> decision;
                    cout << endl;

                    switch (decision) {
                        case 1:

                            cout << "\033[1;34mWill you be giving the airport code or name? \033[0m" << endl;
                            cout << "\033[1;33m[ 1 ]\033[0m" << " Code" << endl;
                            cout << "\033[1;33m[ 2 ]\033[0m" << " Name" << endl;
                            cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                            cout << endl;

                            cout << "\033[1;34mDecision: \033[0m";
                            cin >> decision;
                            cout << endl;

                            switch (decision) {
                                case 1:

                                    cout << "\033[1;34mWhich code? \033[0m";
                                    getline(cin >> ws, code);
                                    cout << endl;

                                    src = flights._10AirportsAirport(code, true);

                                    break;

                                case 2:

                                    cout << "\033[1;34mWhich name? \033[0m";
                                    getline(cin >> ws, code);
                                    cout << endl;

                                    src = flights._10AirportsAirport(code, false);

                                    break;

                                case 0:

                                    break;

                                default:

                                    cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                    cout <<endl;
                                    break;
                            }

                            break;

                        case 2:

                            cout << "\033[1;34mWhich city? \033[0m";
                            getline(cin >> ws, code);
                            cout << endl;

                            cout << "\033[1;34mWould you like to specify a country? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                            cin >> answer;
                            cout << endl;

                            if (answer == "y" || answer == "Y") {

                                cout << "\033[1;34mWhich country? \033[0m";
                                cin >> country;
                                cout << endl;

                            } else if (answer == "n" || answer == "N") {

                                country = "k";

                            } else {

                                cout << "\033[1;31mUnrecognised option - Continuing with no country specification\033[0m";
                                cout <<endl;
                                country = "k";
                                cout << endl;

                            }

                            src = flights._10AirportsCity(code, country);

                            break;

                        case 3:

                            cout << "\033[1;34mWhich country? \033[0m";
                            getline(cin >> ws, code);
                            cout << endl;

                            src = flights._10AirportsPais(code);

                            break;

                        case 4:

                            cout << "\033[1;34mWhich latitude? \033[0m";
                            cin >> lat;
                            cout << endl;

                            cout << "\033[1;34mWhich longitude? \033[0m";
                            cin >> lon;
                            cout << endl;

                            cout << "\033[1;34mWould you like to specify a radius of search? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                            cin >> answer;
                            cout << endl;

                            if (answer == "y" || answer == "Y") {

                                cout << "\033[1;34mHow long of a radius in kilometers? \033[0m";
                                cin >> tr_code_aux;
                                cout << endl;

                                src = flights._10AirportsCoordRaio(lat, lon, tr_code_aux);

                            } else if (answer == "n" || answer == "N") {

                                src = flights._10AirportsCoord(lat,lon);

                            } else {

                                cout << "\033[1;31mUnrecognised option - Continuing with no radius\033[0m";
                                cout <<endl;
                                src = flights._10AirportsCoord(lat,lon);
                                cout << endl;

                            }

                            break;

                        case 0:

                            check = true;
                            break;

                        default:

                            cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                            cout <<endl;
                            break;
                    }

                    if (check) {
                        check = false;
                        break;
                    }

                    cout << "\033[1;34mWhat information would you like to give as destination? \033[0m" << endl;
                    cout << "\033[1;33m[ 1 ]\033[0m" << " Airport" << endl;
                    cout << "\033[1;33m[ 2 ]\033[0m" << " City" << endl;
                    cout << "\033[1;33m[ 3 ]\033[0m" << " Country" << endl;
                    cout << "\033[1;33m[ 4 ]\033[0m" << " Coordinates" << endl;
                    cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                    cout << endl;

                    cout << "\033[1;34mDecision: \033[0m";
                    cin >> decision;
                    cout << endl;

                    switch (decision) {
                        case 1:

                            cout << "\033[1;34mWill you be giving the airport code or name? \033[0m" << endl;
                            cout << "\033[1;33m[ 1 ]\033[0m" << " Code" << endl;
                            cout << "\033[1;33m[ 2 ]\033[0m" << " Name" << endl;
                            cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                            cout << endl;

                            cout << "\033[1;34mDecision: \033[0m";
                            cin >> decision;
                            cout << endl;

                            switch (decision) {
                                case 1:

                                    cout << "\033[1;34mWhich code? \033[0m";
                                    getline(cin >> ws, code);
                                    cout << endl;

                                    dest = flights._10AirportsAirport(code, true);

                                    break;

                                case 2:

                                    cout << "\033[1;34mWhich name? \033[0m";
                                    getline(cin >> ws, code);
                                    cout << endl;

                                    dest = flights._10AirportsAirport(code, false);

                                    break;

                                case 0:

                                    break;

                                default:

                                    cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                    cout <<endl;
                                    break;
                            }

                            break;

                        case 2:

                            cout << "\033[1;34mWhich city? \033[0m";
                            getline(cin >> ws, code);
                            cout << endl;

                            cout << "\033[1;34mWould you like to specify a country? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                            cin >> answer;
                            cout << endl;

                            if (answer == "y" || answer == "Y") {

                                cout << "\033[1;34mWhich country? \033[0m";
                                cin >> country;
                                cout << endl;

                            } else if (answer == "n" || answer == "N") {

                                country = "k";

                            } else {

                                cout << "\033[1;31mUnrecognised option - Continuing with no country specification\033[0m";
                                cout <<endl;
                                country = "k";
                                cout << endl;

                            }

                            dest = flights._10AirportsCity(code, country);

                            break;

                        case 3:

                            cout << "\033[1;34mWhich country? \033[0m";
                            getline(cin >> ws, code);
                            cout << endl;

                            dest = flights._10AirportsPais(code);


                            break;

                        case 4:

                            cout << "\033[1;34mWhich latitude? \033[0m";
                            cin >> lat;
                            cout << endl;

                            cout << "\033[1;34mWhich longitude? \033[0m";
                            cin >> lon;
                            cout << endl;

                            cout << "\033[1;34mWould you like to specify a radius of search? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                            cin >> answer;
                            cout << endl;

                            if (answer == "y" || answer == "Y") {

                                cout << "\033[1;34mHow long of a radius in kilometers? \033[0m";
                                cin >> tr_code_aux;
                                cout << endl;

                                dest = flights._10AirportsCoordRaio(lat, lon, tr_code_aux);

                            } else if (answer == "n" || answer == "N") {

                                dest = flights._10AirportsCoord(lat, lon);

                            } else {

                                cout << "\033[1;31mUnrecognised option - Continuing with no radius\033[0m";
                                cout <<endl;
                                dest = flights._10AirportsCoord(lat, lon);
                                cout << endl;

                            }

                            break;

                        case 0:

                            check = true;
                            break;

                        default:

                            cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                            cout <<endl;
                            break;
                    }

                    if (check) {
                        check = false;
                        break;
                    }

                    cout << "\033[1;32mPossible airports used as origin: \033[0m" << endl << endl;
                    for (auto v : src) {
                        cout << v->getInfo().getName() << "\033[1;32m of code \033[0m" << v->getInfo().getCode() << endl;
                    }
                    cout << endl;

                    cout << "\033[1;32mPossible airports used as destinations: \033[0m" << endl << endl;
                    for (auto v : dest) {
                        cout << v->getInfo().getName() << "\033[1;32m of code \033[0m" << v->getInfo().getCode() << endl;
                    }
                    cout << endl;

                    bool chk;

                    cout << "\033[1;34mWould you like to have only the best option for each pair of airports? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                    cin >> answer;
                    cout << endl;

                    if (answer == "y" || answer == "Y") {
                        chk = true;
                    } else if (answer == "n" || answer == "N") {
                        chk = false;
                    } else {
                        cout << "\033[0;31mUnrecognized option - Proceeding with all options\033[0m" << endl;
                        chk = false;
                        cout <<endl;
                    }



                    //perguntar se ele quer todas as opções ou apenas uma


                    pair<vector<Vertex<Airports> *>, vector<Vertex<Airports> *>> mount = flights._10Montador(src, dest);

                    if (chk) {
                        auto stops = flights._10Commander(mount.first, mount.second);



                        int index = 1;

                        for (auto lsts: stops) {

                            cout << index << "\033[1;32mª opção\033[0m" << endl << endl;

                            for (auto air: lsts) {
                                cout << "\033[1;32mFrom airport \033[0m" << air.src->getInfo().getName() << "\033[1;32m of code \033[0m" << air.src->getInfo().getCode() << "\033[1;32m in \033[0m" << air.src->getInfo().getCity() << "\033[1;32m, \033[0m" << air.src->getInfo().getCountry() << endl;
                                cout << "\033[1;32mTo airport \033[0m" << air.dest->getInfo().getName() << "\033[1;32m of code \033[0m" << air.dest->getInfo().getCode() << "\033[1;32m in \033[0m" << air.dest->getInfo().getCity() << "\033[1;32m, \033[0m" << air.dest->getInfo().getCountry() << endl;
                                cout << "\033[1;32mWith airline \033[0m" << air.airlines.front().getName() << "\033[1;32m of code \033[0m" << air.airlines.front().getCode() << "\033[1;32m with call sign \033[0m" << air.airlines.front().getCallSign() << "\033[1;32m and from \033[0m" << air.airlines.front().getCountry() << endl;
                                cout<<endl;
                            }

                            index++;
                        }
                    } else if (!chk) {
                        auto res = flights._11AllCommander(mount.first, mount.second, {} , 0);

                        int ia = 1;

                        for (auto apoio: res) {
                            cout << ia << "ª opção\n";
                            for (auto air: apoio) {
                                cout << "\033[1;32mFrom airport \033[0m" << air.src->getInfo().getName()
                                     << "\033[1;32m of code \033[0m" << air.src->getInfo().getCode()
                                     << "\033[1;32m in \033[0m" << air.src->getInfo().getCity() << "\033[1;32m, \033[0m"
                                     << air.src->getInfo().getCountry() << endl;
                                cout << "\033[1;32mTo airport \033[0m" << air.dest->getInfo().getName()
                                     << "\033[1;32m of code \033[0m" << air.dest->getInfo().getCode()
                                     << "\033[1;32m in \033[0m" << air.dest->getInfo().getCity()
                                     << "\033[1;32m, \033[0m" << air.dest->getInfo().getCountry() << endl;
                                cout << endl << "\033[1;33mAvailable airlines for this trip: \033[0m" << endl;
                                for (auto b : air.airlines) {
                                    cout << "\033[1;32mWith airline \033[0m" << b.getName()
                                         << "\033[1;32m of code \033[0m" << b.getCode()
                                         << "\033[1;32m with call sign \033[0m" << b.getCallSign()
                                         << "\033[1;32m and from \033[0m" << b.getCountry() << endl;
                                }
                                cout << endl;
                            }
                            ia++;
                        }

                        if (res.size() == 1) {
                            cout << "\033[1;32mThere is \033[0m" << res.size() << "\033[1;32m option\033[0m\n";
                        } else {
                            cout << "\033[1;32mThere are \033[0m" << res.size() << "\033[1;32m options\033[0m\n";
                        }


                    }

                } else if (answer == "y" || answer == "Y") {

                    vector<Vertex<Airports> *> src;
                    vector<Vertex<Airports> *> dest;

                    cout << "\033[1;34mWhat information would you like to give as origin? \033[0m" << endl;
                    cout << "\033[1;33m[ 1 ]\033[0m" << " Airport" << endl;
                    cout << "\033[1;33m[ 2 ]\033[0m" << " City" << endl;
                    cout << "\033[1;33m[ 3 ]\033[0m" << " Country" << endl;
                    cout << "\033[1;33m[ 4 ]\033[0m" << " Coordinates" << endl;
                    cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                    cout << endl;

                    cout << "\033[1;34mDecision: \033[0m";
                    cin >> decision;
                    cout << endl;

                    switch (decision) {
                        case 1:

                            cout << "\033[1;34mWill you be giving the airport code or name? \033[0m" << endl;
                            cout << "\033[1;33m[ 1 ]\033[0m" << " Code" << endl;
                            cout << "\033[1;33m[ 2 ]\033[0m" << " Name" << endl;
                            cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                            cout << endl;

                            cout << "\033[1;34mDecision: \033[0m";
                            cin >> decision;
                            cout << endl;

                            switch (decision) {
                                case 1:

                                    cout << "\033[1;34mWhich code? \033[0m";
                                    getline(cin >> ws, code);
                                    cout << endl;

                                    src = flights._10AirportsAirport(code, true);

                                    break;

                                case 2:

                                    cout << "\033[1;34mWhich name? \033[0m";
                                    getline(cin >> ws, code);
                                    cout << endl;

                                    src = flights._10AirportsAirport(code, false);

                                    break;

                                case 0:

                                    break;

                                default:

                                    cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                    cout <<endl;
                                    break;
                            }

                            break;

                        case 2:

                            cout << "\033[1;34mWhich city? \033[0m";
                            getline(cin >> ws, code);
                            cout << endl;

                            cout << "\033[1;34mWould you like to specify a country? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                            cin >> answer;
                            cout << endl;

                            if (answer == "y" || answer == "Y") {

                                cout << "\033[1;34mWhich country? \033[0m";
                                cin >> country;
                                cout << endl;

                            } else if (answer == "n" || answer == "N") {

                                country = "k";

                            } else {

                                cout << "\033[1;31mUnrecognised option - Continuing with no country specification\033[0m";
                                cout <<endl;
                                country = "k";
                                cout << endl;

                            }

                            src = flights._10AirportsCity(code, country);

                            break;

                        case 3:

                            cout << "\033[1;34mWhich country? \033[0m";
                            getline(cin >> ws, code);
                            cout << endl;

                            src = flights._10AirportsPais(code);

                            break;

                        case 4:

                            cout << "\033[1;34mWhich latitude? \033[0m";
                            cin >> lat;
                            cout << endl;

                            cout << "\033[1;34mWhich longitude? \033[0m";
                            cin >> lon;
                            cout << endl;

                            cout << "\033[1;34mWould you like to specify a radius of search? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                            cin >> answer;
                            cout << endl;

                            if (answer == "y" || answer == "Y") {

                                cout << "\033[1;34mHow long of a radius in kilometers? \033[0m";
                                cin >> tr_code_aux;
                                cout << endl;

                                src = flights._10AirportsCoordRaio(lat, lon, tr_code_aux);

                            } else if (answer == "n" || answer == "N") {

                                src = flights._10AirportsCoord(lat, lon);

                            } else {

                                cout << "\033[1;31mUnrecognised option - Continuing with no radius\033[0m";
                                cout <<endl;
                                src = flights._10AirportsCoord(lat,lon);
                                cout << endl;

                            }

                            break;

                        case 0:

                            check = true;
                            break;

                        default:

                            cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                            cout <<endl;
                            break;
                    }

                    if (check) {
                        check = false;
                        break;
                    }

                    cout << "\033[1;34mWhat information would you like to give as destination? \033[0m" << endl;
                    cout << "\033[1;33m[ 1 ]\033[0m" << " Airport" << endl;
                    cout << "\033[1;33m[ 2 ]\033[0m" << " City" << endl;
                    cout << "\033[1;33m[ 3 ]\033[0m" << " Country" << endl;
                    cout << "\033[1;33m[ 4 ]\033[0m" << " Coordinates" << endl;
                    cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                    cout << endl;

                    cout << "\033[1;34mDecision: \033[0m";
                    cin >> decision;
                    cout << endl;

                    switch (decision) {
                        case 1:

                            cout << "\033[1;34mWill you be giving the airport code or name? \033[0m" << endl;
                            cout << "\033[1;33m[ 1 ]\033[0m" << " Code" << endl;
                            cout << "\033[1;33m[ 2 ]\033[0m" << " Name" << endl;
                            cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                            cout << endl;

                            cout << "\033[1;34mDecision: \033[0m";
                            cin >> decision;
                            cout << endl;

                            switch (decision) {
                                case 1:

                                    cout << "\033[1;34mWhich code? \033[0m";
                                    getline(cin >> ws, code);
                                    cout << endl;

                                    dest = flights._10AirportsAirport(code, true);

                                    break;

                                case 2:

                                    cout << "\033[1;34mWhich name? \033[0m";
                                    getline(cin >> ws, code);
                                    cout << endl;

                                    dest = flights._10AirportsAirport(code, false);

                                    break;

                                case 0:

                                    break;

                                default:

                                    cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                    cout <<endl;
                                    break;
                            }

                            break;

                        case 2:

                            cout << "\033[1;34mWhich city? \033[0m";
                            getline(cin >> ws, code);
                            cout << endl;

                            cout << "\033[1;34mWould you like to specify a country? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                            cin >> answer;
                            cout << endl;

                            if (answer == "y" || answer == "Y") {

                                cout << "\033[1;34mWhich country? \033[0m";
                                cin >> country;
                                cout << endl;

                            } else if (answer == "n" || answer == "N") {

                                country = "k";

                            } else {

                                cout << "\033[1;31mUnrecognised option - Continuing with no country specification\033[0m";
                                cout <<endl;
                                country = "k";
                                cout << endl;

                            }

                            dest = flights._10AirportsCity(code, country);

                            break;

                        case 3:

                            cout << "\033[1;34mWhich country? \033[0m";
                            getline(cin >> ws, code);
                            cout << endl;

                            dest = flights._10AirportsPais(code);

                            break;

                        case 4:

                            cout << "\033[1;34mWhich latitude? \033[0m";
                            cin >> lat;
                            cout << endl;

                            cout << "\033[1;34mWhich longitude? \033[0m";
                            cin >> lon;
                            cout << endl;

                            cout << "\033[1;34mWould you like to specify a radius of search? \033[0m" << "\033[1;33m[ Y / N ] \033[0m" << endl;
                            cin >> answer;
                            cout << endl;

                            if (answer == "y" || answer == "Y") {

                                cout << "\033[1;34mHow long of a radius in kilometers? \033[0m";
                                cin >> tr_code_aux;
                                cout << endl;

                                dest = flights._10AirportsCoordRaio(lat, lon, tr_code_aux);

                            } else if (answer == "n" || answer == "N") {

                                dest = flights._10AirportsCoord(lat, lon);

                            } else {

                                cout << "\033[1;31mUnrecognised option - Continuing with no radius\033[0m";
                                cout <<endl;
                                dest = flights._10AirportsCoord(lat,lon);
                                cout << endl;

                            }

                            break;

                        case 0:

                            check = true;
                            break;

                        default:

                            cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                            cout <<endl;
                            break;
                    }

                    if (check) {
                        check = false;
                        break;
                    }

                    set<string> lista_air;
                    int input = 0;
                    int num = 0;
                    bool min_check = false;

                    cout << "\033[1;34mWhat filter would you like to use? \033[0m" << endl;
                    cout << "\033[1;33m[ 1 ]\033[0m" << " Whitelist airlines" << endl;
                    cout << "\033[1;33m[ 2 ]\033[0m" << " Blacklist airlines" << endl;
                    cout << "\033[1;33m[ 3 ]\033[0m" << " Minimizer" << endl;
                    cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                    cout << endl;

                    cout << "\033[1;34mDecision: \033[0m";
                    cin >> decision;
                    cout << endl;

                    switch (decision) {
                        case 1:

                            input = 1;

                            while (true) {

                                cout << "\033[1;34mWill you be giving the airline code or name? \033[0m" << endl;
                                cout << "\033[1;33m[ 1 ]\033[0m" << " Code" << endl;
                                cout << "\033[1;33m[ 2 ]\033[0m" << " Name" << endl;
                                cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                                cout << endl;

                                cout << "\033[1;34mDecision: \033[0m";
                                cin >> decision;
                                cout << endl;

                                switch (decision) {
                                    case 1:

                                        cout << "\033[1;34mWhich code? \033[0m";
                                        getline(cin >> ws, code);
                                        cout << endl;

                                        lista_air.insert(code);

                                        break;

                                    case 2:

                                        cout << "\033[1;34mWhich name? \033[0m";
                                        getline(cin >> ws, code);
                                        cout << endl;
                                        code= hashAirlines._11CodeAirline(code);
                                        lista_air.insert(code);


                                        break;

                                    case 0:

                                        break;

                                    default:

                                        cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                        cout << endl;
                                        break;
                                }

                                cout << "\033[1;34mWould you like to whitelist another airline, use the minimizer filter or proceed to the result? \033[0m" << endl;
                                cout << "\033[1;33m[ 1 ]\033[0m" << " Whitelist airline" << endl;
                                cout << "\033[1;33m[ 2 ]\033[0m" << " Minimizer" << endl;
                                cout << "\033[1;33m[ 3 ]\033[0m" << " Result" << endl;
                                cout << endl;

                                cout << "\033[1;34mDecision: \033[0m";
                                cin >> decision;
                                cout << endl;

                                if (decision == 1) {

                                } else if (decision == 2) {
                                    min_check = true;
                                    break;
                                } else if (decision == 3) {
                                    break;
                                }

                            }

                            break;

                        case 2:

                            input = 2;

                            while (true) {

                                cout << "\033[1;34mWill you be giving the airline code or name? \033[0m" << endl;
                                cout << "\033[1;33m[ 1 ]\033[0m" << " Code" << endl;
                                cout << "\033[1;33m[ 2 ]\033[0m" << " Name" << endl;
                                cout << "\033[1;31m[ 0 ]\033[0m" << "\033[0;31m Go back\033[0m" << endl;
                                cout << endl;

                                cout << "\033[1;34mDecision: \033[0m";
                                cin >> decision;
                                cout << endl;

                                switch (decision) {
                                    case 1:

                                        cout << "\033[1;34mWhich code? \033[0m";
                                        getline(cin >> ws, code);
                                        cout << endl;

                                        lista_air.insert(code);

                                        break;

                                    case 2:

                                        cout << "\033[1;34mWhich name? \033[0m";
                                        getline(cin >> ws, code);
                                        cout << endl;

                                        lista_air.insert(code);

                                        break;

                                    case 0:

                                        break;

                                    default:

                                        cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                        cout << endl;
                                        break;
                                }

                                cout << "\033[1;34mWould you like to blacklist another airline, use the minimizer filter or proceed to the result? \033[0m" << endl;
                                cout << "\033[1;33m[ 1 ]\033[0m" << " Blacklist airline" << endl;
                                cout << "\033[1;33m[ 2 ]\033[0m" << " Minimizer" << endl;
                                cout << "\033[1;33m[ 3 ]\033[0m" << " Result" << endl;
                                cout << endl;

                                cout << "\033[1;34mDecision: \033[0m";
                                cin >> decision;
                                cout << endl;

                                if (decision == 1) {

                                } else if (decision == 2) {
                                    min_check = true;
                                    break;
                                } else if (decision == 3) {
                                    break;
                                }

                            }

                            break;

                        case 3:

                            min_check = true;
                            cout << "\033[1;34mWould you like to blacklist or whitelist airlines or proceed to result? \033[0m" << endl;
                            cout << "\033[1;33m[ 1 ]\033[0m" << " Blacklist airlines" << endl;
                            cout << "\033[1;33m[ 2 ]\033[0m" << " Whitelist airlines" << endl;
                            cout << "\033[1;33m[ 3 ]\033[0m" << " Result" << endl;
                            cout << endl;

                            cout << "\033[1;34mDecision: \033[0m";
                            cin >> decision;
                            cout << endl;

                            switch (decision) {
                                case 1:

                                    input = 2;

                                    while (true) {

                                        cout << "\033[1;34mWill you be giving the airline code or name? \033[0m" << endl;
                                        cout << "\033[1;33m[ 1 ]\033[0m" << " Code" << endl;
                                        cout << "\033[1;33m[ 2 ]\033[0m" << " Name" << endl;
                                        cout << endl;

                                        cout << "\033[1;34mDecision: \033[0m";
                                        cin >> decision;
                                        cout << endl;

                                        switch (decision) {
                                            case 1:

                                                cout << "\033[1;34mWhich code? \033[0m";
                                                getline(cin >> ws, code);
                                                cout << endl;

                                                lista_air.insert(code);

                                                break;

                                            case 2:

                                                cout << "\033[1;34mWhich name? \033[0m";
                                                getline(cin >> ws, code);
                                                cout << endl;

                                                lista_air.insert(code);

                                                break;

                                            default:

                                                cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                                cout << endl;
                                                break;
                                        }

                                        cout << "\033[1;34mWould you like to blacklist another airline or proceed to the result? \033[0m" << endl;
                                        cout << "\033[1;33m[ 1 ]\033[0m" << " Blacklist airline" << endl;
                                        cout << "\033[1;33m[ 2 ]\033[0m" << " Result" << endl;
                                        cout << endl;

                                        cout << "\033[1;34mDecision: \033[0m";
                                        cin >> decision;
                                        cout << endl;

                                        if (decision == 1) {

                                        } else if (decision == 2) {
                                            break;
                                        }

                                    }

                                    break;

                                case 2:

                                    input = 1;

                                    while (true) {

                                        cout << "\033[1;34mWill you be giving the airline code or name? \033[0m" << endl;
                                        cout << "\033[1;33m[ 1 ]\033[0m" << " Code" << endl;
                                        cout << "\033[1;33m[ 2 ]\033[0m" << " Name" << endl;
                                        cout << endl;

                                        cout << "\033[1;34mDecision: \033[0m";
                                        cin >> decision;
                                        cout << endl;

                                        switch (decision) {
                                            case 1:

                                                cout << "\033[1;34mWhich code? \033[0m";
                                                getline(cin >> ws, code);
                                                cout << endl;

                                                lista_air.insert(code);

                                                break;

                                            case 2:

                                                cout << "\033[1;34mWhich name? \033[0m";
                                                getline(cin >> ws, code);
                                                cout << endl;

                                                lista_air.insert(code);

                                                break;

                                            default:

                                                cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                                                cout << endl;
                                                break;
                                        }

                                        cout << "\033[1;34mWould you like to whitelist another airline or proceed to the result? \033[0m" << endl;
                                        cout << "\033[1;33m[ 1 ]\033[0m" << " Whitelist airline" << endl;
                                        cout << "\033[1;33m[ 2 ]\033[0m" << " Result" << endl;
                                        cout << endl;

                                        cout << "\033[1;34mDecision: \033[0m";
                                        cin >> decision;
                                        cout << endl;

                                        if (decision == 1) {

                                        } else if (decision == 2) {
                                            break;
                                        }

                                    }

                                    break;

                                case 3:

                                    break;

                                default:

                                    cout << "\033[0;31mUnrecognized option - Proceeding without any whitelisted or blacklisted airlines\033[0m" << endl;
                                    cout << endl;
                                    break;
                            }

                            break;

                        case 0:

                            check = true;
                            break;

                        default:

                            cout << "\033[0;31mUnrecognized option - using no filters\033[0m" << endl;
                            cout <<endl;
                            break;
                    }

                    if (check) {
                        check = false;
                        break;
                    }

                    cout << "\033[1;32mPossible airports used as origin: \033[0m" << endl << endl;
                    for (auto v : src) {
                        cout << v->getInfo().getName() << "\033[1;32m of code \033[0m" << v->getInfo().getCode() << endl;
                    }
                    cout << endl;

                    cout << "\033[1;32mPossible airports used as destinations: \033[0m" << endl << endl;
                    for (auto v : dest) {
                        cout << v->getInfo().getName() << "\033[1;32m of code \033[0m" << v->getInfo().getCode() << endl;
                    }
                    cout << endl;

                    pair<vector<Vertex<Airports> *>, vector<Vertex<Airports> *>> mount = flights._10Montador(src, dest);
                    auto res = flights._11AllCommander(mount.first, mount.second, lista_air, input);

                    if (min_check) {
                        auto fim = flights._11FilterMinimizer(res, num);

                        int i = 1;

                        for (auto apoio: fim) {
                            cout << i << "ª opção\n";
                            for (auto air: apoio) {
                                cout << "\033[1;32mFrom airport \033[0m" << air.src->getInfo().getName()
                                     << "\033[1;32m of code \033[0m" << air.src->getInfo().getCode()
                                     << "\033[1;32m in \033[0m" << air.src->getInfo().getCity() << "\033[1;32m, \033[0m"
                                     << air.src->getInfo().getCountry() << endl;
                                cout << "\033[1;32mTo airport \033[0m" << air.dest->getInfo().getName()
                                     << "\033[1;32m of code \033[0m" << air.dest->getInfo().getCode()
                                     << "\033[1;32m in \033[0m" << air.dest->getInfo().getCity()
                                     << "\033[1;32m, \033[0m" << air.dest->getInfo().getCountry() << endl;
                                cout << "\033[1;32mWith airline \033[0m" << air.airlines.getName()
                                     << "\033[1;32m of code \033[0m" << air.airlines.getCode()
                                     << "\033[1;32m with call sign \033[0m" << air.airlines.getCallSign()
                                     << "\033[1;32m and from \033[0m" << air.airlines.getCountry() << endl;
                                cout << endl;
                            }
                            i++;
                        }

                        if (fim.size() == 1) {
                            cout << "\033[1;32mThere is \033[0m" << fim.size() << "\033[1;32m option\033[0m\n";
                        } else {
                            cout << "\033[1;32mThere are \033[0m" << fim.size() << "\033[1;32m options\033[0m\n";
                        }

                        if (num == 1 && fim.size() == 1) {
                            cout << "\033[1;32mThe option shown uses \033[0m" << num << "\033[1;32m airline\033[0m\n" << endl;
                        } else if (num > 1 && fim.size() == 1) {
                            cout << "\033[1;32mThe option shown uses \033[0m" << num << "\033[1;32m different airlines\033[0m\n" << endl;
                        } else if (num == 1 && fim.size() > 1) {
                            cout << "\033[1;32mThe options shown use \033[0m" << num << "\033[1;32m airline\033[0m\n" << endl;
                        } else {
                            cout << "\033[1;32mThe options shown use \033[0m" << num << "\033[1;32m different airlines\033[0m\n" << endl;
                        }

                    } else {

                        int i = 1;

                        for (auto apoio: res) {
                            cout << i << "ª opção\n";
                            for (auto air: apoio) {
                                cout << "\033[1;32mFrom airport \033[0m" << air.src->getInfo().getName()
                                     << "\033[1;32m of code \033[0m" << air.src->getInfo().getCode()
                                     << "\033[1;32m in \033[0m" << air.src->getInfo().getCity() << "\033[1;32m, \033[0m"
                                     << air.src->getInfo().getCountry() << endl;
                                cout << "\033[1;32mTo airport \033[0m" << air.dest->getInfo().getName()
                                     << "\033[1;32m of code \033[0m" << air.dest->getInfo().getCode()
                                     << "\033[1;32m in \033[0m" << air.dest->getInfo().getCity()
                                     << "\033[1;32m, \033[0m" << air.dest->getInfo().getCountry() << endl;
                                cout << endl << "\033[1;33mAvailable airlines for this trip: \033[0m" << endl;
                                for (auto b : air.airlines) {
                                    cout << "\033[1;32mWith airline \033[0m" << b.getName()
                                         << "\033[1;32m of code \033[0m" << b.getCode()
                                         << "\033[1;32m with call sign \033[0m" << b.getCallSign()
                                         << "\033[1;32m and from \033[0m" << b.getCountry() << endl;
                                }
                                cout << endl;
                            }
                            i++;
                        }

                        if (res.size() == 1) {
                            cout << "\033[1;32mThere is \033[0m" << res.size() << "\033[1;32m option\033[0m\n";
                        } else {
                            cout << "\033[1;32mThere are \033[0m" << res.size() << "\033[1;32m options\033[0m\n";
                        }
                    }

                } else {
                    cout << "\033[0;31mUnrecognized option - Going back\033[0m" << endl;
                    cout <<endl;
                }

                break;

            case 0:

                cerr << "Program closed" << endl;
                return 0;

            default:

                cout << "\033[0;31mUnrecognized option\033[0m" << endl;
                cout <<endl;
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

// perguntar se quer todas as opções possiveis ou a melhor opção para cada pair de aeroportos  -  4  - fazer bool