//
// Created by pchmelo on 25-12-2023.
//
#include "string"
#include "set"

#ifndef PROJECT_2_AIRLINES_H
#define PROJECT_2_AIRLINES_H

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
        string  getCountry() const;

        bool operator<(const Airlines airlines) const{
            return this->code < airlines.code;
        }
};

class setAirlines{
    public:
        set<Airlines> setAirlines;
        void readLines();

};


#endif //PROJECT_2_AIRLINES_H
