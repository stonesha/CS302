#include "Car.h"

Car::Car()
{
    //ctor
    cout << "Car #" << m_vin << ": Default-ctor" << endl;
}

Car::Car(char plates[256], int x, float lla[3]) : Vehicle(x, lla)
{

    strcpy(m_plates, plates);

    setVin(x);

    setLla(lla);

    cout << "Car #" << m_vin << ": Parameterized-ctor" << endl;
}

Car::Car(const Car &obj): Vehicle(obj)
{
    strcpy(m_plates, obj.m_plates);

    m_throttle = obj.m_throttle;

    for(int i = 0; i < 3; i++)
    {
        m_lla[i] = obj.getLla(i);
    }

}

Car::~Car()
{
    //dtor
    cout << "Car #" << m_vin << ": Dtor" << endl;
}

ostream& operator<<(ostream& outFile, Car &carObj)
{
    cout << "Car #" << carObj.getVin() << ": @ " << endl;
    printf("[%f, %f, %f]\n", carObj.getLla(0), carObj.getLla(1), carObj.getLla(2));

    return outFile;
}

istream& operator>>(istream& inFile, Car &carObj)
{
    cout << "Car #" << carObj.getVin() << " Plates: " << carObj.getPlates()
            << ", Throttle: " << carObj.getThrottle() << " @ ";
    printf("[%f, %f, %f]\n", carObj.getLla(0), carObj.getLla(1), carObj.getLla(2));

    return inFile;
}

Car& Car::operator=(Car& vl)
{
    for(int i = 0;i < 3; i++)
    {
        m_lla[i] = vl.m_lla[i];
    }

    m_throttle = vl.m_throttle;

    strcpy(m_plates, vl.m_plates);

    cout << "Car #" << getVin() << ": Assignment" << endl;

    return *this;
}

void Car::setLla(float *lla)
{
    for(int i = 0; i < 3; i++, lla++)
    {
        m_lla[i] = *lla;
    }
}

char* Car::getPlates()
{
    return m_plates;
}

int Car::getThrottle()
{
    return m_throttle;
}

void Car::setPlates(char *str)
{
    strcpy(m_plates, str);
}

void Car::setThrottle(int x)
{
    m_throttle = x;
}

void Car::drive(int x)
{
    setThrottle(x);
}

void Car::move(float *lla)
{
    setLla(lla);

    cout << "Car #" << m_vin << ": DRIVE to destination, with throttle @ " << m_throttle;
}


