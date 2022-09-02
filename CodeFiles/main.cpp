/*
 * main.cpp
 * MedCheck 1.3
 * Heath Banak
 * 07-03-22
 *
 * Last update: 07-03-22
 *
 *
 *  KEY-
 *      Med has been taken:
 *          Med is recorded as yes for today in its file; the hasBeenTaken function returns true
 *      Med has not been taken:
 *          Med is either not recorded today or it is recorded as no for today; the hasBeenTaken function returns false
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "Date.h"
#include "Scene.h"
#include "MedNames.h"

void getMedsTaken(vector<string> &medsTaken, Sertraline* ser, Buproprion* bup, Vitamins* vit);
void populateMeds(vector<string> &meds, Sertraline* ser, Buproprion* bup, Vitamins* vit);
void tCheck(Testosterone* tes);
void showMenu();
void showPercentChoices();


int main(int argc, const char * argv[]) {
    Date* today = new Date;
    ifstream inFS;
    bool serTaken = false;
    bool bupTaken = false;
    bool vitTaken = false;
    vector<string> meds;
    vector<string> medsTaken;
    int i;
    int menuChoice;
    int optionChoice;
    
    // Display welcome and date
    Scene* welcome = new Scene("WELCOME");
    welcome->printTitleDate();
    delete welcome;
    
    // Create Med pointers
    Sertraline* ser = new Sertraline;
    Buproprion* bup = new Buproprion;
    Vitamins* vit = new Vitamins;
    Testosterone* tes = new Testosterone;
    
    // Populate string vector of Med names
    populateMeds(meds, ser, bup, vit);
    
    // Populate string vector of Meds that have been taken
    getMedsTaken(medsTaken, ser, bup, vit);
    
    // If it is Monday, check if testosterone has been taken
    if (today->getWeekday() == "MONDAY") {
        tCheck(tes);
    }
    
    // If no Meds have been taken, log new status for all Meds
    if (medsTaken.size() == 0) {
        ser->logMed();
        bup->logMed();
        vit->logMed();
    }
    
    // Otherwise, log new status for only Meds that are not in vector of taken Meds
    else {
        
        // Check if Med name is in vector of taken Meds and store status
        for (i = 0; i < medsTaken.size(); ++i) {
            
            string current = medsTaken.at(i);
            
            if (current == ser->getName()) {
                serTaken = true;
            }
            else if (current == bup->getName()) {
                bupTaken = true;
            }
            else if (current == vit->getName()) {
                vitTaken = true;
            }
        }
        
        // If Med has not been taken, log new status
        if (!serTaken) {
            ser->logMed();
        }
        if (!bupTaken) {
            bup->logMed();
        }
        if (!vitTaken) {
            vit->logMed();
        }
    }
    
    cout << endl;
    cout << "Meds have been logged..." << endl;
    cout << "Press enter to continue..." << endl;
    
    cin.ignore();
    cin.get();
    
    // Display menu
    showMenu();
    
    // Get user menu choice
    cout << "Enter a menu option 1-5: ";
    cin >> menuChoice;
    
    while (menuChoice != 5) {
        try {
            switch (menuChoice) {
                case 1:
                    try {
                        Scene* percents = new Scene("PERCENTAGES");
                        showPercentChoices();
                        cout << "Please enter an option 1-5: ";
                        cin >> optionChoice;
                        
                        while ((optionChoice < 1) || (optionChoice > 5)) {
                            cout << "ERROR: Invalid entry." << endl;
                            cout << "Please enter an option 1-5: ";
                            cin >> optionChoice;
                        }
                                                
                        switch (optionChoice) {
                            case 1:
                                ser->showPercentages();
                                percents->endScene();
                                cout << "Press enter to continue..." << endl;
                                cin.ignore();
                                cin.get();
                                break;
                            case 2:
                                bup->showPercentages();
                                percents->endScene();
                                cout << "Press enter to continue..." << endl;
                                cin.ignore();
                                cin.get();
                                break;
                            case 3:
                                vit->showPercentages();
                                percents->endScene();
                                cout << "Press enter to continue..." << endl;
                                cin.ignore();
                                cin.get();
                                break;
                            case 4:
                                tes->showPercentages(today);
                                percents->endScene();
                                cout << "Press enter to continue..." << endl;
                                cin.ignore();
                                cin.get();
                                break;
                            case 5:
                                ser->showPercentages();
                                percents->endScene();
                                cout << "Press enter to continue..." << endl;
                                cin.ignore();
                                cin.get();
                                bup->showPercentages();
                                percents->endScene();
                                cout << "Press enter to continue..." << endl;
                                cin.get();
                                vit->showPercentages();
                                percents->endScene();
                                cout << "Press enter to continue..." << endl;
                                cin.get();
                                tes->showPercentages(today);
                                percents->endScene();
                                cout << "Press enter to continue..." << endl;
                                cin.get();
                                break;
                            default:
                                throw "ERROR: ";
                                break;
                        }
                        delete percents;
                    }
                    catch (string err) {
                        cout << err << "Internal error, invalid menu choice was validated." << endl;
                    }
                    break;
                case 2:
                    // update
                    break;
                case 3:
                    // view file
                    break;
                case 4:
                    // graphs
                    break;
                default:
                    throw ("Invalid menu choice.");
                    break;
            }
            
            // Display menu
            showMenu();
            
            // Get user menu choice
            cout << "Enter a menu option 1-5: ";
            cin >> menuChoice;
        }
        catch (string err) {
            cout << "ERROR: " << err << endl;
            cout << "\nPlease enter a menu option 1-5: ";
            cin >> menuChoice;
        }
    }
    
    
    // Clean
    delete ser;
    delete bup;
    delete vit;
    delete tes;
    delete today;
    
    cout << "\nGoodbye." << endl;
    
    return 0;
}

// Populate string vector of Med names
void populateMeds(vector<string> &meds, Sertraline* ser, Buproprion* bup, Vitamins* vit) {
    meds.push_back(ser->getName());
    meds.push_back(bup->getName());
    meds.push_back(vit->getName());
}

// Populate string vector of Meds that have been taken
void getMedsTaken(vector<string> &medsTaken, Sertraline* ser, Buproprion* bup, Vitamins* vit) {
    string output = "-999";
    string const OUTA = "Good job! You took ";
    string const OUTB = " today.\n";

    if (ser->hasBeenTaken()) {
        // at least sert
        output = OUTA + ser->getName();
        medsTaken.push_back(ser->getName());
        
        if (bup->hasBeenTaken()) {
            medsTaken.push_back(bup->getName());
            
            if (vit->hasBeenTaken()) {
                // sert, bup, vit
                output = output + ", " + bup->getName() + ", and " + vit->getName() + OUTB;
                medsTaken.push_back(vit->getName());
            }
            else {
                // sert, bup
                output = output + " and " + bup->getName() + OUTB;
            }
        }
        else {
            if (vit->hasBeenTaken()) {
                // sert, vit
                output = output + " and " + vit->getName() + OUTB;
                medsTaken.push_back(vit->getName());
            }
            else {
                // sert
                output = output + OUTB;
            }
        }
    }
    else if (bup->hasBeenTaken()) {
        // at least bup, not sert
        output = OUTA + bup->getName();
        medsTaken.push_back(bup->getName());
            
        if (vit->hasBeenTaken()) {
            // bup, vit
            output = output + " and " + vit->getName() + OUTB;
            medsTaken.push_back(vit->getName());
        }
        else {
            // bup
            output = output + OUTB;
        }
    }
    else {
        if (vit->hasBeenTaken()) {
            // vit
            output = OUTA + vit->getName() + OUTB;
            medsTaken.push_back(vit->getName());
        }
        else {
            // nothing
            output = "";
        }
    }
    
    cout << output << endl;
}

// Check if testosterone has been taken
void tCheck(Testosterone* tes) {
    bool tesTaken = false;
    
    cout << "It is Monday!" << endl;
    cout << endl;
        
    tesTaken = tes->hasBeenTaken();
    
    if (tesTaken) {
        cout << "Good job! You took " << tes->getName() << " today.\n";
    }
    else {
        tes->logMed();
    }
}

void showMenu() {
    Scene* menu = new Scene("MENU");
    menu->printTitleDate();
    
    cout << "1. Show percentages" << endl;
    cout << "2. Update status" << endl;
    cout << "3. View file contents" << endl;
    cout << "4. Display graphs" << endl;
    cout << "5. Quit" << endl;
    
    menu->endScene();
    delete menu;
}

void showPercentChoices() {
    Scene* percents = new Scene("PERCENTAGES");
    cout << endl;
    percents->printTitleDate();
    
    cout << "Which med percentages would you like to see?\n" << endl;
    cout << "1. Sertraline" << endl;
    cout << "2. Buproprion" << endl;
    cout << "3. Vitamin D" << endl;
    cout << "4. Testosterone" << endl;
    cout << "5. View all meds" << endl;
    
    percents->endScene();
    delete percents;
}
