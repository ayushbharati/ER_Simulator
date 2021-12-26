#include "person.h"
#include <iostream>
using namespace std;

person::person()
{
    severity = 0;
    health = false;
    numofvisits = 0;
    visittime = 0;
}

person::person(string name, int severity)
{
    this->name = name;
    if (severity > 0)
    {
        this->getSick(severity);
    }
}

// getter and setter functions
string person::getName()
{
    return name ;
}
int person::getSeverity()
{
    return severity ; 
}
bool person::getHealth()
{
    return health;
}
int person::getnumofvisits()
{
    return numofvisits;
}
double person::getvisittime()
{
    return visittime;
}

bool person::isSick()
{
    return health;
}
void person::getSick(int severity)
{
    this->severity = severity;
    health = true ;
    visittime += severity ;  
}
// a cure function that return the current status 
person *person::curePerson()
{
    health = false ;
    severity = 0 ;
    numofvisits++;
    return this ;
}


void person::addvisit()
{
    numofvisits++;
}

