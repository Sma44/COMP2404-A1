#include <iostream>
using namespace std;
#include <string>

#include "defs.h"
#include "Calendar.h"


int main()
{
  // create calendar object of Timmy Tortoise.
  Calendar cal("Timmy Tortoise");

  // calls function to add events
  loadEvents(cal);

  // populates a choice variable to store user input.
  int uChoice = 5;

  // while the user choses not to exit.
  while (uChoice != 0){
    // displays the choice menu.
    showMenu(uChoice);

    // temp variable to store user input.
    string name,cat,part,buffer;
    int yr,mth,day,hr,min;

    // if user wants to print calendar.
    if (uChoice == 1){
      cal.print();
    }

    // if user wants to print by day.
    if (uChoice == 2){
        //used to clear buffer due to getline calls.
        cin.ignore();
        cout << "enter a year: " << endl;
        cin >> yr;
        cout << "enter a month: " << endl;
        cin >> mth;
        cout << "enter a day: " << endl;
        cin >> day;
        // calls printByDay with given input
        cal.printByDay(yr,mth,day);
    }

    // if user choses to print by category.
    if (uChoice == 3){
      //used to clear buffer due to getline calls.
      cin.ignore();
      cout << "enter a category: " << endl;
      getline(cin, cat);
      // calls printByCat function with given category.
      cal.printByCat(cat);
    }

    // if user wants to create a new event.
    if (uChoice == 4){
      //used to clear buffer due to getline calls.
      cin.ignore();
      cout << "enter an event name: " << endl;
      getline(cin, name);
      cout << "enter a category: " << endl;
      getline(cin, cat);
      cout << "enter main participant: " << endl;
      getline(cin, part);
      cout << "enter a year: " << endl;
      cin >> yr;
      cout << "enter a month: " << endl;
      cin >> mth;
      cout << "enter a day: " << endl;
      cin >> day;
      cout << "enter a start hour: " << endl;
      cin >> hr;
      cout << "enter minutes: " << endl;
      cin >> min;
      // calls addEvent with given input
      cal.addEvent(name,cat,part,yr,mth,day,hr,min);
    }
  }

  return 0;
}

void showMenu(int& choice)
{
 int numOptions = 4;

  cout << endl << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) View calendar" << endl;
  cout << "  (2) View day calendar" << endl;
  cout << "  (3) View category calendar" << endl;
  cout << "  (4) Add an event" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > numOptions) {
    cout << "invalid selection. Try again: " << endl;
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void loadEvents(Calendar& cal)
{
  cal.addEvent("2024 National Heroes Conference", "Work",  "Timmy", 2024,  2, 25,  8, 30);
  cal.addEvent("2023 National Heroes Conference", "Work",  "Timmy", 2023,  2, 24,  8, 30);
  cal.addEvent("Slay dragon",                     "Work",  "Timmy", 2024,  4, 11,  9, 30);
  cal.addEvent("Climb Mount of Dooom",            "Work",  "Timmy", 2024,  4,  8, 10,  0);
  cal.addEvent("some thing",                      "Work",  "Timmy", 2024,  3, 32, 10,  0);
  cal.addEvent("some other thing",                "Other", "Timmy", 2023,  2,  1, 24,  0);
  cal.addEvent("some new thing",                  "Test",  "Timmy", 2023,  2, 18, 14,  0);
  cal.addEvent("Lunch with Gwendolyn",            "Home",  "Timmy", 2024,  3, 29, 11, 45);
  cal.addEvent("Heroes meeting",                  "Work",  "Timmy", 2024,  1,  8,  9,  0);
  cal.addEvent("Practice sparring",               "Work",  "Timmy", 2024,  1, 10, 13, 45);
  cal.addEvent("Sharpen sword",                   "Work",  "Timmy", 2024,  1, 10, 13,  5);
  cal.addEvent("Dinner with Harold",              "Home",  "Timmy", 2024,  3, 30, 18, 30);
  cal.addEvent("Theatre with Harold",             "Home",  "Timmy", 2024,  3, 30, 16,  0);
  cal.addEvent("Grocery shopping",                "Home",  "Timmy", 2024,  1, 20,  9, 45);
  cal.addEvent("Meeting with Wizard",             "Work",  "Timmy", 2024,  3, 28,  6, 15);
  cal.addEvent("some bad thing",                  "Home",  "Timmy", 2023, 22, 18, 14,  0);

  cal.addParticipant(3012, "Harold");
  cal.addParticipant(3011, "Harold");
  cal.addParticipant(3004, "Harold");
  cal.addParticipant(3009, "Harold");
  cal.addParticipant(3004, "Dorc friends");
  cal.addParticipant(3003, "Harold");
  cal.addParticipant(3007, "Gwendolyn");
}

