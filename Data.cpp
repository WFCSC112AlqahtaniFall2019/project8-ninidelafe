//
// Created by Nini de la Fe on 11/18/19.
//

#include <string>
#include <iostream>
#include "Data.h"

using namespace std;

//creates a default constructor for the data
Data::Data() {
    country = "";
    happinessRank = 0.0;
    happinessScore = 0.0;
    GDPperCapita = 0.0;
    lifeExpectancy = 0.0;
}
//creates an alternate constructor for when the data is inputted through parameters
Data::Data(string c, double r, double s, double g, double l) {
    country = c;
    happinessRank = r;
    happinessScore = s;
    GDPperCapita = g;
    lifeExpectancy = l;

}

//overloads the outstream operator
ostream& operator<<(ostream& os, const Data& pr) {
    os << pr.country << ": " << pr.happinessRank<< ", " << pr.happinessScore<< "," << pr.GDPperCapita << ", "<< pr.lifeExpectancy;
    return os;
}

//overloads < operator for happiness rank? maybe GDPperCapita
bool operator < (const Data& hr, const Data &d){
    return hr.GDPperCapita <d.GDPperCapita;
    /*if (this->GDPperCapita > hr.GDPperCapita){
        return false;
    }
    else if (this->GDPperCapita < hr.GDPperCapita){
        return true;
    }
    else{
        return false;
    }*/
}


bool operator>=(const Data& hr, const Data &d) {
    return hr.GDPperCapita>d.GDPperCapita;
}

bool operator>(const Data& hr, const Data &d) {
    return hr.GDPperCapita>d.GDPperCapita;
}
