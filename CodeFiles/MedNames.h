//
//  MedNames.h
//  MedCheck1.3
//
//  Created by Heath Banak on 7/12/22.
//

#include <string>

using namespace std;

#include "Date.h"
#include "Med.h"

#ifndef MedNames_h
#define MedNames_h

// DEFINE SERTRALINE
#ifndef Sertraline_h
#define Sertraline_h

class Sertraline: public Med {
public:
    Sertraline();
};

#endif /* Sertraline_h */

Sertraline::Sertraline() {
    name_ = "sertraline";
    dose_ = "2 100mg pills, once a day";
    file_ = "/Users/heathheath/Desktop/MedCheck1.3/serData.txt";
    Med(name_, dose_, file_);
}

// DEFINE BUPROPRION
#ifndef Buproprion_h
#define Buproprion_h

class Buproprion: public Med {
public:
    Buproprion();
};

#endif /* Buproprion_h */

Buproprion::Buproprion() {
    name_ = "buproprion";
    dose_ = "1 200mg pill, once a day";
    file_ = "/Users/heathheath/Desktop/MedCheck1.3/bupData.txt";
    Med(name_, dose_, file_);
}

// DEFINE VITAMINS
#ifndef Vitamins_h
#define Vitamins_h

class Vitamins: public Med {
public:
    Vitamins();
};

#endif /* Vitamins_h */

Vitamins::Vitamins() {
    name_ = "vitamin D";
    dose_ = "2 vitamin D gummies, once a day";
    file_ = "/Users/heathheath/Desktop/MedCheck1.3/vitData.txt";
    Med(name_, dose_, file_);
}

// DEFINE TESTOSTERONE
#ifndef Testosterone_h
#define Testosterone_h

class Testosterone: public Med {
public:
    Testosterone();
    void showPercentages(Date* today);
};

#endif /* Testosterone_h */
Testosterone::Testosterone() {
    name_ = "testosterone";
    dose_ = "1 0.2mL injection, every Monday";
    file_ = "/Users/heathheath/Desktop/MedCheck1.3/tesData.txt";
    Med(name_, dose_, file_);
}

void Testosterone::showPercentages(Date* today) {
    string errOut = "";
    string text = "";
    
    if (today->getWeekday() != "MONDAY") {
        try {
            inFS_.open(file_);
            if (!inFS_.is_open()) {
                errOut = "Could not open " + getName() + " data file.";
                throw errOut;
            }
            
            // read in all lines of file to vector
            while (getline(inFS_, text)) {
                lines_.push_back(text);
            }
            
            inFS_.close();
            if (inFS_.is_open()) {
                errOut = "Could not close " + getName() + " data file.";
                throw errOut;
            }
        }
        catch (string err) {
            cout << "ERROR: " << err << endl;
        }
    }
    Med::showPercentages();
}

#endif /* MedNames_h */
