#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "defs.h"
#include "Calendar.h"

/// @brief constructor for a Calendar object.
/// @param user , the name of the owner of the calendar
Calendar::Calendar(string user){
    username = user;
    numEvents = 0;
    nextId = EVENTS_ID;
}

/// @brief Adds an event with provided parameters to the event array.
/// @param n , name of event
/// @param cat , category of event
/// @param part , main participant
/// @param yr 
/// @param mth 
/// @param day 
/// @param hrs 
/// @param mins 
/// @return 
bool Calendar::addEvent(string n, string cat, string part, int yr, int mth, int day, int hrs, int mins){

    // creates temporary Date and Time object to validate time and date.
    // also to pass into function for copying into array.
    Date testDate(day,mth,yr);
    Time testTime(hrs,mins);
    
    // checks if time provided is valid. if not, prints a debug message.
    if (!testTime.validate(hrs,mins)){
        cout << "Time provided is invalid" << endl;
        return false;
    }

    // checks if date provided is valid. if not, prints a debug message.
    if (!testDate.validate(day,mth,yr)){
        cout << "Date provided is invalid" << endl;
        return false;
    }

    // check if array is full.
    if (numEvents == MAX_ARR) return false;


    // creates the event object to be added
    Event e(nextId,n,cat,part,yr,mth,day,hrs,mins);

    // increments the next id value if it is valid
    nextId++;

    // check if it is first element to be added for quick return.
    if (numEvents == 0){
        events[numEvents].set(e);
        numEvents++;
        return true;
    }

    // check if insertion point is between existing elements
    for (int i = 0; i < numEvents; i++){
        if (e.lessThan(events[i])){
            // if insertion point is found, 
            // shift elements one position over to make room.
            for (int j = numEvents; j > i; j--){
                events[j].set(events[j-1]);
            }

            events[i].set(e);
            numEvents++;
            return true;
        }
    } 

    // if not found, add to back of array.
    events[numEvents].set(e);
    numEvents++;
    return true;

}

/// @brief loops though event array and checks if there is a match. 
///        if so, update with the new participant
/// @param id , Id of event to add participant to.
/// @param n , name of new participant.
/// @return true, if an event matches the given Id, and is updated, else false.
bool Calendar::addParticipant(int id, string n){
    // checks if id exists in array
    for (int i = 0; i < numEvents; i++){
        // adds to event if found and returns true
        if (events[i].getId() == id){
            events[i].addParticipant(n);
            return true;
        }
    }
    // returns false if not found.
    return false;
}


/// @brief prints out the list of events by looping through event array and calling prints.
void Calendar::print(){
    cout << endl << "user name: " << username << endl << "Events: " << endl;
    for (int i = 0; i < numEvents; i++){
        events[i].print();
    }
    cout << endl;
}

/// @brief prints a list of events to console, given they match the provided date values.
/// @param yr , year
/// @param mth , month
/// @param day , day
void Calendar::printByDay(int yr, int mth, int day){
    Date dte(day,mth,yr);

    // checks if provided date is valid.
    if (!dte.validate(day,mth,yr)){
        cout << endl << "date for print is invalid" << endl;
        return;
    }

    // prints date.
    cout << "user name: " << username << endl << "events for date: ";
    dte.print();
    cout << endl;

    // loops through event array and check if each event's time equals the given time.
    for (int i = 0; i < numEvents; i++){
        if (events[i].getDate().equals(dte)){
            events[i].print();
        }
    }

}

/// @brief prints all events matching given category. Is case sensitive.
/// @param cat , category to match events with.
void Calendar::printByCat(string cat){
    cout << "user name: " << username << endl;
    cout << "Events for the category: " << cat << endl;

    // loops through events array and checks if the event matches given string.
    // if it does, then print it to console.
    for (int i = 0; i < numEvents; i++){
        if (events[i].getCategory() == cat){
            events[i].print();
        }
    }

}