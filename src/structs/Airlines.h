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
        Airlines();
        Airlines(string code);
        Airlines(string code, string name, string callSign, string country);

        string getCode() const;
        string getName() const;
        string getCallSign() const;
        string getCountry() const;

        bool operator==(const Airlines airlines) const{
            return this->code == airlines.code;
        }

    bool operator==(const string airlines) const{
        return this->code == airlines;
    }
};

struct airlinesHash{
    int operator() (const Airlines& b) const {
        const string& code = b.getCode();
        unsigned  int hash = 5381;

        for(char c: b.getCode()){
            hash = 33*hash + static_cast<unsigned int>(c);
        }

        return hash % 449;
    }
        bool operator()(const Airlines &b1, const Airlines &b2) const {
        return b1.getCode() == b2.getCode();
    }
};

typedef unordered_set<Airlines, airlinesHash, airlinesHash> AirlinesTable;

class HashAirlines{
    public:
        AirlinesTable airlinesTable;
        void readLines();

};

#endif //PROJECT_2_AIRLINES_H
