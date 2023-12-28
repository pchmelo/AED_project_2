#include <iostream>
#include <list>
#include "Menu.h"
/*#include "Flights.h"
#include "Airports.h"*/


using namespace std;

int Menu::Terminal() {

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

                        /*cout << endl << "\033[1;32mNumber of airports is \033[0m" << HashAirports::_1numAirports() << endl;
                        cout << endl << "\033[1;32mNumber of available flights is \033[0m" << Flights::_1numviajens() << endl;*/

                        break;

                    case 2:

                        cout << "\033[1;34mWhich airport? \033[0m";
                        cin >> code;
                        cout << endl;
                        /*cout << "\033[1;32mThere are a total of \033[0m" << Flights::_2numViajensDeAirport(code) << "\033[1;32m flights from \033[0m" << Flights::_2numViajensDeAirlines(code) << "\033[1;32m different airlines in \033[0m" << code << endl;*/

                        break;

                    case 3:

                        cout << "\033[1;33m[ 1 ]\033[0m" << " City" << endl;
                        cout << "\033[1;33m[ 2 ]\033[0m" << " Airline" << endl;
                        cout << "\033[1;33m[ 3 ]\033[0m" << " Country" << endl;
                        cout << "\033[1;31m[ 0 ]\033[0m" << " Go back" << endl;

                        cout << "\033[1;34mDecision: \033[0m";
                        cin >> decision;
                        cout << endl;

                        switch (decision) {
                            case 1:

                                cout << "\033[1;34mWhich city? \033[0m";
                                cin >> code;
                                cout << endl;
                                /*cout << "\033[1;32mThere are a total of \033[0m" << Flights::_3getFlightsPerCity(code) << "\033[1;32m flights in \033[0m" << code << endl;*/

                                break;

                            case 2:

                                cout << "\033[1;34mWhich airline? \033[0m";
                                cin >> code;
                                cout << endl;
                                /*cout << "\033[1;32mThere are a total of \033[0m" << Flights::_3getFlightsPerCompany(code) << "\033[1;32m flights from the airline \033[0m" << code << endl;*/

                                break;

                            case 3:

                                cout << "\033[1;34mWhich country? \033[0m";
                                cin >> code;
                                cout << endl;
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

                        cout << "\033[1;34mDecision: \033[0m";
                        cin >> decision;
                        cout << endl;

                        switch (decision) {
                            case 1:

                                cout << "\033[1;34mWhich city? \033[0m";
                                cin >> code;
                                cout << endl;
                                /*cout << Flights::_4getNumCountriesCity(code) << "\033[1;32m different countries flown to from city \033[0m" << code << endl;*/

                                break;

                            case 2:

                                cout << "\033[1;34mWhich airport? \033[0m";
                                cin >> code;
                                cout << endl;
                                /*cout << Flights::_4getNumCountriesAirport(code) << "\033[1;32m different countries flown to from airport \033[0m" << code << endl;*/

                                break;

                            case 3:

                                cout << "\033[1;34mWhich country? \033[0m";
                                cin >> code;
                                cout << endl;
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

                        cout << "\033[1;34mWhich airport? \033[0m";
                        cin >> code;
                        cout << endl;
                        /*cout << "\033[1;32mThere are \033[0m" << Flights::Airports_per_airport(code) << "\033[1;32m airports, \033[0m" << Flights::Cities_per_airport(code) << "\033[1;32m cities and \033[0m" << Flights::Countries_per_airport(code) << "\033[1;32m countries available as destinations from airport \033[0m" << code << endl;*/

                        break;

                    case 6:

                        cout << "\033[1;34mWhich airport? \033[0m";
                        cin >> code;
                        cout << endl;
                        cout << "\033[1;34mHow many lay-overs? \033[0m";
                        cin >> code_aux;
                        cout << endl;
                        /*cout << "\033[1;32mThere are \033[0m" << Flights::_6getIntStopsAirports(code, code_aux    ) << "\033[1;32m airports, \033[0m" << Flights::_6getIntStopsCities(code, code_aux) << "\033[1;32m cities and \033[0m" << Flights::_6getIntStopsCountries(code, code_aux) << "\033[1;32m countries available as destinations from airport \033[0m" << code << "\033[1;32m in \033[0m" << code_aux << "\033[1;32m lay-overs\033[0m" << endl;*/

                        break;

                    case 7:

                        /*aux = _7getAirportsGreat();
                        while (!aux.empty()) {
                            cout << "\033[1;32mTrip from \033[0m" << aux[0].first << "\033[1;32m to \033[0m" << aux[0].second << endl;
                            aux.remove(aux[0]);
                        }*/

                        break;

                    case 8:

                        cout << "\033[1;34mHow many airports do you wish to be presented with? \033[0m";
                        cin >> code_aux;
                        cout << endl;

                        /*frango = _8getTopVecAirports();

                        for (int i = 0; i < code_aux; i++) {
                            cout << frango[i] << endl;
                        }*/

                        break;

                    case 9:



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