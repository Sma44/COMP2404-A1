#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Event.h"

/// @brief constructor for the Event class object.
/// @param i , event's unique Id.
/// @param n , name of event.
/// @param c , category.
/// @param part , main participant.
/// @param y , year.
/// @param m , month.
/// @param day , day.
/// @param h , hours.
/// @param min , minutes.
Event::Event(int i, string n, string c, string part, int y, int m, int day, int h, int min){
    id = i;
    name = n;
    category = c;
    participantNum = 0;
    addParticipant(part);

    //partial validation here


    d.set(day, m, y);
    t.set(h,min);
}

/// @brief Simple getters for Id, Category, and Date.
/// @return , their respective values.
int Event::getId(){
    return id;
}

string Event::getCategory(){
    return category;
}

Date Event::getDate(){
    return d;
}

/// @brief sets the current Event object's values to the given
///        Event object's values.
/// @param e , the Event to copy from.
void Event::set(Event& e){
    id = e.id;
    name = e.name;
    category = e.category;
    
    // loops through given Event's participant array and copies their participants.
    // this creates a deep copy.
    for (int i = 0; i < e.participantNum; i++){
        addParticipant(e.participants[i]);
    }
    participantNum = e.participantNum;
    // calls previously defined functions to set date and time
    d.set(e.d);
    t.set(e.t);
}

/// @brief adds a new participant to the participant array. updates number of participants.
/// @param p , name of the new participant
void Event::addParticipant(string p){
    // if the default constuctor is called, then the participants do not get updated.
    // this check is done since this function is called to set main participant in constructor.
    if (p == "NA"){return;}
    participants[participantNum] = p;
    participantNum++;
}

/// @brief checks strict equality that current Event object is less than given object.
///        checks first the date, and if they are equal, then the time.
/// @param e , the Event to compare current Event to.
/// @return , true is equality satisfied, else false.
bool Event::lessThan(Event& e){
    if (d.lessThan(e.d)) return true;
    if (e.d.equals(d)){
        if (t.lessThan(e.t)) return true;
        return false;
    }
    return false;
}


/// @brief prints the event with specified format
void Event::print(){

    // prints out the id, category, and name of event.
    cout << "== " << setw(5) 
         << setfill(' ') << left << id 
         << setw(6) << left << category << setw(3) << left << "::" 
         << setw(34) << left << name << setw(3) << left << "::";
    
    // prints date.
    d.print();

    cout << setw(0) << setfill(' ') << " " << setw(2) << left << "@";
    
    // prints time.
    t.print();

    cout << setw(6) << setfill(' ') << left << " with " ;

    // loops through participants array and prints all participants with comma separation.
    for (int i = 0; i < participantNum; i++){
        cout << participants[i];
        if (i+1 != participantNum){
            cout << ", ";
        }
    }

    cout << endl;
}
