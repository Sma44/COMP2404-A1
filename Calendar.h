#ifndef CALENDAR_H
#define CALENDAR_H

#include "defs.h"
#include "Event.h"

#include <string>
using namespace std;

class Calendar{

    public:
        Calendar(string="NA");
        bool addEvent(string,string,string,int,int,int,int,int);
        bool addParticipant(int,string);
        void print();
        void printByDay(int,int,int);
        void printByCat(string);

    private:
        string username;
        Event events[MAX_ARR];
        int numEvents;
        int nextId;
};

#endif