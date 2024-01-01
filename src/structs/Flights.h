//
// Created by pchmelo on 25-12-2023.
//

#ifndef PROJECT_2_FLIGHTS_H
#define PROJECT_2_FLIGHTS_H

#include "list"
#include "string"
#include "Graph.h"
#include "Airlines.h"
#include "Airports.h"

class Airports;
class HashAirports;
class HashAirlines;
struct AirportsGreatDistance;
struct AirportsTrafic;
struct AirportStop;
struct AirportStop2;

class Flights {
    public:
        Graph<Airports> flights;   //trocar string para airport


    /**
    * @brief Reads flight data from a CSV file and adds corresponding edges to the graph.
    *
    * This function reads flight data from a CSV file and populates the graph with edges
    * representing flights between airports. The CSV file is expected to have the following format:
    *   - Column 1: Source airport code
    *   - Column 2: Target airport code
    *   - Column 3: Airline code
    *
    * The function extracts relevant information from each line, looks up corresponding airport
    * and airline objects in the provided hash tables, and adds an edge to the graph.
    *
    * Complexity = O(n * m) = O(n), where n is the number of lines in the file, and m is the maximum number of values in a line.
    * Note: m is insignificant compared to n.
    *
    * @param hashAirlines A hash table containing airline information.
    * @param hashAirports A hash table containing airport information.
    *
    * @note The CSV file is expected to be located at "../src/structs/dataset/flights.csv".
    * @note The first line of the CSV file is assumed to contain column headers and is skipped.
    *
    * @param[in,out] hashAirlines The hash table with airline information.
    * @param[in,out] hashAirports The hash table with airport information.
    */
        void ReadLines(HashAirlines hashAirlines, HashAirports hashAirports);  //corrigir readlines



        //3.1
    /**
    * @brief Calculates the total number of flights in the graph.
    *
    * This function iterates through all vertices in the graph and counts the total number
    * of flights (edges) by summing the adjacency lists of each vertex.
    *
    * @return The total number of flights in the graph.
    */
        int _1numViajens();



        //3.2
    /**
    * @brief Calculates the number of outgoing flights from a specified airport.
    *
    * This function takes an airport code as input, finds the corresponding vertex
    * in the graph, and returns the number of outgoing flights from that airport.
    *
    * @param code The code of the airport for which the number of outgoing flights is calculated.
    * @return The number of outgoing flights from the specified airport.
    *         Returns 0 if the airport code is not found in the graph.
    */
        int _2numViajensDeAirport(string code);




    /**
    * @brief Calculates the number of unique airlines associated with flights departing from a specified airport.
    *
    * This function takes an airline code as input, finds the corresponding vertex
    * in the graph, and counts the number of unique airlines associated with flights
    * departing from that airport.
    *
    * @param code The code of the airport for which the number of unique airlines is calculated.
    * @return The number of unique airlines associated with flights departing from the specified airport.
    *         Returns 0 if the airport code is not found in the graph.
    */
        int _2numViajensDeAirlines(string code);




        //3.3
    /**
    * @brief Calculates the number of flights associated with airports from a specified country.
    *
    * This function takes a country name as input, iterates through all vertices in the graph,
    * and counts the number of flights associated with airports from the specified country.
    *
    * @param country The name of the country for which the number of flights is calculated.
    * @return The number of flights associated with airports from the specified country.
    */
        int _3getFlightsPerCountry(string country);




    /**
    * @brief Calculates the number of flights associated with airports from a specified city.
    *
    * This function takes a city and an optional country name as input, iterates through all vertices in the graph,
    * and counts the number of flights associated with airports from the specified city.
    *
    * @param city The name of the city for which the number of flights is calculated.
    * @param country The optional name of the country for additional filtering. Use "k" for no country filtering.
    * @return The number of flights associated with airports from the specified city or country.
    */
        int _3getFlightsPerCity(string city, string country);




    /**
    * @brief Calculates the number of flights associated with a specified airline company.
    *
    * This function takes an airline company code as input, iterates through all vertices in the graph,
    * and counts the number of flights associated with the specified airline company.
    *
    * @param airline The code of the airline company for which the number of flights is calculated.
    * @return The number of flights associated with the specified airline company.
    */
        int _3getFlightsPerCompany(string airline);



