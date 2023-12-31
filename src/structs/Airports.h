//
// Created by pchmelo on 25-12-2023.
//


#ifndef PROJECT_2_AIRPORTS_H
#define PROJECT_2_AIRPORTS_H

#include "string"
#include "set"
#include "unordered_set"
#include "Flights.h"

using namespace std;

class Flights;

class Airports {
    private:
        string code;
        string name;
        string city;
        string country;
        string lat;
        string lon;
    public:

    /**
     * @brief Default constructor for the Airports class.
     *
     * This constructor initializes an Airports object with default values.
     * - Airport code is set to "0".
     * - Airport name is set to "0".
     * - City is set to "0".
     * - Country is set to "0".
     * - Latitude is set to "0".
     * - Longitude is set to "0".
     */
        Airports();




    /**
    * @brief Constructor for the Airports class with a specified airport code.
    *
    * This constructor initializes an Airports object with the given airport code.
    * The other attributes (name, city, country, latitude, longitude) are set to default values.
    *
    * @param code The airport code to set for the Airports object.
    */
        Airports(string code);




    /**
    * @brief Constructor for the Airports class with specified attributes.
    *
    * This constructor initializes an Airports object with the given values for its attributes:
    * airport code, name, city, country, latitude, and longitude.
    *
    * @param code    The airport code to set for the Airports object.
    * @param name    The name of the airport.
    * @param city    The city where the airport is located.
    * @param country The country where the airport is located.
    * @param lat     The latitude of the airport's location.
    * @param lon     The longitude of the airport's location.
    */
        Airports(string code, string name, string city, string country, string lat,string lon);



    /**
     * @brief Get the airport code.
     *
     * @return The airport code.
     */
        string getCode() const;



    /**
    * @brief Get the name of the airport.
    *
    * @return The name of the airport.
    */
        string getName() const;




    /**
    * @brief Get the city where the airport is located.
    *
    * @return The city of the airport.
    */
        string getCity() const;




    /**
    * @brief Get the country where the airport is located.
    *
    * @return The country of the airport.
    */
        string getCountry() const;




    /**
    * @brief Get the latitude of the airport's location.
    *
    * @return The latitude of the airport.
    */
        string getLat() const;




    /**
    * @brief Get the longitude of the airport's location.
    *
    * @return The longitude of the airport.
    */
        string getLon() const;



    /**
     * @brief Equality operator for comparing two airports.
     *
     * @param airports The airport to compare.
     * @return True if the airports have the same code, false otherwise.
     */
    bool operator==(Airports airports) const{
        return this->code == airports.code;
    }


    /**
     * @brief Less-than operator for comparing two airports.
     *
     * @param airports The airport to compare.
     * @return True if the code of the current airport is less than the code of the other airport, false otherwise.
     */
        bool operator<(Airports airports) const{
        return this->code < airports.code;
    }

};


/**
 * @brief Hash function for the Airports class.
 *
 * This struct provides a hash function that can be used for hashing Airports objects.
 */
struct airportHash{



    /**
     * @brief Operator overload for calculating the hash of an Airports object.
     *
     * @param b The Airports object for which the hash is calculated.
     * @return The hash value for the provided Airports object.
     */
    int operator() (const Airports& b) const {
            const string& code = b.getCode();
            unsigned  int hash = 5381;

            for(char c: b.getCode()){
                hash = 33*hash + static_cast<unsigned int>(c);
            }

            return hash % 3019;
        }



    /**
     * @brief Operator overload for comparing two Airports objects for equality.
     *
     * @param b1 The first Airports object for comparison.
     * @param b2 The second Airports object for comparison.
     * @return True if the two Airports objects have the same code, false otherwise.
     */
    bool operator() (const Airports& b1, const Airports& b2) const {
        return b1.getCode() == b2.getCode();
    }
};

typedef unordered_set<Airports, airportHash, airportHash> AirportTable;

class HashAirports{
    public:
        AirportTable airportTable;




    /**
    * @brief Reads airport data from a CSV file and populates the flights graph and airport hash table.
    *
    * This function reads airport information from a CSV file, creates Airports objects, adds them to the
    * flights graph, and inserts them into the airport hash table.
    *
    * Complexity = O(n * m) = O(n), where n is the number of lines in the file, and m is the maximum number of values in a line.
    * Note: m is insignificant compared to n.
    *
    * @param flights The Flights object representing the flights graph to which the airports will be added.
    */
        void  readLines(Flights &flights);

        //1


    /**
    * @brief Returns the number of airports in the hash table.
    *
    * This function retrieves the size of the airport hash table, indicating the total number of airports stored.
    *
    * @return An integer representing the number of airports in the hash table.
    */
        int _1numAirports();
};




/**
 * @brief Represents a pair of airports and the great circle distance between them.
 *
 * The `AirportsGreatDistance` struct stores information about two airports and the distance between them.
 */
struct AirportsGreatDistance{
    Airports airport_source;
    Airports airport_dest;
    int distance;



