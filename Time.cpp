#include "Time.h"
#include <iostream>
using namespace std;
//Parametraized Constructor 
Time::Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {}
Time& Time::get_time() {
    return *this;
}
void Time::set_time(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

bool Time::operator==(const Time& other) const {
    return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
}

bool Time::less_than(const Time& t1, const Time& t2) {
    // Returns true if t1 is less than t2, else false
    // Assuming the time is compared based on hours, then minutes, then seconds
    if (t1.hours < t2.hours)
        return true;
    else if (t1.hours == t2.hours && t1.minutes < t2.minutes)
        return true;
    else if (t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds < t2.seconds)
        return true;
    else
        return false;
}

bool Time::greater_than(const Time& t1, const Time& t2) {
    // Returns true if t1 is greater than t2, else false
    // Assuming the time is compared based on hours, then minutes, then seconds
    if (t1.hours > t2.hours)
        return true;
    else if (t1.hours == t2.hours && t1.minutes > t2.minutes)
        return true;
    else if (t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds > t2.seconds)
        return true;
    else
        return false;
}

bool Time::compare(const Time& other, bool (*fptr)(const Time& t1, const Time& t2)) const {
    // Compare two time instances
    return fptr(*this, other);
}