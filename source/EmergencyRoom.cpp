#include "EmergencyRoom.h"

EmergencyRoom::EmergencyRoom()
{
}

// a void functions that adds a patient
void EmergencyRoom::addPatient(person *x)
{
    std::cout << " Patient " << x->getName() << " arrives with severity " << x->getSeverity() << std::endl;
    if (x->getSeverity() == 0)
    {
        std::cout << " Regular check up for " << x->getName() << std::endl;
    }
    else
    {
        // checks the condition if the severity is 10
        if (x->getSeverity() > 10)
        {
            if (oldpatients[x->getName()] == NULL) // if the patient has visited the hospital before
            {
                std::cout << " This patient is vistiing first time . " << std::endl;
                high_severity.push(x); // push the patient to the queue
                oldpatients[x->getName()] = x;
            }
            else
            {
                oldpatients[x->getName()]->getSick(x->getSeverity());
                high_severity.push(oldpatients[x->getName()]);
            }
        }
        else
        {
            if (oldpatients[x->getName()] == NULL)
            {
                std::cout << " This patient is vistiing first time . " << std::endl;
                low_severity.push(x);
                oldpatients[x->getName()] = x;
            }
            else
            {
                oldpatients[x->getName()]->getSick(x->getSeverity());
                low_severity.push(oldpatients[x->getName()]);
            }
        }
    }
}

// adds the nurses to the nurses set
void EmergencyRoom::addNurse(nurse *n)
{
    nurses.insert(n);
}

// adds the doctor to the doctor set
void EmergencyRoom::addDoctor(doctor *d)
{
    doctors.insert(d);
}

// a setter function
void EmergencyRoom::setPatientPerHour(int n)
{
    patientperhour = n;
}
// a function that maps the patient with the doctor
void EmergencyRoom::takePatients()
{
    std::set<doctor *>::iterator i = doctors.begin();
    bool doctorBusy = false;
    while ((*i)->status())
    {
        i++;
        if (i == doctors.end())
        {
            doctorBusy = true;
            break;
        }
    }

    if (!doctorBusy)
    {
        if (!high_severity.empty())
        {
            (*i)->curePerson(*high_severity.top());
            condition[*i] = high_severity.top();
            high_severity.pop();
        }
        else if (!low_severity.empty())
        {
            (*i)->curePerson(*low_severity.top());
            condition[*i] = low_severity.top();
            low_severity.pop();
        }
    }

    std::set<nurse *>::iterator j = nurses.begin();
    bool nurseBusy = false;
    while ((*j)->status())
    {
        j++;
        if (j == nurses.end())
        {
            nurseBusy = true;
            break;
        }
    }

    if (!nurseBusy)
    {
        if (!low_severity.empty())
        {
            (*j)->curePerson(*low_severity.top());
            condition[*i] = low_severity.top();
            low_severity.pop();
        }
    }
}

// a cure function that cures the patient and erases the severity condition after treated 
void EmergencyRoom::treatPatients()
{
    std::set<doctor *>::iterator i = doctors.begin();
    std::set<nurse *>::iterator j = nurses.begin();

    while (i != doctors.end())
    {
        if ((*i)->status())
        {
            if ((*i)->curePerson(*condition[*i]))
            {
                condition.erase(*i);
            }
        }
        ++i;
    }
}

// a getter function for patient per hour
int EmergencyRoom::getPatientPerHour()
{
    return patientperhour;
}

// a function that prints the patients list
void EmergencyRoom::printPatients()
{
    std::map<std::string, person *>::iterator i = oldpatients.begin();
    std::cout << " Treated Patients : " << std::endl;

    for (i; i != oldpatients.end(); i++)
    {
        std::cout << (*i).second->getName() << " visits : " << (*i).second->getnumofvisits() << std::endl;
        std::cout << " " << (*i).second->getvisittime() << std::endl;
    }
}

void EmergencyRoom::searchName()
{
    std::string name;
    std::cout << " Enter a name : ";
    std::cin >> name;

    std::map<std::string, person *>::iterator i;

    i = oldpatients.find(name);
    std::cout << (*i).second->getName() << " visits " << (*i).second->getnumofvisits() << std::endl;
    std::cout << " " << (*i).second->getvisittime() << std::endl;
}

void EmergencyRoom::printVisitTime()
{
    float numTreated = oldpatients.size();
    float totalTime = 0;
    std::map<std::string, person *>::iterator i = oldpatients.begin();
    for (i; i != oldpatients.end(); i++)
    {
        if (!(*i).second->isSick())
        {
            totalTime += (*i).second->getvisittime();
        }
    }
    std::cout << " average visit time : " << totalTime / numTreated << std::endl;
}

void EmergencyRoom::displayRecords()
{
    int ans = 0;
    while (ans != 4)
    {
        std::cout << " Options " << std::endl;
        std::cout << " 1.  List of old patients " << std::endl;
        std::cout << " 2. look for a patient " << std::endl;
        std::cout << " 3. EXIT " << std::endl;

        if (ans < 0 || ans > 4)
        {
            std::cout << "Non valid option. " << std::endl;
        }

        else if (ans = 1)
        {
            printPatients();
            break;
        }
        else if (ans = 2)
        {
            searchName();
            break;
        }
        else
        {
            break;
        }
    }
}