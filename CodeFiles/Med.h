//
//  Med.h
//  MedCheck1.3
//
//  Created by Heath Banak on 7/5/22.
//

#ifndef Med_h
#define Med_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "Date.h"

class Med {
public:
    Med();
    Med(string name, string dose, string const FILE);
    string getName();
    bool hasBeenTaken();
    void logMed();
    void showPercentages();
protected:
    string file_;
    int i_;
    ifstream inFS_;
    ofstream outFS_;
    string name_;
    string dose_;
    vector<string> lines_;
    vector<string> yesses_;
    vector<string> nos_;
    double noYes_;
    double noNo_;
};


#endif /* Med_h */
