#include <iostream>
#include <string>

bool isLeap(int year){
    return ((year % 4) == 0 && ((year % 100) != 0) || (year % 400) == 0);
}

int leap_Years(int year){
    return (year / 4) - (year/100) + (year/400);
}

int daysSince1971(const std::string& date1){
    const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = (date1[0]-'0') * 1000 + (date1[1]-'0') * 100 + (date1[2]-'0') * 10 + (date1[3]-'0'); 
    int month = (date1[5] -'0')* 10 + (date1[6] - '0');
    int day = (date1[8] -'0')* 10 + (date1[9] - '0');
    int leapYears = leap_Years(year-1) - leap_Years(1971);
    if(month > 2){
        if (isLeap(year)){
            day++;
        }
    } 
    int daysInMo = 0;
    // remove one for the index
    month--;
    // remove one for the current month i will not count it

    month--;
    while(month >= 0){
        daysInMo += daysInMonth[month];
        month--;
    }
    return ((year- 1971)* 365 + leapYears + daysInMo + day); 
}

int daysBetweenDates(std::string date1, std::string date2) {
       // 2019-06-30
       // 0123456789
       int daysBetween = daysSince1971(date1) - daysSince1971(date2);
       if(daysBetween > 0) return daysBetween;
       return -1 * daysBetween;
}

