#ifndef EVENT_H
#define EVENT_H

#include "Date.h"
#include "Time.h"
#include <iomanip>

#include <string>
using namespace std;

#define MAX_PART      24

class Event{

    public:
        Event(int=0,string="NA",string="NA",string="NA",int=0,int=0,int=0,int=-1,int=-1);
        int getId();
        string getCategory();
        Date getDate();
        void set(Event&);
        void addParticipant(string);
        bool lessThan(Event&);
        void print();

    private:
        int id;
        string name;
        string category;
        string participants[MAX_PART];
        int participantNum;
        Date d;
        Time t;

};


#endif