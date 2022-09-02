//
//  Med.cpp
//  MedCheck1.3
//
//  Created by Heath Banak on 7/5/22.
//

#include <iostream>

using namespace std;

#include "Med.h"
#include "Scene.h"

// Default constructor
Med::Med() {
    name_ = "No name";
    dose_ = "No dose";
    file_ = "No file";
    noYes_ = -999;
    noNo_ = -999;
}

// Constructor with passed values
Med::Med(string name, string dose, string file) {
    name_ = name;
    dose_ = dose;
    file_ = file;
}

// Name accessor
string Med::getName() {
    return name_;
}

// Returns true if med is logged on the current day with a YES status
bool Med::hasBeenTaken() {
    string text;
    string errOut;
    bool hasTaken = true;
    Date* today = new Date;
    
    try {
        // open file to read
        inFS_.open(file_);
        
        // if file cannot be opened
        if (!inFS_.is_open()) {
            errOut = "Could not open " + name_ + " data file.";
            throw errOut;
        }
        
        // read in all lines of file to vector
        while (getline(inFS_, text)) {
            lines_.push_back(text);
        }
        
        // check each line of file for current date and YES status
        for (i_ = 0; i_ < lines_.size(); ++i_) {
            string current = lines_.at(i_);
            
            // if current date has status yes, exit for loop
            if (current == (today->getDate() + " YES")) {
                hasTaken = true;
                break;
            }
            else {
                hasTaken = false;
            }
        }
        
        // close file
        inFS_.close();
        
        // if file cannot close
        if (inFS_.is_open()) {
            errOut = "Could not close " + name_ + " data file.";
            throw errOut;
        }
    }
    catch (string err) {
        cout << "ERROR: " << err << endl;
    }
    
    // clean
    delete today;

    return hasTaken;
}

// Logs status of med for current day
void Med::logMed() {
    string answer;
    string output;
    string errOut;
    Date* today = new Date;
    
    try {
        // get user response
        cout << "Did you take " << name_ << " today?" << endl;
        cout << "Enter yes or no: ";
        
        cin >> answer;
        
        while ((answer != "yes") && (answer != "no")) {
            cout << "\nInvalid entry.\n\nPlease enter yes or no: ";
            
            cin >> answer;
        }
        
        // convert response to all caps
        for (i_ = 0; i_ < answer.size(); ++i_) {
            answer.at(i_) = toupper(answer.at(i_));
        }
        
        // open file to write out
        outFS_.open(file_);
        
        // if file cannot open
        if (!outFS_.is_open()) {
            errOut = "Could not open " + name_ + " data file.";
            throw errOut;
        }
        
        // log today's date and med status with newline
        output = today->getDate() + " " + answer + "\n";
        
        // write all previous lines to file
        // if med has been logged today do not rewrite today's line
        if (lines_.size() != 0) {
            if (lines_.at(lines_.size() - 1) == (today->getDate() + " NO")) {
                for (i_ = 0; i_ < lines_.size() - 1; ++i_) {
                    outFS_ << lines_.at(i_) << "\n";
                }
            }
            // if med has not been logged today, rewrite all lines (ensures no data is deleted)
            else {
                for (i_ = 0; i_ < lines_.size(); ++i_) {
                    outFS_ << lines_.at(i_) << "\n";
                }
            }
        }
        
        // add todays date and status to file
        outFS_ << output;
        
        // close file
        outFS_.close();
        
        // if file cannot close
        if (outFS_.is_open()) {
            errOut = "Could not close " + name_ + " data file.";
            throw errOut;
        }
        
        // output med with capital first letter
        string tempName = name_;
        tempName.at(0) = toupper(tempName.at(0));
        
        // print action complete message
        cout << endl;
        cout << tempName << " has been logged.\n" << endl;
    }
    catch (string err) {
        cout << "ERROR: " << err << endl;
    }
}

void Med::showPercentages() {
    size_t posYes = -1;
    size_t posNo = -1;
    double total = lines_.size();
    double percentYes = -9.9;
    double percentNo = -9.9;
    
    for (i_ = 0; i_ < lines_.size(); ++i_) {
        string curr = lines_.at(i_);
        string status = "";
        
        posYes = curr.find("YES");
        posNo = curr.find("NO");
        
        if (posYes != string::npos) {
            status = curr.substr(posYes, 3);
            yesses_.push_back(status);
        }
        if (posNo != string::npos) {
            status = curr.substr(posNo, 2);
            nos_.push_back(status);
        }
    }
    
    noYes_ = yesses_.size();
    noNo_ = nos_.size();
    
    percentYes = 100 * (noYes_ / total);
    percentNo = 100 * (noNo_ / total);
    
    string labelName = getName();
    
    for (i_ = 0; i_ < labelName.size(); ++ i_) {
        labelName.at(i_) = toupper(labelName.at(i_));
    }
    
    cout << endl;
    cout << labelName << endl;
    cout << "Percent days YES: " << noYes_ << "%\n";
    cout << "Percent days NO: " << noNo_ << "%\n" << endl;
    cout << "Total days logged:  " << total << endl;
    cout << endl;
}
