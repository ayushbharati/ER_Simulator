#include "doctor.h"

// constructor 
doctor::doctor()
{
    busy = false;
    workTime = 0;
}
// bool funtion that returns if the doctor is available
bool doctor::status()
{
    return busy ;
}
// a virtual void function that cures the patient based 
bool doctor :: curePerson(person &P)
{
    std::cout<< P.getName() << " is getting treated by a doctor." <<std::endl;
    if (!busy)
    {
        busy = true ;
    }
    // if the DOCTOR WORKTIME GREATER THAN SEVERITY, THE DOCTOR WILL CURE THE PATIENT
    if (workTime >= P.getSeverity())
    {
        P.curePerson();
        busy = false ;
        workTime = 0 ;
        return true;
    }
    else
    {
        workTime++;
        return false;
    }
}

