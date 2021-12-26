#include "nurse.h"

nurse::nurse()
{
    busy = false;
    workTime = 0;
}
bool nurse::curePerson(person &P)
{
    std::cout<< P.getName() <<"is getting treated by a Nurse." <<std::endl;
    if (!busy)
    {
        busy = true ;
    }
    if (workTime >= P.getSeverity())
    {
        P.curePerson();
        busy = false;
        workTime = 0 ;
        return true;
    }
    else
    {
        workTime++;
        return false;
    }
}

bool nurse::canTreat(int severity)
{
    if (severity <= 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}