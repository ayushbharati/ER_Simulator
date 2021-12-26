#ifndef ABSTRACT_H
#define ABSTRACT_H
#include <iostream>
#include "person.h"
using namespace std;

// an abstract class with virtual void functions.
class abstract
{
    virtual bool curePatient(person &P);
    virtual bool status();
};

#endif