        //3.4
    /**
    * @brief Retrieves a set of unique airports representing countries connected to a specified airport.
    *
    * This function takes the code of a starting airport, finds the corresponding vertex in the graph,
    * and retrieves a set of unique airports representing countries connected to the specified airport.
    *
    * @param code The code of the starting airport.
    * @return A set containing unique airports representing countries connected to the specified starting airport.
    *         If the starting airport code is not found in the graph, an empty set is returned.
    */
        set<Airports> _4getVecCountriesAirport(string code );
        int _4getNumCountriesAirport(string code);


    /**
     * @brief Retrieves a set of unique airports representing countries connected to a specified city(and country).
     *
     * This function takes the name of a city and an optional country name as input, finds the corresponding vertices in the graph
     * representing airports in the specified city(and country), and retrieves a set of unique airports representing
     * countries connected to the specified city or city and country combination.
     *
     * @param city The name of the city for which the set of connected countries is retrieved.
     * @param country The optional name of the country for additional filtering. Use "k" for no country filtering.
     * @return A set containing unique airports representing countries connected to the specified city or city and country combination.
     *         If no airports are found for the specified city or city and country combination, an empty set is returned.
     */
        set<Airports> _4getVecCountriesCity(string city, string country);
        int _4getNumCountriesCity(string city, string country);



    /**
    * @brief Retrieves a set of unique airports representing countries connected to airports in a specified country.
    *
    * This function takes the name of a country as input, finds the corresponding vertices in the graph
    * representing airports in the specified country, and retrieves a set of unique airports representing
    * countries connected to airports in the specified country.
    *
    * @param country The name of the country for which the set of connected countries is retrieved.
    * @return A set containing unique airports representing countries connected to airports in the specified country.
    *         If no airports are found for the specified country, an empty set is returned.
    */
        set<Airports> _4getVecCountriesCountry(string country);
        int _4getNumCountriesCountry(string country);



        //3.5
    /**
    * @brief Retrieves a list of unique airports reachable from a specified starting airport.
    *
    * This function performs a breadth-first search starting from the specified airport code
    * and retrieves a list of unique airports that are reachable from the starting airport.
    *
    * @param code The code of the starting airport.
    * @return A vector containing unique airports reachable from the specified starting airport.
    *         If the starting airport code is not found in the graph, an empty vector is returned.
    */
        vector<Airports> _5Airports_per_airport(string code);
        int _5air_per_air_aux(string code);




    /**
    * @brief Retrieves a list of unique cities reachable from a specified starting airport.
    *
    * This function performs a breadth-first search starting from the specified airport code
    * and retrieves a list of unique cities that are reachable from the starting airport.
    *
    * @param code The code of the starting airport.
    * @param country The optional name of the country for additional filtering. Use an empty string for no country filtering.
    * @return A vector containing unique cities reachable from the specified starting airport.
    *         If the starting airport code is not found in the graph, an empty vector is returned.
    */
        vector<Airports> _5Cities_per_airport(string code, string country);
        int _5cit_per_air_aux(string code, string country);



    /**
    * @brief Retrieves a list of unique countries reachable from a specified starting airport.
    *
    * This function performs a breadth-first search starting from the specified airport code
    * and retrieves a list of unique countries that are reachable from the starting airport.
    *
    * @param code The code of the starting airport.
    * @return A vector containing unique countries reachable from the specified starting airport.
     *         If the starting airport code is not found in the graph, an empty vector is returned.
    */
        vector<Airports> _5Countries_per_airport(string code);
        int _5count_per_air_aux(string code);




        //3.6
    /**
    * @brief Retrieves a vector of unique airports reachable within a specified number of stops from a starting airport.
    *
    * This function performs a breadth-first search starting from the specified airport code and retrieves a vector
    * of unique airports that are reachable within the specified number of stops from the starting airport.
    *
    * @param code The code of the starting airport.
    * @param x The maximum number of stops allowed to reach airports from the starting airport.
    * @return A vector containing unique airports reachable within the specified number of stops from the starting airport.
    *         If the starting airport code is not found in the graph, an empty vector is returned.
    */
        vector<Airports> _6getVecStopsAirports(string code, int x );




