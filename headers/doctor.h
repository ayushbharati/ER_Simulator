#include "abstract.h"
#include "person.h"
#include <string>
#ifndef DOCTOR_H
#define DOCTOR_H

// a doctor class 

class doctor : public abstract 
{
private :
    bool busy; // variable that says the doctor is always busy
    int workTime;

public :
    doctor();
    bool curePerson(person &P);
    bool status();
};

#endif