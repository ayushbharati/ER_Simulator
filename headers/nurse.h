#ifndef NURSE_H
#define NURSE_H
#include <iostream>
#include "abstract.h"
using namespace std;

// A CLASS about the nurses in the emergency room

class nurse
{
private :
    bool busy;
    int workTime;
public :
    nurse();
    bool curePerson(person &P);
    bool canTreat(int severity);
    bool status();

};

#endif