    /**
    * @brief Retrieves a vector of unique airports representing cities reachable within a specified number of stops from a starting airport.
    *
    * This function performs a breadth-first search starting from the specified airport code and retrieves a vector
    * of unique airports that are reachable within the specified number of stops from the starting airport.
    *
    * @param code The code of the starting airport.
    * @param x The maximum number of stops allowed to reach airports from the starting airport.
    * @param country The optional name of the country for additional filtering. Use an empty string for no country filtering.
    * @return A vector containing unique airports representing cities or countries reachable within the specified number of stops from the starting airport.
    *         If the starting airport code is not found in the graph, an empty vector is returned.
    */
        vector<Airports> _6getVecStopsCities(string code, int x, string country);


    /**
    * @brief Retrieves a vector of unique airports representing countries reachable within a specified number of stops from a starting airport.
    *
    * This function performs a breadth-first search starting from the specified airport code and retrieves a vector
    * of unique airports that represent countries reachable within the specified number of stops from the starting airport.
    *
    * @param code The code of the starting airport.
    * @param x The maximum number of stops allowed to reach airports from the starting airport.
    * @return A vector containing unique airports representing countries reachable within the specified number of stops from the starting airport.
    *         If the starting airport code is not found in the graph, an empty vector is returned.
    */
        vector<Airports> _6getVecStopsCountries(string code, int x );

        int _6getIntStopsAirports(string code, int x );
        int _6getIntStopsCities(string code, int x, string country);
        int _6getIntStopsCountries(string code, int x);


        //3.7
    /**
    * @brief Retrieves a list of airports with the greatest distance between them in the graph.
    *
    * This function calculates the diameter of the graph, which represents the greatest distance between two airports,
    * and retrieves a list of airports with the greatest distance between them along with the calculated diameter.
    *
    * @return A list of `AirportsGreatDistance` objects representing pairs of airports with the greatest distance between them.
    *         If the graph is empty or contains a single airport, an empty list is returned.
    */
        list<AirportsGreatDistance> _7getAirportsGreat();



        //3.8
    /**
    * @brief Retrieves a vector of airports ranked by traffic (number of connections) in the graph.
    *
    * This function calculates the traffic for each airport in the graph, considering the number of connections
    * (edges) associated with each airport. It then retrieves a vector of airports ranked by traffic along with
    * the corresponding traffic values.
    *
    * @return A vector of `AirportsTrafic` objects representing airports ranked by traffic (number of connections).
    *         If the graph is empty or contains a single airport, an empty vector is returned.
    */
        vector<AirportsTrafic> _8getTopVecAirports();


        vector<AirportsTrafic> _8getTopVecDescAirports();
        vector<AirportsTrafic> _8getTopVecAscAirports();



        //3.9
    /**
    * @brief Retrieves a set of airports that are articulation points in the graph.
    *
    * This function identifies articulation points in the graph using a modified depth-first search (DFS) algorithm.
    * It then retrieves a set of airports that are identified as articulation points.
    *
    * @return A set of `Airports` objects representing articulation points in the graph.
    *         If the graph is empty or contains a single airport, an empty set is returned.
    */
        set<Airports> _9Articulations();


    /**
    * @brief Performs a modified depth-first search (DFS) to identify articulation points in the graph.
    *
    * This function is a helper function used in identifying articulation points in the graph. It performs a modified
    * depth-first search (DFS) algorithm, updating information about the vertices and edges. The articulation points
    * are identified based on the low and num values of the vertices.
    *
    * @param vertex The current vertex being processed during the DFS.
    * @param res A set to store identified articulation points.
    * @param i An integer reference representing the order in which vertices are visited.
    */
        void _9Auxiliar(Vertex<Airports>* vertex, set<Airports> &res, int &i);
        int _9numArticulations( );




        //4.all
    /**
    * @brief Retrieves the best path between two airports using the fewest stops (edges) in the graph.
    *
    * This function performs a breadth-first search (BFS) algorithm to find the best path between two airports,
    * considering the fewest stops (edges) required to reach the destination airport from the source airport.
    *
    * @param src The source airport vertex.
    * @param dest The destination airport vertex.
    * @return A list of `AirportStop2` objects representing the best path between the source and destination airports.
    *         Each object includes information about the source and destination airports and the airlines on the path.
    *         If no path is found or the source/destination airports are not present in the graph, an empty list is returned.
    */
        list<AirportStop2> _10BestPathEntreDoisAeroportos(Vertex<Airports>* src, Vertex<Airports>* dest);