    /**
       * @brief Default constructor for AirportsGreatDistance.
       *
       * Initializes the distance to 0.
       */
    AirportsGreatDistance(){
        this->distance = 0;
    }




    /**
      * @brief Parameterized constructor for AirportsGreatDistance.
      *
      * Initializes the struct with the specified source airport, destination airport, and distance.
      *
      * @param a The source airport.
      * @param b The destination airport.
      * @param distance The great circle distance between the source and destination airports.
      */
    AirportsGreatDistance(Airports a, Airports b, int distance){
        this->airport_source = a;
        this->airport_dest = b;
        this->distance = distance;
    }

};


    /**
     * @brief Represents the traffic information for an airport.
     *
     * The `AirportsTrafic` struct stores information about the traffic at an airport, including the airport itself
     * and the corresponding traffic count.
     */
struct AirportsTrafic{

    pair<Airports, int> trafic;
    /**
  * @brief Constructor for AirportsTrafic.
  *
  * Initializes the struct with the specified airport and traffic count.
  *
  * @param airports The airport for which traffic information is stored.
  * @param n The traffic count for the airport.
  */
    AirportsTrafic(Airports airports, int n){
        pair<Airports, int> res = pair(airports, n);
        this->trafic = res;
    }
    /**
      * @brief Equality comparison operator.
      *
      * Checks if the airport code in the stored traffic information is equal to the provided airport code.
      *
      * @param airports The airport to compare.
      * @return True if the airport codes are equal, false otherwise.
      */
    bool operator==(Airports airports) const{
        return this->trafic.first.getCode() == airports.getCode();
    }
    /**
      * @brief Less-than comparison operator.
      *
      * Compares the traffic count of two `AirportsTrafic` objects.
      *
      * @param a The `AirportsTrafic` object to compare.
      * @return True if the traffic count of the current object is less than that of `a`, false otherwise.
      */
    bool operator<(AirportsTrafic a) const{
        return this->trafic.second < a.trafic.second;
    }
};
    /**
     * @brief Represents a stop at an airport during a flight.
     *
     * The `AirportStop` struct stores information about a stop at an airport during a flight, including the source and
     * destination airports, as well as the associated airline.
     */
struct AirportStop{
    Vertex<Airports>* src;
    Vertex<Airports>* dest;
    Airlines airlines;

    /**
     * @brief Default constructor for AirportStop.
     *
     * Initializes the `AirportStop` struct with default values.
     */
    AirportStop(){}
    /**
      * @brief Constructor for AirportStop.
      *
      * Initializes the `AirportStop` struct with the specified source airport, destination airport, and airline.
      *
      * @param scr The source airport.
      * @param dest The destination airport.
      * @param airlines The associated airline for the flight.
      */
    AirportStop(Vertex<Airports>* scr, Vertex<Airports>* dest, Airlines airlines){
        this->src = scr;
        this->dest = dest;
        this->airlines = airlines;
    }
    /**
     * @brief Sets the source airport for the flight.
     *
     * @param a The source airport to set.
     */
    void setA(Vertex<Airports>* a){
        this->src = a;
    }

    /**
     * @brief Sets the destination airport for the flight.
     *
     * @param b The destination airport to set.
     */
    void setB(Vertex<Airports>* b){
        this->dest = b;
    }
    /**
      * @brief Sets the airline for the flight.
      *
      * @param airlines1 The airline to set.
      */
    void Airline(Airlines airlines1){
        this->airlines = airlines1;
    }

};
    /**
     * @brief Represents a stop at an airport during a flight with multiple airlines.
     *
     * The `AirportStop2` struct stores information about a stop at an airport during a flight, including the source and
     * destination airports, as well as a vector of associated airlines.
     */
struct AirportStop2{
    Vertex<Airports>* src;
    Vertex<Airports>* dest;
    vector<Airlines> airlines;

    /**
     * @brief Default constructor for AirportStop2.
     *
     * Initializes the `AirportStop2` struct with default values.
     */
    AirportStop2(){}
    /**
     * @brief Constructor for AirportStop2.
     *
     * Initializes the `AirportStop2` struct with the specified source airport, destination airport, and vector of airlines.
     *
     * @param scr The source airport.
     * @param dest The destination airport.
     * @param airlines The vector of associated airlines for the flight.
     */
    AirportStop2(Vertex<Airports>* scr, Vertex<Airports>* dest, vector<Airlines> airlines){
        this->src = scr;
        this->dest = dest;
        this->airlines = airlines;
    }
    /**
      * @brief Sets the source airport for the flight.
      *
      * @param a The source airport to set.
      */
    void setA(Vertex<Airports>* a){
        this->src = a;
    }
    /**
       * @brief Sets the destination airport for the flight.
       *
       * @param b The destination airport to set.
       */
    void setB(Vertex<Airports>* b){
        this->dest = b;
    }
    /**
     * @brief Sets the vector of airlines for the flight.
     *
     * @param airlines1 The vector of airlines to set.
     */
    void Airline(vector<Airlines> airlines1){
        this->airlines = airlines1;
    }

};


#endif
