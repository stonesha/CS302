#include "Vehicle.h"

int Vehicle::s_idgen = 0;

Vehicle::Vehicle()
{
    //ctor
    cout << "Vehicle" << m_vin << ": Default-ctor";
}

Vehicle::Vehicle(int x, float *lla)
{
    cout << "Vehicle" << m_vin << ": Default-ctor";
}

Vehicle::~Vehicle()
{
    //dtor
}
