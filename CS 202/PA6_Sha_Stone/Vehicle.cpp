#include "Vehicle.h"

Vehicle::Vehicle()
{
    //ctor

    cout << "Vehicle: Default-ctor" << endl;
}

Vehicle::Vehicle(const float *ptr)
{
    //copy ctor

    SetLLA(ptr);

    cout << "Vehicle: Parameterized-ctor" << endl;
}


Vehicle::~Vehicle()
{
    //dtor

    cout << "Vehicle: Dtor" << endl;
}

Vehicle::Vehicle(const Vehicle& other)
{
    //copy ctor
    SetLLA(other.m_lla);

    cout << "Vehicle: Copy-ctor" << endl;
}

//operator overloads
Vehicle& Vehicle::operator=(const Vehicle& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    for(int i = 0; i < 3; i++)
    {
        m_lla[i] = rhs.m_lla[i];
    }

    cout << "Vehicle: Assignment" << endl;

    return *this;
}

ostream& operator<<(ostream& outFile, const Vehicle& vehicleObj)
{
    vehicleObj.serialize(outFile);

    return outFile;
}

//GET AND SET
void Vehicle::SetLLA(const float* ptr)
{
    for(int i = 0; i < 3; i++, ptr++)
    {
        m_lla[i] = *ptr;
    }
}

float Vehicle::getLla(int i)
{
    return m_lla[i];
}

//Serialize
void Vehicle::serialize(ostream& outFile)const
{
    outFile << "Vehicle @ [" << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]" << endl;
}
