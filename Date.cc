#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y)
{
  set(d, m, y);
}

void Date::set(int d, int m, int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth(m, y) ) ? d : 0 );
}

/// @brief sets the current Date object to the same values 
///        as the given date reference by calling previous function.
/// @param d , date reference to copy values from.
void Date::set(Date& d){
  set(d.day, d.month, d.year);
}

void Date::print()
{
  cout << right << setfill('0') << setw(4) << year << "-"
       << setw(2) << month << "-"
       << setw(2) << day;
}

int Date::lastDayInMonth(int m, int y)
{ 
  switch(m)
  {
    case 2:
      if (leapYear(y))
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30; 
  }
}

bool Date::leapYear(int y)
{ 
  if ( y%400 == 0 ||
       (y%4 == 0 && y%100 != 0) )
    return true;
  else
    return false;
}   
  
string Date::getMonthStr(int m)
{
  string monthStrings[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( m >= 1 && m <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
} 

/// @brief checks the strict equality of the current date object 
///        with the given date object by reference.
/// @param d , the date to be compared to.
/// @return ,true if all values are the same, false otherwise.
bool Date::equals(Date& d){
  if (d.year == year && d.month == month && d.day == day) return true; 
  return false;
}

/// @brief returns true if the Date object that calls this 
///        function occurs earlier than the provided Date reference.
/// @param d , the date to be compared.
/// @return true, if it strictly occurs earlier, else false.
bool Date::lessThan(Date& d){
  // check if year is greater
  if (year < d.year) return true;
  // if they are equal then need to check months
  if (year == d.year){
    if (month < d.month)return true;
    //if months are equal check days
    if (month == d.month){
      if (day < d.day)return true;
    }
  }
  return false;
}

/// @brief checks if provided date values are witin the bounds as follows:
///        year is positive, 
///        months is between 1 and 12,
///        day is within 1 and the last day in that month.
/// @param d , day
/// @param m , month
/// @param y , year
/// @return true if conditions are met, else false.
bool Date::validate(int d, int m, int y){

  if (y < 1) return false;
  if (m < 1 || m > 12) return false;

  // uses lastDayInMonth to check if it's a valid day for the month
  if (d < 1 || d > lastDayInMonth(m,y)) return false;
  
  return true;
}