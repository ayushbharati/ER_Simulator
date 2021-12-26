// Ayush Bharati
// CS 273 Final Project 
// EMergency Room SImulator
// THis program is a simulator program that contains information about an Emergency Room. 



#include <iostream>
#include <vector>
#include <time.h>
#include <ostream>
#include <fstream>
#include <array>
#include <string>
#include "doctor.h"
#include "nurse.h"
#include "EmergencyRoom.h"
#include "person.h"

// Algorithm

// set up ER with doctors, nurses, num of patient per hour .
// set up your ER per hour
// fill the ER with nurse and doctor

// update room queue


// open the file
// push each of them in the vector of names that you created

// get a random name

// main function
// a vector of names
// set up a room and open the file to set up the ER

// run Time= all day/night

// run it everyday
// er will take the patient and
// treat the patients

// a string function that gets a random patients
std::string getAPatient(std::vector<std::string> residents)
{
    int x = rand() % 2000;
    std::string patient = residents.at(x);
    return patient;
}

// an emergency room function that does the specified function
void EmergencyRoomClinic(EmergencyRoom *ER)
{
    // create a random number of patients, doctors and nurses
    int doc = rand() % 20;
    int nurs = rand() % 20;
    int pPerhour = rand() % 40 + 20;
    cout << " There are " << doc << " doctors and " << nurs << " in the ER. " << std::endl;

    ER->setPatientPerHour(pPerhour);
 
    // adds doctor, nurses dyanmically
    for (int i = 0; i < doc; i++)
    {
        ER->addDoctor(new doctor);
    }

    for (int i = 0; i < nurs; i++)
    {
        ER->addNurse(new nurse);
    }
}

// a function that reads the name from the text and makes it as a vector
void openText(std::vector<std::string> *residents)
{
    std::string line;
    std::ifstream f;

    f.open("residents_of_273ville.txt");
    if (f.fail())
    {
        std::cout << " ERROR OPENING THE FILE. " << std::endl;
    }
    if (f.is_open())
    {
        while (getline(f, line))
        {
            residents->push_back(line); // sends each string of the residents vector 
        }
    }
    f.close();
}


int main()
{
    EmergencyRoom ER; // create an object 
    EmergencyRoom *ERp = &ER; // create a pointer that is pointing to the object
    EmergencyRoomClinic(ERp);

    std::vector<std::string> residents;
    openText(&residents);

    int x = 24 * 7 * 60; // since there is 168 hours in a day it updates every hour
    int count = 0;
    while (count < x)
    {
        int severity = rand() % 20; // gets a patient with random severity
        ERp->addPatient(new person(getAPatient(residents),severity) ) ; // dynamically add a new patient 
        ERp->takePatients(); 
        ERp->treatPatients();
    }
    ERp->displayRecords();
}

