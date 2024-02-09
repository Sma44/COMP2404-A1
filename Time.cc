#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

Time::Time(int h, int m)
{
  set(h, m);
}

void Time::set(int h, int m)
{
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

int Time::convertToMins()
{
  return (hours*60 + minutes);

}

void Time::print()
{
  cout<<setfill('0') << right <<setw(2)<<hours<<":"
      <<setfill('0')<<setw(2)<<minutes;
}

/// @brief calls previous function to set current Time object
///        to the same values as given Time object.
/// @param t , the Time object to be copied from.
void Time::set(Time& t){
  set(t.hours, t.minutes);
}

/// @brief checks that current Time object is strictly less than
///        given Time object. If the values are equal, it returns false.
/// @param t , the Time object to be compared to.
/// @return true, if condition is satisfied, else false.
bool Time::lessThan(Time& t){
  if (hours > t.hours){ return false;}
  //if hours are the same then minutes must be compared
  else if (hours == t.hours){
    if (minutes >= t.minutes) {return false;}
  }
  return true;
}

/// @brief checks if provided values confine with possible values in a 24hr 
///        time format. hours, must be between 0 and 23, minutes, between 0 and 59.
/// @param h , hours
/// @param m , minutes
/// @return true if conditions are satisfied, else false.
bool Time::validate(int h, int m){
  if (h < 0 || h > 23) return false;
  if (m < 0 || m > 59) return false;
  return true;
}
