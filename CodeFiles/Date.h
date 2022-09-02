//
//  Date.h
//  MedCheck1.3
//
//  Created by Heath Banak on 7/3/22.
//

#ifndef Date_h
#define Date_h

#include <ctime>
#include <string>

using namespace std;

class Date {
public:
    Date();
    string getDate();
    string getDisplayDate();
    string getWeekday();
private:
    string getMonthNum();
    string getDayNum();
    int i;
    time_t now_;
    char* tDate_;
    string today_;
    string weekday_;
    string month_;
    string day_;
    string year_;
};

#endif /* Date_h */
