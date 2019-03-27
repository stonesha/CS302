#include "Car.h"

//constructors and destructors
Car::Car()
{
    //ctor

    m_throttle = 0;
    cout << "Car: Default-ctor" << endl;

}

Car::~Car()
{
    //dtor

    cout << "Car: Dtor" << endl;
}

Car::Car(float *ptr)
{
    SetLLA(ptr);
    m_throttle = 0;
    cout << "Car: Parameterized-ctor" << endl;
}

Car::Car(const Car& other)
{
    //copy ctor

    Vehicle::SetLLA(other.m_lla);

    m_throttle = other.m_throttle;

    cout << "Car: Copy-ctor" << endl;
}

//operator overloads
Car& Car::operator=(const Car& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    for(int i = 0; i < 3; i++)
    {
        m_lla[i] = rhs.m_lla[i];
    }

    cout << "Car: Assignment" << endl;
    return *this;
}

//Throttle and Drive methods
void Car::setThrottle(int x)
{
    m_throttle = x;
}

int Car::getThrottle()
{
    return m_throttle;
}

void Car::drive(int x)
{
    setThrottle(x);
}

//MOVE
void Car::Move(float *ptr)
{

    drive(75);

    for(int i = 0;i < 3;i++, ptr++)
    {
        *ptr = m_lla[i];
    }

    cout << "Car: DRIVE to destination, with throttle @ " << m_throttle << endl;
}

//Serialize
void Car::serialize(ostream& outFile)const
{
    outFile << "Car: Throttle: " << m_throttle << " @ [" << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]" << endl;
}
