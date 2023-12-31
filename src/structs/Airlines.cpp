//
// Created by pchmelo on 25-12-2023.
//

#include "Airlines.h"
#include "fstream"
#include "sstream"
#include "vector"



    Airlines::Airlines() {
        this->code = "0";
        this->name = "0";
        this->callSign = "0";
        this->country = "0";
    }



    Airlines::Airlines(string code) {
        this->code = code;
        this->name = "0";
        this->callSign = "0";
        this->country = "0";
    }



    Airlines::Airlines(string code, string name, string callSign, string country){
        this->code = code;
        this->name = name;
        this->callSign = callSign;
        this->country = country;
    }




    string Airlines::getCode() const{
        return this->code;
    }





    string Airlines::getName() const{
        return this->name;
    }




    string Airlines::getCallSign() const{
        return this->callSign;
    }






    string Airlines::getCountry() const{
        return this->country;
    }





    void HashAirlines::readLines() {
        string input = "../src/structs/dataset/airlines.csv";
        ifstream MyReadFile(input);

        string line;
        Airlines airlines;

        getline(MyReadFile, line);

        while (std::getline(MyReadFile, line)) {
            vector<std::string> values;
            stringstream ss(line);

            while (ss.good()) {
                std::string subtr;
                getline(ss, subtr, ',');
                values.push_back(subtr);
            }

            airlines = Airlines(values[0], values[1], values[2], values[3]);
            this->airlinesTable.insert(airlines);
        }
    }