    /**
     * @brief Finds the best paths between multiple pairs of source and destination airports in the graph.
     *
     * This function iterates through multiple pairs of source and destination airports and finds the best paths
     * between them using the fewest stops (edges) based on the `_10BestPathEntreDoisAeroportos` function.
     *
     * @param src A vector of source airport vertices.
     * @param dest A vector of destination airport vertices. The size of this vector should match the size of the 'src' vector.
     * @return A vector of lists of `AirportStop2` objects representing the best paths between the corresponding pairs of source and destination airports.
     *         Each list includes information about the source and destination airports and the airlines on the path.
     *         If no path is found for a pair or the source/destination airports are not present in the graph, an empty list is included in the result vector.
     */
        vector<list<AirportStop2>> _10Commander(vector<Vertex<Airports>*> src, vector<Vertex<Airports>*> dest);




    /**
     * @brief Retrieves airport vertices based on a specified airport code in the graph.
     *
     * This function searches for airport vertices in the graph based on a specified airport code or name.
     *
     * @param code The airport code to search for in the graph.
     * @param flag A boolean flag indicating whether the provided 'code' parameter represents an airport code (true) or name (false).
     * @return A vector of airport vertices matching the specified code or name. If no vertices are found, an empty vector is returned.
     */
        vector<Vertex<Airports>*> _10AirportsAirport(string code, bool flag);





    /**
     * @brief Retrieves airport vertices based on a specified city in the graph.
     *
     * This function searches for airport vertices in the graph based on a specified city.
     *
     * @param city The city name to search for in the graph.
     * @param pais The country name to search for in the graph. If set to "k," the search will only consider the city.
     * @return A vector of airport vertices matching the specified city and country. If no vertices are found, an empty vector is returned.
     */
        vector<Vertex<Airports>*> _10AirportsCity(string city, string pais);




    /**
     * @brief Retrieves airport vertices based on a specified country in the graph.
     *
     * This function searches for airport vertices in the graph based on a specified country.
     *
     * @param country The country name to search for in the graph.
     * @return A vector of airport vertices matching the specified country. If no vertices are found, an empty vector is returned.
     */
        vector<Vertex<Airports>*> _10AirportsPais(string pais);





    /**
     * @brief Retrieves airport vertices based on geographical coordinates in the graph.
     *
     * This function searches for airport vertices in the graph based on geographical coordinates.
     *
     * @param lat The latitude of the target location.
     * @param log The longitude of the target location.
     * @return A vector of airport vertices located closest to the specified geographical coordinates. If multiple vertices have the same minimum distance, all of them are included in the vector. If no vertices are found, an empty vector is returned.
     */
        vector<Vertex<Airports>*> _10AirportsCoord(string lat, string log);





    /**
    * @brief Retrieves airport vertices within a specified radius of geographical coordinates in the graph.
    *
    * This function searches for airport vertices in the graph that are within a specified radius of geographical coordinates.
    *
    * @param lat The latitude of the center location.
    * @param log The longitude of the center location.
    * @param raio The radius within which to search for airport vertices (in the same unit as the Haversine distance).
    * @return A vector of airport vertices located within the specified radius of the center geographical coordinates. If no vertices are found, an empty vector is returned.
    */
        vector<Vertex<Airports>*> _10AirportsCoordRaio(string lat, string log,int raio);




    /**
     * @brief Calculates the Haversine distance between two geographical coordinates.
     *
     * The Haversine formula is used to calculate the great-circle distance between two points on the surface of a sphere (e.g., Earth) given their latitude and longitude.
     *
     * @param lat_1 The latitude of the first point (in radians).
     * @param log_1 The longitude of the first point (in radians).
     * @param lat_2 The latitude of the second point (in radians).
     * @param log_2 The longitude of the second point (in radians).
     * @return The Haversine distance between the two geographical coordinates.
     */
        double _10Haversine(double lat_1, double log_1, double lat_2, double log_2);





