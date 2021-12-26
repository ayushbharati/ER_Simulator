#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class person
{
private:
    string name;
    int severity;
    bool health;
    int numofvisits;
    double visittime;

public:
    // constructor function
    person();
    // 
    person(string name, int severity);
    
    string getName();
    int getSeverity();
    bool getHealth();
    int getnumofvisits();
    double getvisittime();


    bool isSick();
    //bool previoussick();
    void isSick(int severity);
    void getSick(int severity);
    person* curePerson();
    void addvisit();
    


    
};

#endif