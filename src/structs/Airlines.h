//
// Created by pchmelo on 25-12-2023.
//


#ifndef PROJECT_2_AIRLINES_H
#define PROJECT_2_AIRLINES_H

#include "string"
#include "set"
#include "unordered_set"

using namespace std;

class Airlines {
    private:
        string code;
        string name;
        string callSign;
        string country;

    public:
    /**
 * @brief Default constructor for the Airlines class.
 *
 * This constructor initializes the Airlines object with default values.
 * The default values for code, name, callSign, and country are all set to "0".
 */
        Airlines();

    /**
     * @brief Parameterized constructor for the Airlines class.
     *
     * This constructor initializes the Airlines object with the specified code,
     * and default values for name, callSign, and country.
     *
     * @param code The code of the airline.
     */
        Airlines(string code);

    /**
     * @brief Overloaded constructor for the Airlines class.
     *
     * This constructor initializes the Airlines object with the specified values.
     *
     * @param code The code of the airline.
     * @param name The name of the airline.
     * @param callSign The call sign of the airline.
     * @param country The country of the airline.
     */
        Airlines(string code, string name, string callSign, string country);


    /**
     * @brief Get the code of the airline.
     *
     * @return A string representing the code of the airline.
     */
        string getCode() const;

    /**
     * @brief Get the name of the airline.
     *
     * @return A string representing the name of the airline.
     */
        string getName() const;

    /**
     * @brief Get the call sign of the airline.
     *

     * @return A string representing the call sign of the airline.
     */
        string getCallSign() const;

    /**
    * @brief Get the country of the airline.
    *
    * @return A string representing the country of the airline.
    */
        string getCountry() const;



    /**
     * @brief Equality comparison operator for the Airlines class.
     *
     * This operator checks if the airline code of two Airlines objects is equal.
     *
     * @param airlines The Airlines object to compare.
     * @return True if the airline codes are equal; false otherwise.
     */
        bool operator==(const Airlines airlines) const{
            return this->code == airlines.code;
        }
    /**
     * @brief Equality comparison operator between Airlines and string.
     *
     * This operator checks if the airline code of the Airlines object is equal to a string.
     *
     * @param airlines The string representing the airline code.
     * @return True if the airline codes are equal; false otherwise.
     */
    bool operator==(const string airlines) const{
        return this->code == airlines;
    }
};





/**
 * @brief Hash function for the Airlines class.
 *
 * This structure provides a hash function for the Airlines class. It is used by the HashAirlines class
 * to calculate the hash value for an Airlines object when storing it in a hash table.
 */
struct airlinesHash{


    /**
 * @brief Calculate the hash value for an Airlines object.
 *
 * This function calculates the hash value for an Airlines object based on its airline code.
 *
 * @param b The Airlines object for which the hash value is calculated.
 * @return The calculated hash value.
 */
    int operator() (const Airlines& b) const {
        const string& code = b.getCode();
        unsigned  int hash = 5381;

        for(char c: b.getCode()){
            hash = 33*hash + static_cast<unsigned int>(c);
        }

        return hash % 449;
    }



    /**
     * @brief Compare two Airlines objects for equality.
     *
     * This function checks if two Airlines objects are equal based on their airline codes.
     *
     * @param b1 The first Airlines object.
     * @param b2 The second Airlines object.
     * @return True if the airline codes are equal; false otherwise.
     */
        bool operator()(const Airlines &b1, const Airlines &b2) const {
        return b1.getCode() == b2.getCode();
    }
};

typedef unordered_set<Airlines, airlinesHash, airlinesHash> AirlinesTable;

class HashAirlines{
    public:
        AirlinesTable airlinesTable;

    /**
    * @brief Read airline data from a CSV file and populate the hash table.
    *
    * This member function reads airline data from a CSV file located at "../src/structs/dataset/airlines.csv".
    * It parses each line of the file, extracts the necessary information (code, name, call sign, country),
    * and inserts the corresponding `Airlines` object into the hash table.
    *
    *Complexity = O(n * m) = O(n), where n is the number of lines in the file, and m is the maximum number of values in a line.
    * Note: m is insignificant compared to n.
    */
        void readLines();

};

#endif //PROJECT_2_AIRLINES_H
