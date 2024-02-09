#ifndef TIME_H
#define TIME_H

class Time
{
  public:
    Time(int=0, int=0);
    void set(int, int);
    void set(Time&);
    void print();
    bool lessThan(Time&);
    bool validate(int, int);

  private:
    int hours;
    int minutes;
    int convertToMins();
};

#endif
