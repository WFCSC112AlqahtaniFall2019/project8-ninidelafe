//
// Created by Nini de la Fe on 11/7/19.
//

#ifndef PROJECT7_DATA_H
#define PROJECT7_DATA_H

#include <string>
#include <iostream>

using namespace std;

class Data {
public:
    Data ();
    Data(string c, double r, double s, double g, double l);
    friend ostream& operator<<(ostream& os, const Data& pr);
    friend bool operator >= (const Data& hr, const Data &d);
    friend bool operator < (const Data& hr, const Data &d);
    friend bool operator > (const Data& hr, const Data &d);

    string country;
    double happinessRank;
    double happinessScore;
    double GDPperCapita;
    double lifeExpectancy;

};


#endif //PROJECT7_DATA_H
