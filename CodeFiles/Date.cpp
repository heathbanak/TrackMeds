//
//  Date.cpp
//  MedCheck1.3
//
//  Created by Heath Banak on 7/3/22.
//

#include <ctime>

using namespace std;

#include "Date.h"

Date::Date() {
    now_ = time(0);
    tDate_ = ctime(&now_);
    today_ = tDate_;
    
    weekday_ = today_.substr(0, 3);
    month_ = today_.substr(4, 3);
    day_ = today_.substr(8, 2);
    year_ = today_.substr(today_.size() - 5, 4);
}

string Date::getMonthNum() {
    string month = "-999";
    
    if (month_ == "Jan") {
        month = "01";
    }
    if (month_ == "Feb") {
        month = "02";
    }
    if (month_ == "Mar") {
        month = "03";
    }
    if (month_ == "Apr") {
        month = "04";
    }
    if (month_ == "May") {
        month = "05";
    }
    if (month_ == "Jun") {
        month = "06";
    }
    if (month_ == "Jul") {
        month = "07";
    }
    if (month_ == "Aug") {
        month = "08";
    }
    if (month_ == "Sep") {
        month = "09";
    }
    if (month_ == "Oct") {
        month = "10";
    }
    if (month_ == "Nov") {
        month = "11";
    }
    if (month_ == "Dec") {
        month = "12";
    }
    
    return month;
}

string Date::getDayNum() {
    char first = day_.at(0);
    
    if (first == ' ') {
        day_.replace(0, 1, "0");
    }
    
    return day_;
}

string Date::getWeekday() {
    string weekday = "-999";
    
    if (weekday_ == "Sun") {
        weekday = "SUNDAY";
    }
    if (weekday_ == "Mon") {
        weekday = "MONDAY";
    }
    if (weekday_ == "Tue") {
        weekday = "TUESDAY";
    }
    if (weekday_ == "Wed") {
        weekday = "WEDNESDAY";
    }
    if (weekday_ == "Thu") {
        weekday = "THURSDAY";
    }
    if (weekday_ == "Fri") {
        weekday = "FRIDAY";
    }
    if (weekday_ == "Sat") {
        weekday = "SATURDAY";
    }
    
    return weekday;
}

string Date::getDate() {
    string formatDate = "-999";
    
    formatDate = getMonthNum() + "/" + getDayNum() + "/" + year_;
    
    return formatDate;
}

string Date::getDisplayDate() {
    string formatDate;
    
    formatDate = getWeekday() + " " + getDate();
    
    return formatDate;
}
