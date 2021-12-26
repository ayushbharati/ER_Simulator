#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H
#include "abstract.h"
#include "person.h"
#include "nurse.h"
#include "doctor.h"
#include <queue>
#include <map>
#include <iterator>
#include <set>
#include <vector>
class EmergencyRoom
{
private :
    std::vector<person*> people ;
    std::set<doctor*> doctors;
    std::set<nurse*> nurses ;
    std::priority_queue<person*> high_severity ;
    std::priority_queue<person*> low_severity ;
    std::map<abstract*,person*> condition ;
    std::map<std::string , person*> oldpatients ;
    int patientperhour ;

public :
    EmergencyRoom();
    void addPatient(person* x);
    void addNurse(nurse* n);
    void addDoctor(doctor* d);
    void setPatientPerHour(int n);
    void takePatients();
    void treatPatients();
    ~EmergencyRoom();
    int getPatientPerHour();

    void printPatients();
    void searchName();
    void displayRecords();
    void printVisitTime();
};

#endif