    /**
    * @brief Constructs pairs of source and destination vectors for airport vertices.
    *
    * This function constructs pairs of source and destination vectors for airport vertices. Each pair consists of a source vertex from the 'src' vector and a destination vertex from the 'dest' vector.
    *
    * @param src A vector of source airport vertices.
    * @param dest A vector of destination airport vertices.
    * @return A pair of vectors, where the first vector contains source airport vertices and the second vector contains corresponding destination airport vertices.
    */
        pair<vector<Vertex<Airports> *>, vector<Vertex<Airports> *>> _10Montador(vector<Vertex<Airports>*> src, vector<Vertex<Airports>*> dest);




        //5.all
    /**
    * @brief Finds all best paths between two airports considering a set of restrictions.
    *
    * The function uses a modified BFS algorithm to find the best paths between two airports, considering the given set of restrictions.
    *
    * @param src The source airport vertex.
    * @param dest The destination airport vertex.
    * @param lista A set of airport codes representing restrictions.
    * @param set_up The type of restriction setup: 0 for exclusion, 1 for inclusion.
    * @return A vector of vectors of AirportStop2 representing all best paths between the source and destination airports.
    */
        vector<vector<AirportStop2>> _11AllBestPathEntreDoisAeroportos(Vertex<Airports>* src, Vertex<Airports>* dest, set<string> list, int set);




    /**
    * @brief Auxiliary function to reconstruct all best paths between two airports considering a set of restrictions.
    *
    * The function is used as an auxiliary helper to reconstruct all best paths between two airports based on the given set of restrictions.
    *
    * @param src The source airport vertex.
    * @param dest The destination airport vertex.
    * @param previo The map storing previous vertices in the best paths.
    * @param caminhoAtual The current path being reconstructed.
    * @param res The vector of vectors of AirportStop2 representing all best paths.
    * @param t The AirportStop2 object used for storing information about the path.
    * @param flag A boolean flag indicating the first iteration in the reconstruction process.
    */
        void _11AuxReconstructor(Vertex <Airports>* src, Vertex <Airports>* dest, unordered_map<Vertex<Airports>*, set<Vertex<Airports>*>> &previo, vector<AirportStop2> &caminhoAtual, vector<vector<AirportStop2>> &res, AirportStop2 &t, bool &flag);





    /**
    * @brief Commander function to find all best paths between sets of source and destination airports.
    *
    * The function serves as a commander for finding all best paths between sets of source and destination airports based on a set of restrictions.
    *
    * @param src Vector containing pointers to source airport vertices.
    * @param dest Vector containing pointers to destination airport vertices.
    * @param lista Set of airport codes representing restrictions on airline availability.
    * @param set An integer representing the type of restriction: 0 for inclusion, 1 for exclusion.
    * @return Vector of vectors of AirportStop2 representing all best paths between the sets of source and destination airports.
    */
        vector<vector<AirportStop2>> _11AllCommander(vector<Vertex<Airports>*> src, vector<Vertex<Airports>*> dest, set<string> list, int set);





    /**
     * @brief Separator function to generate combinations of airlines for each segment in a vector of AirportStop2.
     *
     * The function separates the input vector of AirportStop2 into combinations of airlines for each segment and generates all possible combinations.
     *
     * @param input Vector of vectors of AirportStop2 representing the input data.
     * @return Vector of vectors of AirportStop representing all combinations of airlines for each segment.
     */
        vector<vector<AirportStop>> _11Separator(vector<vector<AirportStop2>> input);




     /**
     * @brief Filter and minimize combinations of airlines for each segment in a vector of AirportStop2.
     *
     * The function separates the input vector of AirportStop2 into combinations of airlines for each segment and filters out the combinations based on the minimum number of different airlines.
     *
     * @param input Vector of vectors of AirportStop2 representing the input data.
     * @param num Reference to an integer variable to store the minimum number of different airlines.
     * @return Vector of vectors of AirportStop representing filtered and minimized combinations of airlines for each segment.
     */
        vector<vector<AirportStop>> _11FilterMinimizer(vector<vector<AirportStop2>> input, int &num);

};

#endif //PROJECT_2_FLIGHTS_H
